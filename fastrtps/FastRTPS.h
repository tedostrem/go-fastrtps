#ifdef __cplusplus
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/Domain.h>

using namespace eprosima::fastrtps;

class AttributesFactory
{
  public:
	static PublisherAttributes *ReliablePublisher(void *topicDataType, char *topicName);
	static PublisherAttributes *MultimediaPublisher(void *topicDataType, char *topicName);
	static SubscriberAttributes *ReliableSubscriber(void *topicDataType, char *topicName);
	static SubscriberAttributes *MultimediaSubscriber(void *topicDataType, char *topicName);
};

extern "C" {
#endif
typedef struct
{
	void *ReliablePublisher;
	void *MultimediaPublisher;
	void *ReliableSubscriber;
	void *MultimediaSubscriber;
} FastRTPSAttributes;

typedef struct
{
	void *listener;
	void *publisher;
} FastRTPSPublisher;

typedef struct
{
	void *subscriber;
	void *listener;
} FastRTPSSubscriber;

FastRTPSAttributes FastRTPSGetAttributes(void *topicDataType, char *topicName);
void *FastRTPSNewPublisher(void *participant, void *publisherAttributes);
void *FastRTPSNewSubscriber(void *subscriberListener, void *participant, void *subscriberAttributes);
void *FastRTPSNewParticipant(char *name);
void *FastRTPSNewMediaTopicDataType();
void FastRTPSRegisterType(void *participant, void *topicDataType);

#ifdef __cplusplus
}
#endif
