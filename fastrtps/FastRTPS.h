#ifdef __cplusplus
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
	void *Media;
} FastRTPSTopicDataTypes;

typedef struct
{
	void *wrapper;
} FastRTPSParticipant;

typedef struct
{
	void *wrapper;
} FastRTPSPublisher;

typedef struct
{
	void *wrapper;
} FastRTPSSubscriber;

FastRTPSAttributes FastRTPSGetAttributes(void *topicDataType, char *topicName);
FastRTPSPublisher *FastRTPSNewPublisher(FastRTPSParticipant *participant, void *publisherAttributes);
FastRTPSSubscriber *FastRTPSNewSubscriber(FastRTPSParticipant *participant, void *subscriberAttributes);
void FastRTPSRegisterType(FastRTPSParticipant *participant, void *topicDataType);
FastRTPSTopicDataTypes FastRTPSGetTopicDataTypes();
FastRTPSParticipant *FastRTPSNewParticipant(char *name);
void FastRTPSPublish(FastRTPSPublisher *publisher, char *image);

#ifdef __cplusplus
}
#endif
