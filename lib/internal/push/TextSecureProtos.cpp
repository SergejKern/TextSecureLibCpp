#include "TextSecureProtos.h"

TextSecureProtos::SyncMessage::Request::Type 
TextSecureProtos::SyncMessage::Request::GetType()
{
  return this->type;
}
