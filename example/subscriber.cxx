#include "../fastrtps/fastrtps.h"
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

extern "C" void media_callback(int callbackId, char* image);

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
			media_callback(this->callbackId, st.image().data());
    }
  }
}
