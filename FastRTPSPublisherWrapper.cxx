#include <fastrtps/Domain.h>
#include "FastRTPSPublisherWrapper.h"
#include "MediaPubSubTypes.h"

using namespace eprosima::fastrtps;

FastRTPSPublisherWrapper::FastRTPSPublisherWrapper(Participant* participant, PublisherAttributes* publisherAttributes) {
	publisher = Domain::createPublisher(participant, *publisherAttributes, (PublisherListener *)&listener);
  if (publisher == nullptr)
		throw;
  std::cout << "Publisher created, waiting for Subscribers." << std::endl;
}

void FastRTPSPublisherWrapper::Publish(char *image) {
  Media st;
	std::memcpy(st.image().data(), image, 1382400);
  publisher->write(&st);
	std::free(image);
}
