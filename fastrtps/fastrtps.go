package fastrtps

// #include "FastRTPS.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"unsafe"
)

type Publisher struct {
	publisher *C.FastRTPSPublisher
}

type Subscriber struct {
	subscriber *C.FastRTPSSubscriber
}

func GetTopicDataTypes() C.FastRTPSTopicDataTypes {
	return C.FastRTPSGetTopicDataTypes()
}

func NewParticipant(name string) *C.FastRTPSParticipant {
	return C.FastRTPSNewParticipant(C.CString(name))
}

func GetAttributes(topicDataType unsafe.Pointer, topicName string) C.FastRTPSAttributes {
	return C.FastRTPSGetAttributes(topicDataType, C.CString(topicName))
}

func RegisterType(participant *C.FastRTPSParticipant, topicDataType unsafe.Pointer) {
	C.FastRTPSRegisterType(participant, topicDataType)
}

func (p *Publisher) Publish(image []byte) {
	C.FastRTPSPublish(p.publisher, (*C.char)(C.CBytes(image)))
}

func NewPublisher(participant *C.FastRTPSParticipant, publisherAttributes unsafe.Pointer) *Publisher {
	return &Publisher{
		publisher: C.FastRTPSNewPublisher(participant, publisherAttributes),
	}
}

func NewSubscriber(participant *C.FastRTPSParticipant, subscriberAttributes unsafe.Pointer) *Subscriber {
	return &Subscriber{
		subscriber: C.FastRTPSNewSubscriber(participant, subscriberAttributes),
	}
}
