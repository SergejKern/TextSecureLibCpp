#include "Base64.h"

Base64::Decoder::Decoder(int flags, ArrayList<char>* output)
{
  this->output = output;

  this->alphabet = ((flags & URL_SAFE) == 0) ? DECODE : DECODE_WEBSAFE;
  state = 0;
  value = 0;
}
int Base64::Decoder::MaxOutputSize(int len) { return len * 3 / 4 + 10; }
bool Base64::Decoder::Process(ArrayList<char>* input, int offset, int len, bool finish)
{
  if (this->state == 6)
    return false;

  int p = offset;
  len += offset;

  // Using local variables makes the decoder about 12%
  // faster than if we manipulate the member variables in
  // the loop.  (Even alphabet makes a measurable
  // difference, which is somewhat surprising to me since
  // the member variable is const.)
  int state = this->state;
  int value = this->value;
  int op = 0;
  ArrayList<char>* output = this->output;
  int alphabet[] = this->alphabet;

  while (p < len)
  {
    // Try the fast path:  we're starting a new tuple and the
    // next four bytes of the input stream are all data
    // bytes.  This corresponds to going through states
    // 0-1-2-3-0.  We expect to use this method for most of
    // the data.
    //
    // If any of the next four bytes of input are non-data
    // (whitespace, etc.), value will end up negative.  (All
    // the non-data values in decode are small negative
    // numbers, so shifting any of them up and or'ing them
    // together will result in a value with its top bit set.)
    //
    // You can remove this whole block and the output should
    // be the same, just slower.
    if (state == 0)
    {
      while (p + 4 <= len &&
        (value = ((alphabet[input->GetAt(p) & 0xff] << 18) |
        (alphabet[input->GetAt(p + 1) & 0xff] << 12) |
        (alphabet[input->GetAt(p + 2) & 0xff] << 6) |
        (alphabet[input->GetAt(p + 3) & 0xff]))) >= 0)
      {
        output->SetAt(op + 2, (char)value);
        output->SetAt(op + 1, (char)(value >> 8));
        output->SetAt(op, (char)(value >> 16));
        op += 3;
        p += 4;
      }
      if (p >= len)
        break;
    }

    // The fast path isn't available -- either we've read a
    // partial tuple, or the next four input bytes aren't all
    // data, or whatever.  Fall back to the slower state
    // machine implementation.

    int d = alphabet[input->GetAt(p++) & 0xff];

    switch (state)
    {
    case 0:
      if (d >= 0)
      {
        value = d;
        ++state;
      }
      else if (d != SKIP)
      {
        this->state = 6;
        return false;
      }
      break;
    case 1:
      if (d >= 0)
      {
        value = (value << 6) | d;
        ++state;
      }
      else if (d != SKIP)
      {
        this->state = 6;
        return false;
      }
      break;
    case 2:
      if (d >= 0)
      {
        value = (value << 6) | d;
        ++state;
      }
      else if (d == EQUALS)
      {
        // Emit the last (partial) output tuple;
        // expect exactly one more padding character.
        output->SetAt(op++, (char)(value >> 4));
        state = 4;
      }
      else if (d != SKIP)
      {
        this->state = 6;
        return false;
      }
      break;
    case 3:
      if (d >= 0)
      {
        // Emit the output triple and return to state 0.
        value = (value << 6) | d;
        output->SetAt(op + 2, (char)value);
        output->SetAt(op + 1, (char)(value >> 8));
        output->SetAt(op, (char)(value >> 16));
        op += 3;
        state = 0;
      }
      else if (d == EQUALS)
      {
        // Emit the last (partial) output tuple;
        // expect no further data or padding characters.
        output->SetAt(op + 1, (char)(value >> 2));
        output->SetAt(op, (char)(value >> 10));
        op += 2;
        state = 5;
      }
      else if (d != SKIP)
      {
        this->state = 6;
        return false;
      }
      break;
    case 4:
      if (d == EQUALS)
      {
        ++state;
      }
      else if (d != SKIP)
      {
        this->state = 6;
        return false;
      }
      break;
    case 5:
      if (d != SKIP)
      {
        this->state = 6;
        return false;
      }
      break;
    }
  }
  if (!finish)
  {
    // We're out of input, but a future call could provide
    // more.
    this->state = state;
    this->value = value;
    this->op = op;
    return true;
  }
  // Done reading input.  Now figure out where we are left in
  // the state machine and finish up.
  switch (state)
  {
  case 0:
    // Output length is a multiple of three.  Fine.
    break;
  case 1:
    // Read one extra input byte, which isn't enough to
    // make another output byte.  Illegal.
    this->state = 6;
    return false;
  case 2:
    // Read two extra input bytes, enough to emit 1 more
    // output byte.  Fine.
    output->SetAt(op++, (char)(value >> 4));
    break;
  case 3:
    // Read three extra input bytes, enough to emit 2 more
    // output bytes.  Fine.
    output->SetAt(op++, (char)(value >> 10));
    output->SetAt(op++, (char)(value >> 2));
    break;
  case 4:
    // Read one padding '=' when we expected 2.  Illegal.
    this->state = 6;
    return false;
  case 5:
    // Read all the padding '='s we expected and no more.
    // Fine.
    break;
  }
  this->state = state;
  this->op = op;
  return true;
}
ArrayList<char>* Base64::Decode(OsIndependentString* str, int flags)
{
  return Decode(str->GetBytes(), flags);
}
ArrayList<char>* Base64::Decode(ArrayList<char>* input, int flags)
{
  return Decode(input, 0, input->Size(), flags);
}
ArrayList<char>* Base64::Decode(ArrayList<char>* input, int offset, int len, int flags)
{
  // Allocate space for the most data the input could represent.
  // (It could contain less if it contains whitespace, etc.)
  Decoder* decoder = new Decoder(flags, new char[len * 3 / 4]);
  if (!decoder->Process(input, offset, len, true))
  {
    throw new IllegalArgumentException("bad base-64");
  }
  // Maybe we got lucky and allocated exactly enough output space.
  if (decoder->op == decoder->output->Size())
  {
    return decoder->output;
  }
  // Need to shorten the array, so allocate a new one of the
  // right size and copy.
  ArrayList<char>* temp = new byte[decoder.op];
  System::Arraycopy(decoder->output, 0, temp, 0, decoder->op);
  return temp;
}
OsIndependentString* Base64::EncodeToString(ArrayList<char>* input, int flags)
{
  try {
    return new OsIndependentString(encode(input, flags), "US-ASCII");
  }
  catch (UnsupportedEncodingException e) {
    // US-ASCII is guaranteed to be available.
    throw new AssertionError(e);
  }
}
OsIndependentString* Base64::EncodeToString(ArrayList<char>* input, int offset, int len, int flags) {
  try {
    return new OsIndependentString(encode(input, offset, len, flags), "US-ASCII");
  }
  catch (UnsupportedEncodingException e) {
    // US-ASCII is guaranteed to be available.
    throw new AssertionError(e);
  }
}
ArrayList<char>* Base64::Encode(ArrayList<char>* input, int flags)
{
  return encode(input, 0, input.length, flags);
}
ArrayList<char>* Base64::Encode(ArrayList<char>* input, int offset, int len, int flags)
{
  Encoder encoder = new Encoder(flags, null);

  // Compute the exact length of the array we will produce.
  int output_len = len / 3 * 4;

  // Account for the tail of the data and the padding bytes, if any.
  if (encoder.do_padding) {
    if (len % 3 > 0) {
      output_len += 4;
    }
  }
  else {
    switch (len % 3) {
    case 0: break;
    case 1: output_len += 2; break;
    case 2: output_len += 3; break;
    }
  }

  // Account for the newlines, if any.
  if (encoder.do_newline && len > 0) {
    output_len += (((len - 1) / (3 * Encoder.LINE_GROUPS)) + 1) *
      (encoder.do_cr ? 2 : 1);
  }

  encoder.output = new byte[output_len];
  encoder.process(input, offset, len, true);

  assert encoder.op == output_len;

  return encoder.output;
}
Base64::Encoder::Encoder(int flags, ArrayList<char>* output)
{
  this->output = output;

  do_padding = (flags & NO_PADDING) == 0;
  do_newline = (flags & NO_WRAP) == 0;
  do_cr = (flags & CRLF) != 0;
  alphabet = ((flags & URL_SAFE) == 0) ? ENCODE : ENCODE_WEBSAFE;

  tail = new byte[2];
  tailLen = 0;

  count = do_newline ? LINE_GROUPS : -1;
}
int Base64::Encoder::MaxOutputSize(int len)
{
  return len * 8 / 5 + 10;
}
bool Base64::Encoder::Process(ArrayList<char>* input, int offset, int len, bool finish)
{
  // Using local variables makes the encoder about 9% faster.
  const ArrayList<char>* alphabet = this->alphabet;
  const ArrayList<char>* output = this->output;
  int op = 0;
  int count = this->count;

  int p = offset;
  len += offset;
  int v = -1;

  // First we need to concatenate the tail of the previous call
  // with any input bytes available now and see if we can empty
  // the tail.

  switch (tailLen) {
  case 0:
    // There was no tail.
    break;

  case 1:
    if (p + 2 <= len) {
      // A 1-byte tail with at least 2 bytes of
      // input available now.
      v = ((tail[0] & 0xff) << 16) |
        ((input[p++] & 0xff) << 8) |
        (input[p++] & 0xff);
      tailLen = 0;
    };
    break;

  case 2:
    if (p + 1 <= len) {
      // A 2-byte tail with at least 1 byte of input.
      v = ((tail[0] & 0xff) << 16) |
        ((tail[1] & 0xff) << 8) |
        (input[p++] & 0xff);
      tailLen = 0;
    }
    break;
  }

  if (v != -1) {
    output[op++] = alphabet[(v >> 18) & 0x3f];
    output[op++] = alphabet[(v >> 12) & 0x3f];
    output[op++] = alphabet[(v >> 6) & 0x3f];
    output[op++] = alphabet[v & 0x3f];
    if (--count == 0) {
      if (do_cr) output[op++] = '\r';
      output[op++] = '\n';
      count = LINE_GROUPS;
    }
  }

  // At this point either there is no tail, or there are fewer
  // than 3 bytes of input available.

  // The main loop, turning 3 input bytes into 4 output bytes on
  // each iteration.
  while (p + 3 <= len) {
    v = ((input[p] & 0xff) << 16) |
      ((input[p + 1] & 0xff) << 8) |
      (input[p + 2] & 0xff);
    output[op] = alphabet[(v >> 18) & 0x3f];
    output[op + 1] = alphabet[(v >> 12) & 0x3f];
    output[op + 2] = alphabet[(v >> 6) & 0x3f];
    output[op + 3] = alphabet[v & 0x3f];
    p += 3;
    op += 4;
    if (--count == 0) {
      if (do_cr) output[op++] = '\r';
      output[op++] = '\n';
      count = LINE_GROUPS;
    }
  }

  if (finish) {
    // Finish up the tail of the input.  Note that we need to
    // consume any bytes in tail before any bytes
    // remaining in input; there should be at most two bytes
    // total.

    if (p - tailLen == len - 1) {
      int t = 0;
      v = ((tailLen > 0 ? tail[t++] : input[p++]) & 0xff) << 4;
      tailLen -= t;
      output[op++] = alphabet[(v >> 6) & 0x3f];
      output[op++] = alphabet[v & 0x3f];
      if (do_padding) {
        output[op++] = '=';
        output[op++] = '=';
      }
      if (do_newline) {
        if (do_cr) output[op++] = '\r';
        output[op++] = '\n';
      }
    }
    else if (p - tailLen == len - 2) {
      int t = 0;
      v = (((tailLen > 1 ? tail[t++] : input[p++]) & 0xff) << 10) |
        (((tailLen > 0 ? tail[t++] : input[p++]) & 0xff) << 2);
      tailLen -= t;
      output[op++] = alphabet[(v >> 12) & 0x3f];
      output[op++] = alphabet[(v >> 6) & 0x3f];
      output[op++] = alphabet[v & 0x3f];
      if (do_padding) {
        output[op++] = '=';
      }
      if (do_newline) {
        if (do_cr) output[op++] = '\r';
        output[op++] = '\n';
      }
    }
    else if (do_newline && op > 0 && count != LINE_GROUPS) {
      if (do_cr) output[op++] = '\r';
      output[op++] = '\n';
    }

    assert tailLen == 0;
    assert p == len;
  }
  else {
    // Save the leftovers in tail to be consumed on the next
    // call to encodeInternal.

    if (p == len - 1) {
      tail[tailLen++] = input[p];
    }
    else if (p == len - 2) {
      tail[tailLen++] = input[p];
      tail[tailLen++] = input[p + 1];
    }
  }

  this->op = op;
  this->count = count;

  return true;
}

Base64::Base64() { }
