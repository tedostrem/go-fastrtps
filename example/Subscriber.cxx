// +build subscriber

#include <gofastrtps/FastRTPS.h>
#include <gofastrtps/MediaPubSubTypes.h>
#include "Subscriber.h"
#include "_cgo_export.h"

void MediaSubListener::onSubscriptionMatched(Subscriber *sub, MatchingInfo &info)
{
  if (info.status == MATCHED_MATCHING)
  {
    n_matched++;
		MediaOnSubscriptionMatched(n_matched);
  }
  else
  {
    n_matched--;
		MediaOnSubscriptionUnmatched(n_matched);
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
			MediaOnNewDataMessage(st.image().data());
    }
  }
}

extern "C" void *NewMediaSubListener()
{
  return (void *)new MediaSubListener();
}
