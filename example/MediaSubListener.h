#ifndef _MediaSubListener_h
#define _MediaSubListener_h

#include <fastrtps/subscriber/SubscriberListener.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/subscriber/SampleInfo.h>

using namespace eprosima::fastrtps;

class MediaSubListener : public SubscriberListener
{
  public:
    MediaSubListener() : n_matched(0),n_msg(0){};
    ~MediaSubListener(){};
    void onSubscriptionMatched(Subscriber* sub, MatchingInfo& info);
    void onNewDataMessage(Subscriber* sub);
    SampleInfo_t m_info;
    int n_matched;
    int n_msg;
};

#endif
