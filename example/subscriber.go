// +build subscriber

package main

// #include "MediaSubListener.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto ../fastrtps/lib.a
import "C"

import (
	"crypto/md5"
	"fmt"
	"go-fastrtps/fastrtps"
	"time"
	"unsafe"
)

//export MediaCallback
func MediaCallback(image *C.char) {
	img := C.GoBytes(unsafe.Pointer(image), 1382400)
	fmt.Printf("Subscriber Golang: %x\n", md5.Sum(img))
}

func main() {
	participant := fastrtps.NewParticipant("participant_subscriber")
	topicDataType := fastrtps.NewMediaTopicDataType()
	subscriberAttributes := fastrtps.GetAttributes(topicDataType, "topic_multimedia").MultimediaSubscriber
	fastrtps.RegisterType(participant, topicDataType)
	listener := C.NewMediaSubListener()
	fastrtps.NewSubscriber(listener, participant, subscriberAttributes)
	for {
		time.Sleep(1 * time.Second)
	}
}
