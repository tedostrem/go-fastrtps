#include "../fastrtps/fastrtps.h"
#include <fastrtps/publisher/Publisher.h>
#include "publisher.h"
#include "MediaPubSubTypes.h"

extern "C" void PublishMedia(void *publisher, char *image)
{
  Media st;
  std::memcpy(st.image().data(), image, 1382400);
  ((Publisher *)((FastRTPSPublisher *)publisher)->publisher)->write(&st);
  std::free(image);
}
