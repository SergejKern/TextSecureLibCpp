#pragma once
/*
Port of class JavaJobSerializer from jobmanager-android
*/

// [x] done
// TFS ID: 773

#include "..\EncryptionKeys.h"
#include "..\Job.h"
#include "..\util\Base64.h"
//
#include "..\..\..\Factory\Factory.h"
#include "..\..\..\javastuff\IOException.h"
//import java.io.ObjectInputStream;
//import java.io.ObjectOutputStream;
//import java.io.PrintWriter;
//import java.io.StringWriter;

#include "JobSerializer.h"

/**
 * An implementation of {@link org.whispersystems.jobqueue.persistence.JobSerializer} that uses
 * Java Serialization.
 *
 * NOTE: This {@link JobSerializer} does not support encryption. Jobs will be serialized normally,
 * but any corresponding {@link Job} encryption keys will be ignored.
 */
class JavaJobSerializer : public JobSerializer
{
public:
  JavaJobSerializer() {}
  //@Override
  virtual OsIndependentString* Serialize(Job* job) override /*throws IOException*/
  {
    OsIndependentByteArrayOutputStream* baos = FactoryByteArrayOutputStream::GetInstance()->CreateNewByteArrayOutputStream();
    auto oos = FactoryObjectOutputStream::GetInstance()->CreateNewObjectOutputStream(baos);
    oos->WriteObject(job);

    return Base64::EncodeToString(baos->ToByteArray(), Base64::NO_WRAP);
  }
  //@Override
  virtual Job* Deserialize(EncryptionKeys* keys, bool encrypted, OsIndependentString* serialized) override /*throws IOException*/
  {
    try
    {
      OsIndependentByteArrayInputStream* bais = FactoryByteArrayInputStream::GetInstance()->CreateNewByteArrayInputStream(Base64::Decode(serialized->GetBytes(), Base64::NO_WRAP));
      auto ois = FactoryObjectInputStream::GetInstance()->CreateNewObjectInputStream(bais);
      return (Job*)ois->ReadObject();
    }
    catch (...)
    {
    }
      /*(ClassNotFoundException* e)
    {
      StringWriter sw = new StringWriter();
      PrintWriter  pw = new PrintWriter(sw);
      e->printStackTrace(pw);

      throw new IOException(e->GetMessage() + "\n" + sw.toString());
    }*/
  }
};
