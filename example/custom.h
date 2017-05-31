#include "../fastrtps/fastrtps.h"
#ifdef __cplusplus
extern "C" {
#endif

void *NewMediaSubListener(int callbackId);
void *NewMediaTopicDataType();
char *GetTopicDataTypeName(void *topicDataType);
void Publish(void *publisher, char *image);

#ifdef __cplusplus
}
#endif
