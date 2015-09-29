#pragma once
/*
Port of class EncryptingJobSerializer from TextSecure-android
*/

// [ ] done
// TFS ID: 550

#include "..\..\..\osindependent\OsIndependentString.h"

#include "..\..\crypto\MasterCipher.h"
#include "..\..\crypto\MasterSecret.h"
#include "..\..\util\ParcelUtil.h"
//import org.whispersystems.jobqueue.EncryptionKeys;
//import org.whispersystems.jobqueue.Job;
//import org.whispersystems.jobqueue.persistence.JavaJobSerializer;
//import org.whispersystems.jobqueue.persistence.JobSerializer;
//import org.whispersystems.libaxolotl.InvalidMessageException;
//
//import java.io.IOException;

class EncryptingJobSerializer : JobSerializer
{
private:
  /* TODO JavaJobSerializer delegate;*/

public:
  EncryptingJobSerializer()
  {
    this.delegate = new JavaJobSerializer();
  }

  //@Override
  OsIndependentString* Serialize(Job* job) /*throws IOException*/
  {
    OsIndependentString* plaintext = delegate.serialize(job);
    if (job->GetEncryptionKeys() != null)
    {
      MasterSecret* masterSecret = ParcelUtil::Deserialize(job->GetEncryptionKeys()->GetEncoded(),
                                                         MasterSecret::CREATOR);
      MasterCipher* masterCipher = new MasterCipher(masterSecret);

      return masterCipher->EncryptBody(plaintext);
    } else {
      return plaintext;
    }
  }

  //@Override
  Job* Deserialize(EncryptionKeys* keys, bool encrypted, OsIndependentString* serialized) /*throws IOException*/
  {
    try
    {
      OsIndependentString* plaintext;
      if (encrypted)
      {
        MasterSecret* masterSecret = ParcelUtil::Deserialize(keys->GetEncoded(), MasterSecret::CREATOR);
        MasterCipher* masterCipher = new MasterCipher(masterSecret);
        plaintext = masterCipher->DecryptBody(serialized);
      }
      else
      {
        plaintext = serialized;
      }
      return delegate.deserialize(keys, encrypted, plaintext);
    }
    catch (InvalidMessageException e)
    {
      throw new IOException(e);
    }
  }
};
