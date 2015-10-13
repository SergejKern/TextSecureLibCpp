#pragma once
/*
Port of class Base64 from jobmanager-android
*/

// [x] done
// TFS ID: 779

/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "..\..\..\osindependent\OsIndependentString.h"
#include "..\..\..\javastuff\UnsupportedEncodingException.h"

#include <array>

/**
 * Utilities for encoding and decoding the Base64 representation of
 * binary data.  See RFCs <a
 * href="http://www.ietf.org/rfc/rfc2045.txt">2045</a> and <a
 * href="http://www.ietf.org/rfc/rfc3548.txt">3548</a>.
 */
class Base64
{
public:
  /**
   * Default values for encoder/decoder flags.
   */
  static const int DEFAULT = 0;
  /**
   * Encoder flag bit to omit the padding '=' characters at the end
   * of the output (if any).
   */
  static const int NO_PADDING = 1;
  /**
   * Encoder flag bit to omit all line terminators (i.e., the output
   * will be on one long line).
   */
  static const int NO_WRAP = 2;
  /**
   * Encoder flag bit to indicate lines should be terminated with a
   * CRLF pair instead of just an LF.  Has no effect if {@code
   * NO_WRAP} is specified as well.
   */
  static const int CRLF = 4;
  /**
   * Encoder/decoder flag bit to indicate using the "URL and
   * filename safe" variant of Base64 (see RFC 3548 section 4) where
   * {@code -} and {@code _} are used in place of {@code +} and
   * {@code /}.
   */
  static const int URL_SAFE = 8;
  /**
   * Flag to pass to {@link android.util.Base64OutputStream} to indicate that it
   * should not close the output stream it is wrapping when it
   * itself is closed.
   */
  static const int NO_CLOSE = 16;
  //  --------------------------------------------------------
  //  shared code
  //  --------------------------------------------------------
  /* package */ 
  static class Coder
  {
  public:
    std::vector<unsigned char>* output;
    int op;
    /**
     * Encode/decode another block of input data.  this->output is
     * provided by the caller, and must be big enough to hold all
     * the coded data.  On exit, this->opwill be set to the length
     * of the coded data.
     *
     * @param finish true if this is the const call to process for
     *        this object.  Will finalize the coder state and
     *        include any const bytes in the output.
     *
     * @return true if the input so far is good; false if some
     *         error has been detected in the input stream..
     */
    virtual bool Process(std::vector<unsigned char>* input, int offset, int len, bool finish) = 0;
    /**
     * @return the maximum number of bytes a call to process()
     * could produce for the given number of input bytes.  This may
     * be an overestimate.
     */
    virtual int MaxOutputSize(int len) = 0;
  };
  /* package */ 
  static class Decoder : public Coder
  {
    /**
    * Lookup table for turning bytes into their position in the
    * Base64 alphabet.
    */
  private:
    static const int DECODE[];
    /**
    * Decode lookup table for the "web safe" variant (RFC 3548
    * sec. 4) where - and _ replace + and /.
    */
    static const int DECODE_WEBSAFE[];
    /** Non-data values in the DECODE arrays. */
    static const int SKIP = -1;
    static const int EQUALS = -2;
    /**
    * States 0-3 are reading through the next input tuple.
    * State 4 is having read one '=' and expecting exactly
    * one more.
    * State 5 is expecting no more data or padding characters
    * in the input.
    * State 6 is the error state; an error has been detected
    * in the input and no future input can "fix" it.
    */
    int state;   // state number (0 to 6)
    int value;

    std::array<int, 256> alphabet;

  public:
    Decoder(int flags, std::vector<unsigned char>* output);
    /**
    * @return an overestimate for the number of bytes {@code
    * len} bytes could decode to.
    */
    int MaxOutputSize(int len);
    /**
    * Decode another block of input data.
    *
    * @return true if the state machine is still healthy.  false if
    *         bad base-64 data has been detected in the input stream.
    */
    bool Process(std::vector<unsigned char>* input, int offset, int len, bool finish);
  };
  /* package */
  static class Encoder : public Coder
  {
  public:
    /**
    * Emit a new line every this many output tuples.  Corresponds to
    * a 76-character line length (the maximum allowable according to
    * <a href="http://www.ietf.org/rfc/rfc2045.txt">RFC 2045</a>).
    */
    static const int LINE_GROUPS = 19;
  private:
    /**
    * Lookup table for turning Base64 alphabet positions (6 bits)
    * into output bytes.
    */
    static const char ENCODE[];
    /**
    * Lookup table for turning Base64 alphabet positions (6 bits)
    * into output bytes.
    */
    static const char ENCODE_WEBSAFE[];

    std::vector<unsigned char>* tail;
    /* package */ int tailLen;
    int count;
  public:
    bool do_padding;
    bool do_newline;
    bool do_cr;
  private:
    std::array<int, 64> alphabet;

  public:
    Encoder(int flags, std::vector<unsigned char>* output);
    /**
    * @return an overestimate for the number of bytes {@code
    * len} bytes could encode to.
    */
    int MaxOutputSize(int len);
    bool Process(std::vector<unsigned char>* input, int offset, int len, bool finish);
  };
  //  --------------------------------------------------------
  //  decoding
  //  --------------------------------------------------------

  /**
   * Decode the Base64-encoded data in input and return the data in
   * a new byte array.
   *
   * <p>The padding '=' characters at the end are considered optional, but
   * if any are present, there must be the correct number of them.
   *
   * @param str    the input String to decode, which is converted to
   *               bytes using the default charset
   * @param flags  controls certain features of the decoded output.
   *               Pass {@code DEFAULT} to decode standard Base64.
   *
   * @throws IllegalArgumentException if the input contains
   * incorrect padding
   */
  std::vector<unsigned char>* Decode(OsIndependentString* str, int flags);
  /**
   * Decode the Base64-encoded data in input and return the data in
   * a new byte array.
   *
   * <p>The padding '=' characters at the end are considered optional, but
   * if any are present, there must be the correct number of them.
   *
   * @param input the input array to decode
   * @param flags  controls certain features of the decoded output.
   *               Pass {@code DEFAULT} to decode standard Base64.
   *
   * @throws IllegalArgumentException if the input contains
   * incorrect padding
   */
  static std::vector<unsigned char>* Decode(std::vector<unsigned char>* input, int flags);
  /**
   * Decode the Base64-encoded data in input and return the data in
   * a new byte array.
   *
   * <p>The padding '=' characters at the end are considered optional, but
   * if any are present, there must be the correct number of them.
   *
   * @param input  the data to decode
   * @param offset the position within the input array at which to start
   * @param len    the number of bytes of input to decode
   * @param flags  controls certain features of the decoded output.
   *               Pass {@code DEFAULT} to decode standard Base64.
   *
   * @throws IllegalArgumentException if the input contains
   * incorrect padding
   */
  static std::vector<unsigned char>* Decode(std::vector<unsigned char>* input, int offset, int len, int flags);

  //  --------------------------------------------------------
  //  encoding
  //  --------------------------------------------------------
  /**
   * Base64-encode the given data and return a newly allocated
   * String with the result.
   *
   * @param input  the data to encode
   * @param flags  controls certain features of the encoded output.
   *               Passing {@code DEFAULT} results in output that
   *               adheres to RFC 2045.
   */
  static OsIndependentString* EncodeToString(std::vector<unsigned char>* input, int flags);
  /**
   * Base64-encode the given data and return a newly allocated
   * String with the result.
   *
   * @param input  the data to encode
   * @param offset the position within the input array at which to
   *               start
   * @param len    the number of bytes of input to encode
   * @param flags  controls certain features of the encoded output.
   *               Passing {@code DEFAULT} results in output that
   *               adheres to RFC 2045.
   */
  static OsIndependentString* EncodeToString(std::vector<unsigned char>* input, int offset, int len, int flags);
  /**
   * Base64-encode the given data and return a newly allocated
   * byte[] with the result.
   *
   * @param input  the data to encode
   * @param flags  controls certain features of the encoded output.
   *               Passing {@code DEFAULT} results in output that
   *               adheres to RFC 2045.
   */
  static std::vector<unsigned char>* Encode(std::vector<unsigned char>* input, int flags);
  /**
   * Base64-encode the given data and return a newly allocated
   * byte[] with the result.
   *
   * @param input  the data to encode
   * @param offset the position within the input array at which to
   *               start
   * @param len    the number of bytes of input to encode
   * @param flags  controls certain features of the encoded output.
   *               Passing {@code DEFAULT} results in output that
   *               adheres to RFC 2045.
   */
  static std::vector<unsigned char>* Encode(std::vector<unsigned char>* input, int offset, int len, int flags);
private:
  Base64() { }   // don't instantiate
};

const int Base64::Decoder::DECODE[] = {
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
  52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1,
  -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
  -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};
/**
* Decode lookup table for the "web safe" variant (RFC 3548
* sec. 4) where - and _ replace + and /.
*/
const int Base64::Decoder::DECODE_WEBSAFE[] = {
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1,
  52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1,
  -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, 63,
  -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};
const char Base64::Encoder::ENCODE[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/',
};
/**
* Lookup table for turning Base64 alphabet positions (6 bits)
* into output bytes.
*/
const char Base64::Encoder::ENCODE_WEBSAFE[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '_',
};
