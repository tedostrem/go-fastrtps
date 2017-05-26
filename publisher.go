package main

// #include "FastRTPS.h"
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
	mediaType := C.FastRTPSGetTopicDataTypes().Media
	participant := C.FastRTPSNewParticipant(C.CString("participant"))
	publisherAttributes := C.FastRTPSGetPublisherAttributes(mediaType, C.CString("media_topic")).MultimediaPublisher
	C.FastRTPSRegisterType(participant, mediaType)
	publisher := C.FastRTPSNewPublisher(participant, publisherAttributes)

	img := image()
	for i := 0; i < 10000; i += 1 {
		fmt.Printf("Publisher Golang: %x\n", md5.Sum(img))
		C.FastRTPSPublish(publisher, (*C.char)(C.CBytes(img)))
	}
}
