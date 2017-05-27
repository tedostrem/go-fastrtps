// +build subscriber

package main

import (
	"go-fastrtps/fastrtps"
	"time"
)

func main() {
	participant := fastrtps.NewParticipant("participant_subscriber")
	topicDataType := fastrtps.GetTopicDataTypes().Media
	subscriberAttributes := fastrtps.GetAttributes(topicDataType, "topic_multimedia").MultimediaSubscriber
	fastrtps.RegisterType(participant, topicDataType)
	fastrtps.NewSubscriber(participant, subscriberAttributes)
	for {
		time.Sleep(1 * time.Second)
	}
}
