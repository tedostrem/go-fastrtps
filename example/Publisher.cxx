// +build publisher
#include <gofastrtps/FastRTPS.h>
#include <gofastrtps/MediaPubSubTypes.h>
#include "Publisher.h"

extern "C" void PublishMedia(void *publisher, char *image)
{
  Media st;
  std::memcpy(st.image().data(), image, 1382400);
  ((Publisher *)((FastRTPSPublisher *)publisher)->publisher)->write(&st);
  std::free(image);
}
