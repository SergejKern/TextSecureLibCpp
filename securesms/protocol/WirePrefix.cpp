#include "WirePrefix.h"

bool WirePrefix::IsKeyExchange(OsIndependentString* message)
{
  return VerifyPrefix("?TSK", message);
}
bool WirePrefix::IsEncryptedMessage(OsIndependentString* message)
{
  return VerifyPrefix("?TSM", message);
}
bool WirePrefix::IsPreKeyBundle(OsIndependentString* message)
{
  return VerifyPrefix("?TSP", message);
}
bool WirePrefix::IsEndSession(OsIndependentString* message)
{
  return VerifyPrefix("?TSE", message);
}
OsIndependentString* WirePrefix::CalculateKeyExchangePrefix(OsIndependentString* message)
{
  return CalculatePrefix(("?TSK" + message).getBytes(), PREFIX_BYTES);
}
OsIndependentString* WirePrefix::CalculateEncryptedMesagePrefix(OsIndependentString* message)
{
  return CalculatePrefix(("?TSM" + message).getBytes(), PREFIX_BYTES);
}
OsIndependentString* WirePrefix::CalculatePreKeyBundlePrefix(OsIndependentString* message)
{
  return CalculatePrefix(("?TSP" + message).getBytes(), PREFIX_BYTES);
}
OsIndependentString* WirePrefix::CalculateEndSessionPrefix(OsIndependentString* message)
{
  return CalculatePrefix(("?TSE" + message).getBytes(), PREFIX_BYTES);
}
bool WirePrefix::VerifyPrefix(OsIndependentString* prefixType, OsIndependentString* message)
{
  if (message->Length() <= PREFIX_SIZE)
    return false;

  OsIndependentString* prefix = message.substring(0, PREFIX_SIZE);
  message = message.substring(PREFIX_SIZE);

  OsIndependentString* calculatedPrefix = calculatePrefix((prefixType + message).getBytes(), PREFIX_BYTES);

  assert(calculatedPrefix.length() == PREFIX_SIZE);

  return prefix->Equals(calculatedPrefix);
}
OsIndependentString* WirePrefix::CalculatePrefix(/*byte[]*/char* message, int byteCount)
{
  try {
    MessageDigest md = MessageDigest.getInstance("SHA1");
    byte[] runningDigest = message;

    for (int i = 0; i<HASH_ITERATIONS; i++) {
      runningDigest = md.digest(runningDigest);
    }

    return Base64.encodeBytes(runningDigest, 0, byteCount);
  }
  catch (NoSuchAlgorithmException e) {
    throw new AssertionError(e);
  }
}
OsIndependentString* WirePrefix::CalculateEncryptedMmsSubject()
{
  try {
    byte[] postfix = new byte[6];
    SecureRandom.getInstance("SHA1PRNG").nextBytes(postfix);

    OsIndependentString* postfixString = Base64.encodeBytes(postfix);
    OsIndependentString* prefix = calculatePrefix(postfixString.getBytes(), 6);

    return prefix + postfixString;
  }
  catch (NoSuchAlgorithmException e) {
    throw new AssertionError(e);
  }
}
bool WirePrefix::IsEncryptedMmsSubject(OsIndependentString* subject)
{
  if (subject.length() < 9)
    return false;

  OsIndependentString* prefix = subject.substring(0, 8);
  OsIndependentString* postfix = subject.substring(8);

  OsIndependentString* calculatedPrefix = calculatePrefix(postfix.getBytes(), 6);
  return calculatedPrefix.equals(prefix);
}
