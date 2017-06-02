// +build publisher

#include <fastrtps/publisher/Publisher.h>
#include "../fastrtps/FastRTPS.h"
#include "../fastrtps/MediaPubSubTypes.h"
#include "Publisher.h"

extern "C" void PublishMedia(void *publisher, char *image)
{
  Media st;
  std::memcpy(st.image().data(), image, 1382400);
  ((Publisher *)((FastRTPSPublisher *)publisher)->publisher)->write(&st);
  std::free(image);
}
