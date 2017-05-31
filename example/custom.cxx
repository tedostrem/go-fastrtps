#include <fastrtps/TopicDataType.h>
#include <fastrtps/publisher/Publisher.h>
#include "custom.h"
#include "MediaPubSubTypes.h"
#include "MediaSubListener.h"

void MediaSubListener::onSubscriptionMatched(Subscriber *sub, MatchingInfo &info)
{
  if (info.status == MATCHED_MATCHING)
  {
    n_matched++;
    std::cout << "Subscriber matched" << std::endl;
  }
  else
  {
    n_matched--;
    std::cout << "Subscriber unmatched" << std::endl;
  }
}

extern "C" void go_callback(int callbackId, char* image);

void MediaSubListener::onNewDataMessage(Subscriber *sub)
{
  Media st;
  if (sub->takeNextData(&st, &m_info))
  {
    if (m_info.sampleKind == ALIVE)
    {
      ++n_msg;
      std::string str(st.image().begin(), st.image().end());
      std::cout << "Subscriber C++:    " << md5(str) << std::endl;
			go_callback(this->callbackId, st.image().data());
    }
  }
}

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

extern "C" void Publish(void *publisher, char *image)
{
  Media st;
  std::memcpy(st.image().data(), image, 1382400);
  ((Publisher *)((FastRTPSPublisher *)publisher)->publisher)->write(&st);
  std::free(image);
}
