#include "PushReceivedJob.h"

PushReceivedJob::PushReceivedJob(OsIndependentContext* context, JobParameters* parameters)
{
  super(context, parameters);
}
void PushReceivedJob::Handle(TextSecureEnvelope* envelope, bool sendExplicitReceipt)
{
  if (!isActiveNumber(context, envelope->GetSource())) {
    TextSecureDirectory* directory = TextSecureDirectory::GetInstance(context);
    ContactTokenDetails* contactTokenDetails = new ContactTokenDetails();
    contactTokenDetails->SetNumber(envelope->GetSource());

    directory->SetNumber(contactTokenDetails, true);
  }

  if (envelope->IsReceipt())
    HandleReceipt(envelope);
  else
    HandleMessage(envelope, sendExplicitReceipt);
}
void PushReceivedJob::HandleMessage(TextSecureEnvelope* envelope, bool sendExplicitReceipt)
{
  Recipients recipients = RecipientFactory.getRecipientsFromString(context, envelope.getSource(), false);
  JobManager jobManager = ApplicationContext.getInstance(context).getJobManager();

  if (!recipients.isBlocked()) {
    long messageId = DatabaseFactory.getPushDatabase(context).insert(envelope);
    jobManager.add(new PushDecryptJob(context, messageId, envelope.getSource()));
  }
  else {
    Log.w(TAG, "*** Received blocked push message, ignoring...");
  }

  if (sendExplicitReceipt) {
    jobManager.add(new DeliveryReceiptJob(context, envelope.getSource(),
      envelope.getTimestamp(),
      envelope.getRelay()));
  }
}
void PushReceivedJob::HandleReceipt(TextSecureEnvelope* envelope)
{
  Log.w(TAG, String.format("Received receipt: (XXXXX, %d)", envelope.getTimestamp()));
  DatabaseFactory.getMmsSmsDatabase(context).incrementDeliveryReceiptCount(envelope.getSource(),
    envelope.getTimestamp());
}
bool PushReceivedJob::IsActiveNumber(OsIndependentContext* context, OsIndependentString* e164number)
{
  bool isActiveNumber;
  try
  {
    isActiveNumber = TextSecureDirectory::GetInstance(context)->IsActiveNumber(e164number);
  }
  catch (NotInDirectoryException e)
  {
    isActiveNumber = false;
  }

  return isActiveNumber;
}
