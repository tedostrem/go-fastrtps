#ifndef _SubListener_h
#define _SubListener_h

#include <fastrtps/subscriber/SubscriberListener.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/subscriber/SampleInfo.h>

using namespace eprosima::fastrtps;

class SubListener : public SubscriberListener
{
  public:
    SubListener() : n_matched(0),n_msg(0){};
    ~SubListener(){};
    void onSubscriptionMatched(Subscriber* sub, MatchingInfo& info);
    void onNewDataMessage(Subscriber* sub);
    SampleInfo_t m_info;
    int n_matched;
    int n_msg;
};

#endif
