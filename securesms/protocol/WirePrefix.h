#pragma once
/*
Port of class WirePrefix from TextSecure-android
*/

// [ ] done
// TFS ID: 629

#include "..\..\osindependent\OsIndependentString.h"
#include "..\util\Base64.h"
//import java.security.MessageDigest;
//import java.security.NoSuchAlgorithmException;
//import java.security.SecureRandom;

/**
 * Calculates prefixes that identify a message as
 * being part of an encrypted session.  The idea was to
 * make calculating and identifying these prefixes somewhat
 * expensive, so that filtering them en-mass would come at a cost.
 *
 * @author Moxie Marlinspike
 */

/* abstract */
class WirePrefix
{
private:
  static const int HASH_ITERATIONS = 1000;
  static const int PREFIX_BYTES = 3;
public:
  static const int PREFIX_SIZE = 4;
  virtual OsIndependentString* CalculatePrefix(OsIndependentString* message) = 0;
  static bool IsKeyExchange(OsIndependentString* message);
  static bool IsEncryptedMessage(OsIndependentString* message);
  static bool IsPreKeyBundle(OsIndependentString* message);
  static bool IsEndSession(OsIndependentString* message);
  static OsIndependentString* CalculateKeyExchangePrefix(OsIndependentString* message);
  static OsIndependentString* CalculateEncryptedMesagePrefix(OsIndependentString* message);
  static OsIndependentString* CalculatePreKeyBundlePrefix(OsIndependentString* message);
  static OsIndependentString* CalculateEndSessionPrefix(OsIndependentString* message);
private:
  static bool VerifyPrefix(OsIndependentString* prefixType, OsIndependentString* message);
  static OsIndependentString* CalculatePrefix(/*byte[]*/char* message, int byteCount);
public:
  static OsIndependentString* CalculateEncryptedMmsSubject();
  static bool IsEncryptedMmsSubject(OsIndependentString* subject);
};
