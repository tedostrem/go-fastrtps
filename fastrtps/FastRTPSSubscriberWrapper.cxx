#include <fastrtps/Domain.h>
#include "FastRTPSSubscriberWrapper.h"

using namespace eprosima::fastrtps;

FastRTPSSubscriberWrapper::FastRTPSSubscriberWrapper(Participant *participant, SubscriberAttributes *subscriberAttributes)
{
  subscriber = Domain::createSubscriber(participant, *subscriberAttributes, (SubscriberListener *)&listener);
  if (subscriber == nullptr)
    throw;
  std::cout << "Subscriber created, waiting for data." << std::endl;
}
