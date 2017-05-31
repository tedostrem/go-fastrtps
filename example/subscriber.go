// +build subscriber

package main

// #include "custom.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"crypto/md5"
	"fmt"
	"go-fastrtps/fastrtps"
	"time"
	"unsafe"
)

func OnNewMessage(image *C.char) {
	img := C.GoBytes(unsafe.Pointer(image), 1382400)
	fmt.Printf("Subscriber Golang: %x\n", md5.Sum(img))
}

func main() {
	participant := fastrtps.NewParticipant("participant_subscriber")
	topicDataType := C.NewMediaTopicDataType()
	subscriberAttributes := fastrtps.GetAttributes(C.GoString(C.GetTopicDataTypeName(topicDataType)), "topic_multimedia").MultimediaSubscriber
	fastrtps.RegisterType(participant, topicDataType)
	fn := register(OnNewMessage)
	listener := C.NewMediaSubListener(C.int(fn))
	fastrtps.NewSubscriber(listener, participant, subscriberAttributes)
	for {
		time.Sleep(1 * time.Second)
	}
	unregister(fn)
}
