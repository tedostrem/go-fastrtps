// +build subscriber

#include "../fastrtps/FastRTPS.h"
#include "../fastrtps/MediaPubSubTypes.h"
#include "MediaSubListener.h"
#include "_cgo_export.h"

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

void MediaSubListener::onNewDataMessage(Subscriber *sub)
{
  Media st;
  if (sub->takeNextData(&st, &m_info))
  {
    if (m_info.sampleKind == ALIVE)
    {
      ++n_msg;
			MediaCallback(st.image().data());
    }
  }
}

extern "C" void *NewMediaSubListener()
{
  return (void *)new MediaSubListener();
}
