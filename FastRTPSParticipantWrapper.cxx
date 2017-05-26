#include <fastrtps/Domain.h>
#include "FastRTPSParticipantWrapper.h"

using namespace eprosima::fastrtps;

FastRTPSParticipantWrapper::FastRTPSParticipantWrapper(char *name) {
  ParticipantAttributes PParam;
  PParam.rtps.builtin.domainId = 0;
  PParam.rtps.builtin.leaseDuration = c_TimeInfinite;
  PParam.rtps.setName(name);
  participant = Domain::createParticipant(PParam);
  if (participant == nullptr)
		throw;
}
