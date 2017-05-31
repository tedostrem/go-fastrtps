// +build subscriber

package main

// #include "custom.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"go-fastrtps/fastrtps"
	"time"
)

func main() {
	participant := fastrtps.NewParticipant("participant_subscriber")
	topicDataType := C.NewMediaTopicDataType()
	subscriberAttributes := fastrtps.GetAttributes(C.GoString(C.GetTopicDataTypeName(topicDataType)), "topic_multimedia").MultimediaSubscriber
	fastrtps.RegisterType(participant, topicDataType)
	listener := C.NewMediaSubListener()
	fastrtps.NewSubscriber(listener, participant, subscriberAttributes)
	for {
		time.Sleep(1 * time.Second)
	}
}
