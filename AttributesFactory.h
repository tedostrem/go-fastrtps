#ifndef _AttributesFactory_h_
#define _AttributesFactory_h_

#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/Domain.h>

using namespace eprosima::fastrtps;

class AttributesFactory {
	public:
		static PublisherAttributes* ReliablePublisher(TopicDataType* topicDataType, char* topicName);
		static PublisherAttributes* MultimediaPublisher(TopicDataType* topicDataType, char* topicName); 
};

#endif
