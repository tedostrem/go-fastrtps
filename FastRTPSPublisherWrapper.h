#ifndef _FastRTPSPublisherWrapper_h
#define _FastRTPSPublisherWrapper_h

#include <fastrtps/participant/Participant.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include "PubListener.h"

using namespace eprosima::fastrtps;

class FastRTPSPublisherWrapper {
	private:
		Publisher* publisher;
		PubListener listener;
	public:
		FastRTPSPublisherWrapper(Participant* participant, PublisherAttributes* publisherAttributes);
		void Publish(char *image);
};

#endif
