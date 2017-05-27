#ifndef _AttributesFactory_h_
#define _AttributesFactory_h_

#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/Domain.h>

using namespace eprosima::fastrtps;

class AttributesFactory
{
  public:
	static PublisherAttributes *ReliablePublisher(char *topicDataTypeName, char *topicName);
	static PublisherAttributes *MultimediaPublisher(char *topicDataTypeName, char *topicName);
	static SubscriberAttributes *ReliableSubscriber(char *topicDataTypeName, char *topicName);
	static SubscriberAttributes *MultimediaSubscriber(char *topicDataTypeName, char *topicName);

};

#endif
