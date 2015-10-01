#pragma once
/*
Port of class EncryptionKeys from jobmanager-android
*/

// [x] done
// TFS ID: 766

class EncryptionKeys
{
private:
  /*transient*/ /*final*/ /*byte[]*/ char* encoded;

public:
  EncryptionKeys(/*byte[]*/char* encoded)
  {
    this->encoded = encoded;
  }
  /*byte[]*/char* GetEncoded() { return this->encoded; }
};
