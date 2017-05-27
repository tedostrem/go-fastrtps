// +build subscriber

package main

// #include "FastRTPS.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"time"
)

func main() {
	mediaType := C.FastRTPSGetTopicDataTypes().Media
	participant := C.FastRTPSNewParticipant(C.CString("participant_subscriber"))
	mediaSubscriberAttributes := C.FastRTPSGetAttributes(mediaType, C.CString("topic_multimedia")).MultimediaSubscriber
	C.FastRTPSRegisterType(participant, mediaType)
	C.FastRTPSNewSubscriber(participant, mediaSubscriberAttributes)
	for {
		time.Sleep(1 * time.Second)
	}
}
