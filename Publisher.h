#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void* media;
} TopicDataTypes;

typedef struct {
	void* wrapper;
} FastRTPSParticipant;

typedef struct {
	void* wrapper;
} FastRTPSPublisher;

TopicDataTypes GetTopicDataTypes();
FastRTPSParticipant* NewFastRTPSParticipant(char *name);
FastRTPSPublisher* NewFastRTPSPublisher(FastRTPSParticipant *participant, void* topicDataType, char* topicName);
void Publish(FastRTPSPublisher* publisher, char *image);

#ifdef __cplusplus
}
#endif
