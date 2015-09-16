/* 
  Port of NotificationTracker.h from Signal-iOS 
  */

#ifndef NOTIFICATIONTRACKER_H_
#define NOTIFICATIONTRACKER_H_

// ??? #import <Foundation/Foundation.h>

/**
 *  Tracks which notifications have already been processed, and which are are seen for the first time. 
 **/

//@interface NotificationTracker : NSObject
class NotificationTracker
{
public:
//+(NotificationTracker*) notificationTracker;
  static NotificationTracker* CreateNotificationTracker(void);

//-(BOOL) shouldProcessNotification:(NSDictionary*) notification;
  bool ShouldProcessNotification(NSDictionary*);

}

#endif // NOTIFICATIONTRACKER_H_
