#include "../fastrtps/fastrtps.h"
#include <fastrtps/TopicDataType.h>
#include "MediaPubSubTypes.h"
#include "MediaSubListener.h"
#include "generated.h"

extern "C" void *NewMediaSubListener(int id)
{
  return (void *)new MediaSubListener(id);
}

extern "C" void *NewMediaTopicDataType()
{
  return (void *)new MediaPubSubType();
}

extern "C" char *GetTopicDataTypeName(void *topicDataType)
{
  return (char *)(((TopicDataType *)topicDataType)->getName());
}
