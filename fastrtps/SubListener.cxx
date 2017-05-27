#include "SubListener.h" 
#include "MediaPubSubTypes.h"

void SubListener::onSubscriptionMatched(Subscriber* sub, MatchingInfo& info)
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

void SubListener::onNewDataMessage(Subscriber* sub)
{
    Media st;
    if(sub->takeNextData(&st, &m_info))
    {
      if(m_info.sampleKind == ALIVE)
      {
        ++n_msg;
        std::string str(st.image().begin(), st.image().end());
        std::cout << "Subscriber C++:    " << md5(str) << std::endl;
      }
    }
}
