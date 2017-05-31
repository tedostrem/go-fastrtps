#include "fastrtps.h"

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

extern "C" void FastRTPSRegisterType(void *participant, void *topicDataType)
{
	Domain::registerType((Participant *)participant, (TopicDataType *)topicDataType);
}

extern "C" FastRTPSAttributes FastRTPSGetAttributes(char *topicDataTypeName, char *topicName)
{
	FastRTPSAttributes attributes;
	attributes.ReliablePublisher = AttributesFactory::ReliablePublisher(topicDataTypeName, topicName);
	attributes.MultimediaPublisher = AttributesFactory::MultimediaPublisher(topicDataTypeName, topicName);
	attributes.ReliableSubscriber = AttributesFactory::ReliableSubscriber(topicDataTypeName, topicName);
	attributes.MultimediaSubscriber = AttributesFactory::MultimediaSubscriber(topicDataTypeName, topicName);
	return attributes;
}

extern "C" void *FastRTPSNewParticipant(char *name)
{
	ParticipantAttributes PParam;
	PParam.rtps.builtin.domainId = 0;
	PParam.rtps.builtin.leaseDuration = c_TimeInfinite;
	PParam.rtps.setName(name);
	Participant *participant = Domain::createParticipant(PParam);
	if (participant == nullptr)
		throw "Participant could not be created";
	return (void *)participant;
}

extern "C" void *FastRTPSNewPublisher(void *participant, void *publisherAttributes)
{
	FastRTPSPublisher *publisher = new FastRTPSPublisher();
	publisher->publisher = (Publisher *)Domain::createPublisher(
		(Participant *)participant,
		*((PublisherAttributes *)publisherAttributes),
		(PublisherListener *)publisher->listener);
	if (publisher->publisher == nullptr)
		throw "Publisher could not be created";
	return (void *)publisher;
}

extern "C" void *FastRTPSNewSubscriber(void *subListener, void *participant, void *subscriberAttributes)
{
	FastRTPSSubscriber *subscriber = new FastRTPSSubscriber();
	subscriber->listener = (SubscriberListener *)subListener;
	subscriber->subscriber = (Subscriber *)Domain::createSubscriber(
		(Participant *)participant,
		*((SubscriberAttributes *)subscriberAttributes),
		(SubscriberListener *)subscriber->listener);
	if (subscriber->subscriber == nullptr)
		throw "Subscriber could not be created";
	return (void *)subscriber;
}