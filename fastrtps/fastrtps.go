package fastrtps

// #include "fastrtps.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"unsafe"
)

func NewParticipant(name string) unsafe.Pointer {
	return C.FastRTPSNewParticipant(C.CString(name))
}

func GetAttributes(topicDataTypeName string, topicName string) C.FastRTPSAttributes {
	return C.FastRTPSGetAttributes(C.CString(topicDataTypeName), C.CString(topicName))
}

func RegisterType(participant unsafe.Pointer, topicDataType unsafe.Pointer) {
	C.FastRTPSRegisterType(participant, topicDataType)
}

func NewPublisher(participant unsafe.Pointer, publisherAttributes unsafe.Pointer) unsafe.Pointer {
	return C.FastRTPSNewPublisher(participant, publisherAttributes)
}

func NewSubscriber(subListener unsafe.Pointer, participant unsafe.Pointer, subscriberAttributes unsafe.Pointer) unsafe.Pointer {
	return C.FastRTPSNewSubscriber(subListener, participant, subscriberAttributes)
}
