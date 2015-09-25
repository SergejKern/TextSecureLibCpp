#pragma once
/*
Port of class ContactTokenDetails from TextSecure-android
*/

// [x] done
// TFS ID: 284

/**
 * A class that represents a contact's registration state.
 */
class ContactTokenDetails
{
private:
  unsigned char* token;
  unsigned char* relay;
  unsigned char* number;
  bool supportsSms;
public:
  ContactTokenDetails() {}
  /**
   * @return The "anonymized" token (truncated hash) that's transmitted to the server.
   */
  unsigned char* GetToken() { return this->token; }
  /**
   * @return The federated server this contact is registered with, or null if on your server.
   */
  unsigned char* GetRelay() { return this->relay; }
  /**
   * @return Whether this contact supports receiving encrypted SMS.
   */
  bool IsSupportsSms() { return this->supportsSms; }
  /**
   * @return This contact's username (e164 formatted number).
   */
  unsigned char* GetNumber() { return this->number; }
  void SetNumber(unsigned char* number) { this->number = number; }
};
