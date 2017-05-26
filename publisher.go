package main

// #include "Publisher.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"crypto/md5"
	"fmt"
	"math/rand"
	"time"
)

func image() []byte {
	rand.Seed(time.Now().UnixNano())
	buffer := make([]byte, 1382400)
	rand.Read(buffer)
	return buffer
}

func main() {
	media := C.FastRTPSGetTopicDataTypes().media
	participant := C.FastRTPSNewParticipant(C.CString("participant"))
	publisherAttributes := C.FastRTPSGetPublisherAttributes(media, C.CString("media_topic")).multimedia
	C.FastRTPSRegisterType(participant, media)
	publisher := C.FastRTPSNewPublisher(participant, publisherAttributes)

	img := image()
	for i := 0; i < 10000; i += 1 {
		fmt.Printf("Publisher Golang: %x\n", md5.Sum(img))
		C.FastRTPSPublish(publisher, (*C.char)(C.CBytes(img)))
	}
}
