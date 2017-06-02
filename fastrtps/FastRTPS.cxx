#include "FastRTPS.h"
#include "MediaPubSubTypes.h"

using namespace eprosima::fastrtps;

PublisherAttributes *AttributesFactory::ReliablePublisher(void *topicDataType, char *topicName)
{
	PublisherAttributes *param = new PublisherAttributes();
	param->topic.topicDataType = ((TopicDataType *)topicDataType)->getName();
	param->topic.topicName = topicName;
	return param;
}

PublisherAttributes *AttributesFactory::MultimediaPublisher(void *topicDataType, char *topicName)
{
	PublisherAttributes *param = new PublisherAttributes();
	param->topic.topicDataType = ((TopicDataType *)topicDataType)->getName();
	param->topic.topicName = topicName;
	param->qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
	param->topic.historyQos.depth = 50;
	param->topic.resourceLimitsQos.max_samples = 101;
	param->topic.resourceLimitsQos.max_instances = 1;
	param->topic.resourceLimitsQos.max_samples_per_instance = 100;
	param->qos.m_publishMode.kind = ASYNCHRONOUS_PUBLISH_MODE;
	return param;
}

SubscriberAttributes *AttributesFactory::ReliableSubscriber(void *topicDataType, char *topicName)
{
	SubscriberAttributes *param = new SubscriberAttributes();
	param->topic.topicDataType = ((TopicDataType *)topicDataType)->getName();
	param->topic.topicName = topicName;
	return param;
}

SubscriberAttributes *AttributesFactory::MultimediaSubscriber(void *topicDataType, char *topicName)
{
	SubscriberAttributes *param = new SubscriberAttributes();
	param->topic.topicDataType = ((TopicDataType *)topicDataType)->getName();
	param->topic.topicName = topicName;
	param->qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
	param->topic.historyQos.depth = 50;
	param->topic.resourceLimitsQos.max_samples = 101;
	param->topic.resourceLimitsQos.max_instances = 1;
	param->topic.resourceLimitsQos.max_samples_per_instance = 100;
	return param;
}

extern "C" void FastRTPSRegisterType(void *participant, void *topicDataType)
{
	Domain::registerType((Participant *)participant, (TopicDataType *)topicDataType);
}

extern "C" FastRTPSAttributes FastRTPSGetAttributes(void *topicDataType, char *topicName)
{
	FastRTPSAttributes attributes;
	attributes.ReliablePublisher = AttributesFactory::ReliablePublisher(topicDataType, topicName);
	attributes.MultimediaPublisher = AttributesFactory::MultimediaPublisher(topicDataType, topicName);
	attributes.ReliableSubscriber = AttributesFactory::ReliableSubscriber(topicDataType, topicName);
	attributes.MultimediaSubscriber = AttributesFactory::MultimediaSubscriber(topicDataType, topicName);
	return attributes;
}

extern "C" void *FastRTPSNewParticipant(char *name)
{
	ParticipantAttributes param;
	param.rtps.builtin.domainId = 0;
	param.rtps.builtin.leaseDuration = c_TimeInfinite;
	param.rtps.setName(name);
	Participant *participant = Domain::createParticipant(param);
	if (participant == nullptr)
		throw "Participant could not be created";
	return (void *)participant;
}

extern "C" void *FastRTPSNewPublisher(void *participant, void *publisherAttributes)
{
	FastRTPSPublisher *publisher = new FastRTPSPublisher();
	publisher->publisher = (Publisher *)Domain::createPublisher(
		(Participant *)participant,
		*(PublisherAttributes *)publisherAttributes,
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
		*(SubscriberAttributes *)subscriberAttributes,
		(SubscriberListener *)subscriber->listener);
	if (subscriber->subscriber == nullptr)
		throw "Subscriber could not be created";
	return (void *)subscriber;
}

extern "C" void *FastRTPSNewMediaTopicDataType() {
	return (void*)new MediaPubSubType();
}
