#include "PushContentReceiveJob.h"

PushContentReceiveJob::PushContentReceiveJob(OsIndependentContext* context)
  : PushReceivedJob(context, JobParameters::NewBuilder()->Create()), 
  data(nullptr)
{ }
PushContentReceiveJob::PushContentReceiveJob(OsIndependentContext* context, OsIndependentString* data)
  : PushReceivedJob(context, JobParameters::newBuilder()->WithPersistence()->WithWakeLock(true)->Create()),
  data(data)
{
}
void PushContentReceiveJob::onRun()
{
  try
  {
    OsIndependentString* sessionKey = TextSecurePreferences::GetSignalingKey(context);
    TextSecureEnvelope* envelope = new TextSecureEnvelope(data, sessionKey);

    Handle(envelope, true);
  }
  catch (IOException e)
  {
    //Log.w(TAG, e);
  }
  catch (InvalidVersionException e)
  {
    //Log.w(TAG, e);
  }
}
