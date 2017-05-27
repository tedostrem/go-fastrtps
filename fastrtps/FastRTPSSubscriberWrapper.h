#ifndef _FastRTPSSubscriberWrapper_h
#define _FastRTPSSubscriberWrapper_h

#include <fastrtps/participant/Participant.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include "SubListener.h"

using namespace eprosima::fastrtps;

class FastRTPSSubscriberWrapper
{
  private:
	Subscriber *subscriber;
	SubListener listener;

  public:
	FastRTPSSubscriberWrapper(Participant *participant, SubscriberAttributes *subscriberAttributes);
};

#endif
