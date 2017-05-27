#include "MediaPubSubTypes.h"
#include "AttributesFactory.h"
#include "FastRTPSParticipantWrapper.h"
#include "FastRTPSPublisherWrapper.h"
#include "FastRTPSSubscriberWrapper.h"
#include "FastRTPS.h"

using namespace eprosima::fastrtps;

extern "C" void FastRTPSRegisterType(FastRTPSParticipant *participant, void *topicDataType)
{
	Domain::registerType(
		((FastRTPSParticipantWrapper *)participant->wrapper)->participant,
		(TopicDataType *)topicDataType);
}

extern "C" FastRTPSAttributes FastRTPSGetAttributes(void *topicDataType, char *topicName)
{
	FastRTPSAttributes attributes; 
	attributes.ReliablePublisher = AttributesFactory::ReliablePublisher((char *)((TopicDataType *)topicDataType)->getName(), topicName);
	attributes.MultimediaPublisher = AttributesFactory::MultimediaPublisher((char *)((TopicDataType *)topicDataType)->getName(), topicName);
	attributes.ReliableSubscriber = AttributesFactory::ReliableSubscriber((char *)((TopicDataType *)topicDataType)->getName(), topicName);
	attributes.MultimediaSubscriber= AttributesFactory::MultimediaSubscriber((char *)((TopicDataType *)topicDataType)->getName(), topicName);
	return attributes;
}

extern "C" FastRTPSTopicDataTypes FastRTPSGetTopicDataTypes()
{
	FastRTPSTopicDataTypes topicDataTypes;
	topicDataTypes.Media = (TopicDataType *)new MediaPubSubType();
	return topicDataTypes;
}

extern "C" FastRTPSParticipant* FastRTPSNewParticipant(char *name)
{
	FastRTPSParticipant *participant = new FastRTPSParticipant();
	participant->wrapper = new FastRTPSParticipantWrapper(name);
	return participant;
}

extern "C" FastRTPSPublisher* FastRTPSNewPublisher(FastRTPSParticipant *participant, void *publisherAttributes)
{
	FastRTPSPublisher* publisher = new FastRTPSPublisher();
	publisher->wrapper = new FastRTPSPublisherWrapper(
		((FastRTPSParticipantWrapper *)participant->wrapper)->participant,
		(PublisherAttributes *)publisherAttributes);
	return publisher;
}

extern "C" FastRTPSSubscriber* FastRTPSNewSubscriber(FastRTPSParticipant *participant, void *subscriberAttributes)
{
	FastRTPSSubscriber* subscriber = new FastRTPSSubscriber();
	subscriber->wrapper = new FastRTPSSubscriberWrapper(
		((FastRTPSParticipantWrapper *)participant->wrapper)->participant,
		(SubscriberAttributes *)subscriberAttributes);
	return subscriber;
}

extern "C" void FastRTPSPublish(FastRTPSPublisher *publisher, char *image)
{
	((FastRTPSPublisherWrapper *)publisher->wrapper)->Publish(image);
}
