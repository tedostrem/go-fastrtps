#include "PubListener.h"

using namespace eprosima::fastrtps;

void PubListener::onPublicationMatched(Publisher* pub, MatchingInfo& info)
{
  if (info.status == MATCHED_MATCHING)
  {
    n_matched++;
    std::cout << "Publisher matched" << std::endl;
  }
  else
  {
    n_matched--;
    std::cout << "Publisher unmatched" << std::endl;
  }
}
