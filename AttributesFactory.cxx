#include "AttributesFactory.h"

using namespace eprosima::fastrtps;

PublisherAttributes *AttributesFactory::ReliablePublisher(char *topicDataTypeName, char *topicName)
{
	PublisherAttributes *Wparam = new PublisherAttributes();
	Wparam->topic.topicDataType = topicDataTypeName;
	Wparam->topic.topicName = topicName;
	return Wparam;
}

PublisherAttributes *AttributesFactory::MultimediaPublisher(char *topicDataTypeName, char *topicName)
{
	PublisherAttributes *Wparam = new PublisherAttributes();
	Wparam->topic.topicDataType = topicDataTypeName;
	Wparam->topic.topicName = topicName;
	Wparam->qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
	Wparam->topic.historyQos.depth = 50;
	Wparam->topic.resourceLimitsQos.max_samples = 101;
	Wparam->topic.resourceLimitsQos.max_instances = 1;
	Wparam->topic.resourceLimitsQos.max_samples_per_instance = 100;
	Wparam->qos.m_publishMode.kind = ASYNCHRONOUS_PUBLISH_MODE;
	return Wparam;
}


SubscriberAttributes *AttributesFactory::ReliableSubscriber(char *topicDataTypeName, char *topicName)
{
	SubscriberAttributes *Wparam = new SubscriberAttributes();
	Wparam->topic.topicDataType = topicDataTypeName;
	Wparam->topic.topicName = topicName;
	return Wparam;
}

SubscriberAttributes *AttributesFactory::MultimediaSubscriber(char *topicDataTypeName, char *topicName)
{
	SubscriberAttributes *Wparam = new SubscriberAttributes();
	Wparam->topic.topicDataType = topicDataTypeName;
	Wparam->topic.topicName = topicName;
	Wparam->qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
	Wparam->topic.historyQos.depth = 50;
	Wparam->topic.resourceLimitsQos.max_samples = 101;
	Wparam->topic.resourceLimitsQos.max_instances = 1;
	Wparam->topic.resourceLimitsQos.max_samples_per_instance = 100;
	return Wparam;
}
