#ifndef _FastRTPSParticipantWrapper_h
#define _FastRTPSParticipantWrapper_h

#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>

using namespace eprosima::fastrtps;

class FastRTPSParticipantWrapper {
	public:
		Participant *participant;
		FastRTPSParticipantWrapper(char *name);
};

#endif
