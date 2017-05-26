#include "MediaPubSubTypes.h"
#include "AttributesFactory.h"
#include "FastRTPSParticipantWrapper.h"
#include "FastRTPSPublisherWrapper.h"
#include "FastRTPS.h"

using namespace eprosima::fastrtps;

extern "C" void FastRTPSRegisterType(FastRTPSParticipant *participant, void *topicDataType)
{
	Domain::registerType(
		((FastRTPSParticipantWrapper *)participant->wrapper)->participant,
		(TopicDataType *)topicDataType);
}

extern "C" FastRTPSPublisherAttributes FastRTPSGetPublisherAttributes(void *topicDataType, char *topicName)
{
	FastRTPSPublisherAttributes publisherAttributes;
	publisherAttributes.ReliablePublisher = AttributesFactory::ReliablePublisher((char *)((TopicDataType *)topicDataType)->getName(), topicName);
	publisherAttributes.MultimediaPublisher = AttributesFactory::MultimediaPublisher((char *)((TopicDataType *)topicDataType)->getName(), topicName);
	return publisherAttributes;
}

extern "C" FastRTPSTopicDataTypes FastRTPSGetTopicDataTypes()
{
	FastRTPSTopicDataTypes topicDataTypes;
	topicDataTypes.Media = (TopicDataType *)new MediaPubSubType();
	return topicDataTypes;
}

extern "C" FastRTPSParticipant *FastRTPSNewParticipant(char *name)
{
	FastRTPSParticipant *participant = new FastRTPSParticipant();
	participant->wrapper = new FastRTPSParticipantWrapper(name);
	return participant;
}

extern "C" FastRTPSPublisher *FastRTPSNewPublisher(FastRTPSParticipant *participant, void *publisherAttributes)
{
	FastRTPSPublisher *publisher = new FastRTPSPublisher();
	publisher->wrapper = new FastRTPSPublisherWrapper(
		((FastRTPSParticipantWrapper *)participant->wrapper)->participant,
		(PublisherAttributes *)publisherAttributes);
	return publisher;
}

extern "C" void FastRTPSPublish(FastRTPSPublisher *publisher, char *image)
{
	((FastRTPSPublisherWrapper *)publisher->wrapper)->Publish(image);
}
