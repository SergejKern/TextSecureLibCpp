#pragma once
/*
abstract class OsIndependentAttributeSet to replace android.util.AttributeSet
http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/util/AttributeSet.java#AttributeSet
*/

// [x] done
// TFS ID: 667

#include <list>
#include "OsIndependentString.h"

/* public interface AttributeSet { */
class OsIndependentAttributeSet
{
private:
public:
  /**/
  /*
  Returns the number of attributes available in the set.
  Returns:
  A positive integer, or 0 if the set is empty.
  */
  int GetAttributeCount();
  /*
  Returns the name of the specified attribute.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  Returns :
  A String containing the name of the attribute, or null if the attribute cannot be found.
  */
  OsIndependentString* GetAttributeName(int index);
  /*
  Returns the value of the specified attribute as a string representation.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  Returns :
  A String containing the value of the attribute, or null if the attribute cannot be found.
  */
  OsIndependentString* GetAttributeValue(int index);
  /*
  Returns the value of the specified attribute as a string representation.The lookup is performed using the attribute name.
  Parameters:
  namespace The namespace of the attribute to get the value from.
  name The name of the attribute to get the value from.
  Returns :
  A String containing the value of the attribute, or null if the attribute cannot be found.
  */
  OsIndependentString* GetAttributeValue(OsIndependentString* _namespace, OsIndependentString* name);
  /*
  Returns a description of the current position of the attribute set.For instance, if the attribute set is loaded from an XML document, the position description could indicate the current line number.
  Returns:
  A string representation of the current position in the set, may be null.
  */
  OsIndependentString* GetPositionDescription();
  /*
  Return the resource ID associated with the given attribute name.This will be the identifier for an attribute resource, which can be used by styles.Returns 0 if there is no resource associated with this attribute.
  Note that this is different than getAttributeResourceValue(int, int) in that it returns a resource identifier for the attribute name; the other method returns this attribute's value as a resource identifier.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  Returns :
  The resource identifier, 0 if none.
  */
  int GetAttributeNameResource(int index);
  /*
  Return the index of the value of 'attribute' in the list 'options'.
  Parameters:
  namespace Namespace of attribute to retrieve.
  attribute Name of attribute to retrieve.
  options List of strings whose values we are checking against.
  defaultValue Value returned if attribute doesn't exist or no match is found.
  Returns :
  Index in to 'options' or defaultValue.
  */
  int GetAttributeListValue(OsIndependentString* _namespace, OsIndependentString* attribute, std::list<OsIndependentString*>* options, int defaultValue);
  /*
  Return the boolean value of 'attribute'.
  Parameters:
  namespace Namespace of attribute to retrieve.
  attribute The attribute to retrieve.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  bool GetAttributeBooleanValue(OsIndependentString* _namespace, OsIndependentString* attribute, bool defaultValue);
  /*
  Return the value of 'attribute' as a resource identifier.
  Note that this is different than getAttributeNameResource(int) in that it returns the value contained in this attribute as a resource identifier(i.e., a value originally of the form "@package:type/resource"); the other method returns a resource identifier that identifies the name of the attribute.
  Parameters:
  namespace Namespace of attribute to retrieve.
  attribute The attribute to retrieve.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  int GetAttributeResourceValue(OsIndependentString* _namespace, OsIndependentString* attribute, int defaultValue);
  /*
  Return the integer value of 'attribute'.
  Parameters:
  namespace Namespace of attribute to retrieve.
  attribute The attribute to retrieve.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  int GetAttributeIntValue(OsIndependentString* _namespace, OsIndependentString* attribute, int defaultValue);
  /*
  Return the boolean value of 'attribute' that is formatted as an unsigned value.In particular, the formats 0xn...n and #n...n are handled.
  Parameters:
  namespace Namespace of attribute to retrieve.
  attribute The attribute to retrieve.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  int GetAttributeUnsignedIntValue(OsIndependentString* _namespace, OsIndependentString* attribute, int defaultValue);
  /*
  Return the float value of 'attribute'.
  Parameters:
  namespace Namespace of attribute to retrieve.
  attribute The attribute to retrieve.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  float GetAttributeFloatValue(OsIndependentString* _namespace, OsIndependentString* attribute, float defaultValue);
  /*
  Return the index of the value of attribute at 'index' in the list 'options'.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  options List of strings whose values we are checking against.
  defaultValue Value returned if attribute doesn't exist or no match is found.
  Returns :
  Index in to 'options' or defaultValue.
  */
  int GetAttributeListValue(int index, std::list<OsIndependentString*>* options, int defaultValue);
  /*
  Return the boolean value of attribute at 'index'.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  bool GetAttributeBooleanValue(int index, bool defaultValue);
  /*
  Return the value of attribute at 'index' as a resource identifier.
  Note that this is different than getAttributeNameResource(int) in that it returns the value contained in this attribute as a resource identifier(i.e., a value originally of the form "@package:type/resource"); the other method returns a resource identifier that identifies the name of the attribute.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  int GetAttributeResourceValue(int index, int defaultValue);
  /*
  Return the integer value of attribute at 'index'.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  int GetAttributeIntValue(int index, int defaultValue);
  /*
  Return the integer value of attribute at 'index' that is formatted as an unsigned value.In particular, the formats 0xn...n and #n...n are handled.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  int GetAttributeUnsignedIntValue(int index, int defaultValue);
  /*
  Return the float value of attribute at 'index'.
  Parameters:
  index Index of the desired attribute, 0...count - 1.
  defaultValue What to return if the attribute isn't found.
  Returns :
  Resulting value.
  */
  float GetAttributeFloatValue(int index, float defaultValue);
  /*
  Return the value of the "id" attribute or null if there is not one.Equivalent to getAttributeValue(null, "id").
  Returns:
  The id attribute's value or null.
  */
  OsIndependentString* GetIdAttribute();
  /*
  Return the value of the "class" attribute or null if there is not one.Equivalent to getAttributeValue(null, "class").
  Returns:
  The class attribute's value or null.
  */
  OsIndependentString* GetClassAttribute();
  /*
  Return the integer value of the "id" attribute or defaultValue if there is none.Equivalent to getAttributeResourceValue(null, "id", defaultValue);
  Parameters:
  defaultValue What to return if the "id" attribute isn't found.
  Returns :
  int Resulting value.
  */
  int GetIdAttributeResourceValue(int defaultValue);
  /*
  Return the value of the "style" attribute or 0 if there is not one.Equivalent to getAttributeResourceValue(null, "style").
  Returns:
  The style attribute's resource identifier or 0.
  */
  int GetStyleAttribute();
};
/*
needs no Factory, because is an interface
*/
