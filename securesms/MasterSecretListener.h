#pragma once

/*
Port of MasterSecretListener.java from TextSecure-android
*/

// [x] done
// TFS ID: 723

//public interface MasterSecretListener
class MasterSecretListener
{
  virtual void OnMasterSecretCleared() = 0;
};
