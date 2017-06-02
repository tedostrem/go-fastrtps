// +build subscriber

package main

// #include "Subscriber.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lgofastrtps
import "C"

import (
	"crypto/md5"
	"fmt"
	"go-fastrtps/fastrtps"
	"os"
	"os/signal"
	"time"
	"unsafe"
)

//export MediaOnSubscriptionMatched
func MediaOnSubscriptionMatched(subscribers C.int) {
	fmt.Println("Subscription matched: ", int(subscribers))
}

//export MediaOnSubscriptionUnmatched
func MediaOnSubscriptionUnmatched(subscribers C.int) {
	fmt.Println("Subscription unmatched: ", int(subscribers))
}

//export MediaOnNewDataMessage
func MediaOnNewDataMessage(image *C.char) {
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
	c := make(chan os.Signal, 1)
	signal.Notify(c, os.Interrupt)
	go func() {
		for _ = range c {
			fastrtps.RemoveParticipant(participant)
			os.Exit(0)
		}
	}()
	for {
		time.Sleep(1 * time.Second)
	}
}
