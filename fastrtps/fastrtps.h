#ifdef __cplusplus

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

FastRTPSAttributes FastRTPSGetAttributes(char *topicDataTypeName, char *topicName);
void *FastRTPSNewPublisher(void *participant, void *publisherAttributes);
void *FastRTPSNewSubscriber(void *subscriberListener, void *participant, void *subscriberAttributes);
void *FastRTPSNewParticipant(char *name);
void FastRTPSRegisterType(void *participant, void *topicDataType);

#ifdef __cplusplus
}
#endif