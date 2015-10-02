#pragma once
/*
Port of class JobSerializer from jobmanager-android
*/

// [x] done
// TFS ID: 774

#include "..\..\..\osindependent\OsIndependentString.h"

#include "..\Job.h"
#include "..\EncryptionKeys.h"

#include "..\..\..\javastuff\IOException.h"

/**
 * A JobSerializer is responsible for serializing and deserializing persistent jobs.
 */
class JobSerializer
{
public:
  /**
   * Serialize a job object into a string.
   * @param job The Job to serialize.
   * @return The serialized Job.
   * @throws IOException if serialization fails.
   */
  virtual OsIndependentString* Serialize(Job* job) = 0 /*throws IOException*/;
  /**
   * Deserialize a String into a Job.
   * @param keys Optional encryption keys that could have been used.
   * @param encrypted True if the job was encrypted using the encryption keys.
   * @param serialized The serialized Job.
   * @return The deserialized Job.
   * @throws IOException If the Job deserialization fails.
   */
  virtual Job* Deserialize(EncryptionKeys* keys, bool encrypted, OsIndependentString* serialized) = 0 /*throws IOException*/;
};
