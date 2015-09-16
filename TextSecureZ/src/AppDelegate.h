/* 
  Port of AppDelegate.h from Signal-iOS 
  */

#ifndef APPDELEGATE_H_
// ??? #import <UIKit/UIKit.h>

// ??? #include "SignalsViewController.h"

//@interface AppDelegate : UIResponder <UIApplicationDelegate> 
class AppDelegate
{
private:
  void* window;
  SignalsViewController* signalVC;
public:
//@property (strong, nonatomic) UIWindow *window;
  void* GetWindow(void);
  void SetWindow(void*);

//@property (strong, nonatomic) SignalsViewController *signalVC;
  SignalsViewController* GetViewController(void);
  void SetViewController(SignalsViewController*);
}
#endif // APPDELEGATE_H_
