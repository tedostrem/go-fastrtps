#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/Domain.h>
#include <fastrtps/utils/eClock.h>
#include <fastrtps/utils/md5.h>
#include "MediaPubSubTypes.h"
#include "PubListener.h"
#include "Publisher.h"

using namespace eprosima::fastrtps;

class FastRTPSParticipantWrapper {
	public:
		Participant *participant;
		FastRTPSParticipantWrapper(char *name) {
  		ParticipantAttributes PParam;
  		PParam.rtps.builtin.domainId = 0;
  		PParam.rtps.builtin.leaseDuration = c_TimeInfinite;
  		PParam.rtps.setName(name);
  		participant = Domain::createParticipant(PParam);
  		if (participant == nullptr)
				throw;
		}
};

class FastRTPSPublisherWrapper {
	private:
		Publisher *publisher;
		PubListener listener;
	public:
		FastRTPSPublisherWrapper(
				Participant* participant, 
				TopicDataType* topicDataType, 
				char* topicName) {
  		// Create Publisher
  		PublisherAttributes Wparam;
			Wparam.topic.topicDataType = topicDataType->getName();
			Wparam.topic.topicName = topicName;
			Wparam.historyMemoryPolicy = DYNAMIC_RESERVE_MEMORY_MODE;
			Wparam.topic.topicKind = NO_KEY;
			Wparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
			Wparam.qos.m_durability.kind = VOLATILE_DURABILITY_QOS;
			Wparam.qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
			Wparam.topic.historyQos.depth =  50;
			Wparam.topic.resourceLimitsQos.max_samples = 100;
			Wparam.topic.resourceLimitsQos.max_instances = 1;
			Wparam.topic.resourceLimitsQos.max_samples_per_instance = 100;
			Wparam.qos.m_publishMode.kind = ASYNCHRONOUS_PUBLISH_MODE;

  		publisher = Domain::createPublisher(participant, Wparam, (PublisherListener *)&listener);
  		if (publisher == nullptr)
				throw;
  		std::cout << "Publisher created, waiting for Subscribers." << std::endl;
		}

		void Publish(char *image) {
  		Media st;
			std::memcpy(st.image().data(), image, 1382400);
  		publisher->write(&st);
			std::free(image);
		}
};

extern "C" void RegisterType(FastRTPSParticipant* participant, void* topicDataType) {
	Domain::registerType(
			((FastRTPSParticipantWrapper*)participant->wrapper)->participant, 
			(TopicDataType*)topicDataType);
}

extern "C" TopicDataTypes GetTopicDataTypes() {
	TopicDataTypes topicDataTypes;
	topicDataTypes.media = (TopicDataType*)new MediaPubSubType();
	return topicDataTypes;
}

extern "C" FastRTPSParticipant* NewFastRTPSParticipant(char *name) {
	FastRTPSParticipant* participant = new FastRTPSParticipant();
	participant->wrapper = new FastRTPSParticipantWrapper(name);
	return participant;
}

extern "C" FastRTPSPublisher* NewFastRTPSPublisher(FastRTPSParticipant *participant, void* topicDataType, char* topicName) {
	FastRTPSPublisher* publisher = new FastRTPSPublisher();
	publisher->wrapper = new FastRTPSPublisherWrapper(
			((FastRTPSParticipantWrapper*)participant->wrapper)->participant, 
			(TopicDataType*)topicDataType, 
			topicName);
	return publisher;
}

extern "C" void Publish(FastRTPSPublisher* publisher, char *image) {
	((FastRTPSPublisherWrapper *)publisher->wrapper)->Publish(image);
}
