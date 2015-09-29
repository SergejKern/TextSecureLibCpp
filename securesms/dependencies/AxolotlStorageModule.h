#pragma once
/*
Port of class AxolotlStorageModule from TextSecure-android
*/

// [ ] done
// TFS ID: 491

#include "..\..\osindependent\OsIndependentContext.h"
//
//import org.thoughtcrime.securesms.crypto.MasterSecret;
//import org.thoughtcrime.securesms.crypto.storage.TextSecureAxolotlStore;
//import org.thoughtcrime.securesms.jobs.CleanPreKeysJob;
//import org.whispersystems.libaxolotl.state.SignedPreKeyStore;
//
//import dagger.Module;
//import dagger.Provides;

//@Module (complete = false, injects = {CleanPreKeysJob.class})
class AxolotlStorageModule
{
private:
  OsIndependentContext* context;
public:
  AxolotlStorageModule(OsIndependentContext* context)
  {
    this->context = context;
  }
public:
  //public static interface SignedPreKeyStoreFactory
  class SignedPreKeyStoreFactory
  {
  public:
    SignedPreKeyStore* Create();
  };
  //@Provides 
  SignedPreKeyStoreFactory* ProvideSignedPreKeyStoreFactory()
  {
    // TODO deanonymize anonym function \0_o/
    //return new SignedPreKeyStoreFactory()
    //{
    //public:
    //  //@Override
    //  SignedPreKeyStore* create() {
    //    return new TextSecureAxolotlStore(context);
    //  }
    //}
  }
};
