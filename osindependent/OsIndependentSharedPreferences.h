#pragma once
/*
  abstract class OsIndependentSQLiteCursorDriver to replace  android.content.SharedPreferences
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/SharedPreferences.java#SharedPreferences
*/

// [x] done
// TFS ID: 804

#include <list>
#include <set>
#include <map>
#include "OsIndependentString.h"
#include "OsIndependentCursor.h"

// public interface   SharedPreferences {
class OsIndependentSharedPreferences
{
public:
  //public interface Editor{
  class Editor
  {
  public:
    void Apply();
    Editor* Clear();
    bool Commit();
    Editor* PutBoolean(OsIndependentString* key, bool value);
    Editor* PutFloat(OsIndependentString* key, float value);
    Editor* PutInt(OsIndependentString* key, int value);
    Editor* PutLong(OsIndependentString* key, long value);
    Editor* PutString(OsIndependentString* key, OsIndependentString* value);
    Editor* PutStringSet(OsIndependentString* key, std::set<OsIndependentString*> values);
    Editor* Remove(OsIndependentString* key);
  };
  //public interface OnSharedPreferenceChangeListener{
  class OnSharedPreferenceChangeListener
  {
  public:
    virtual void OnSharedPreferenceChanged(OsIndependentSharedPreferences* sharedPreferences, OsIndependentString* key);
  };
public:
  bool Contains(OsIndependentString* key);
  Editor* Edit();
  std::map<OsIndependentString*, void*> GetAll();
  bool GetBoolean(OsIndependentString* key, bool defValue);
  float GetFloat(OsIndependentString* key, float defValue);
  int GetInt(OsIndependentString* key, int defValue);
  long GetLong(OsIndependentString* key, long defValue);
  OsIndependentString* GetString(OsIndependentString* key, OsIndependentString* defValue);
  std::set<OsIndependentString*> GetStringSet(OsIndependentString* key, Set<OsIndependentString*>* defValues);
  void RegisterOnSharedPreferenceChangeListener(OnSharedPreferenceChangeListener* listener);
  void UnregisterOnSharedPreferenceChangeListener(OnSharedPreferenceChangeListener* listener);
};
/*
needs no Factory, because is an interface
*/
