#ifndef _PubListener_h
#define _PubListener_h

#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/publisher/Publisher.h>

using namespace eprosima::fastrtps;

class PubListener : public PublisherListener
{
	public:
  	PubListener() : n_matched(0){};
  	~PubListener(){};
  	void onPublicationMatched(Publisher *pub, MatchingInfo &info);
  	int n_matched;
};

#endif
