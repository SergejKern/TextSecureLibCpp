#pragma once
/*
Port of class WebSocketEventListener from TextSecure-android
*/

// [x] done
// TFS ID: 369

//interface WebSocketEventListener
class WebSocketEventListener
{
  virtual void OnMessage(char* payload) = 0;
  virtual void OnClose() = 0;
  virtual void OnConnected() = 0;
};
