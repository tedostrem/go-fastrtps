#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void* reliable;
	void* multimedia;
} FastRTPSPublisherAttributes; 

typedef struct {
	void* media;
} FastRTPSTopicDataTypes;

typedef struct {
	void* wrapper;
} FastRTPSParticipant;

typedef struct {
	void* wrapper;
} FastRTPSPublisher;

FastRTPSPublisherAttributes FastRTPSGetPublisherAttributes(void* topicDataType, char* topicName);
FastRTPSPublisher* FastRTPSNewPublisher(FastRTPSParticipant *participant, void* publisherAttributes);
void FastRTPSRegisterType(FastRTPSParticipant* participant, void* topicDataType);
FastRTPSTopicDataTypes FastRTPSGetTopicDataTypes();
FastRTPSParticipant* FastRTPSNewParticipant(char *name);
void FastRTPSPublish(FastRTPSPublisher* publisher, char *image);

#ifdef __cplusplus
}
#endif
