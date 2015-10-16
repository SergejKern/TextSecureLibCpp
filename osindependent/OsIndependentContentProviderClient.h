#pragma once
/*
  abstract class OsIndependentContentProviderClient to replace android.content.ContentProviderClient
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/ContentProviderClient.java#ContentProviderClient
*/

// [ ] done
// TFS ID: 685

// public class ContentProviderClient {
class OsIndependentContentProviderClient
{
private:
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------------------+  creates   +-----------------------------------+
| OsIndependentContentProviderClient |<-----------|    FactoryContentProviderClient   |
+------------------------------------+            +-----------------------------------+
                 ^                                                 ^                Plattform independent code
                /|\                                               /|\
                 |                                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                 |                                                 |
                 |                                                 |                Plattform specific code
                 |                                                 |
+------------------------------------+  creates   +-----------------------------------+
|     Tizen-ContentProviderClient    |<-----------| TizenFactoryContentProviderClient |
+------------------------------------+            +-----------------------------------+
*/
class FactoryContentProviderClient
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryContentProviderClient* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryContentProviderClient* plattformSpecific) { FactoryContentProviderClient::instance = plattformSpecific; }
  static FactoryContentProviderClient* GetInstance()
  {
    if (FactoryContentProviderClient::instance == nullptr)
      throw;
    return FactoryContentProviderClient::instance;
  }
  // interface
  virtual OsIndependentContentProviderClient* CreateNewContentProviderClient() = 0;
};
