# FastRTPS Most Commonly Used Attributes

```yml
* SimpleEDPAttributes
  * bool use_PublicationWriterANDSubscriptionReader : true
  * bool use_PublicationReaderANDSubscriptionWriter : true

* BuiltInAttributes
  * SimpleEDPAttributes m_simpleEDP
  * bool use_SIMPLE_RTPSParticipantDiscoveryProtocol : true
  * bool use_SIMPLE_EndpointDiscoveryProtocol : true
  * bool use_STATIC_EndpointDiscoveryProtocol : false 
  * uint32_t domainId : 80
  * Duration_t leaseDuration : 500 # seconds 
  * Duration_t leaseDuration_announcmentperiod : 250 # seconds 

* DurabilityQosPolicyKind
  * octet VOLATILE_DURABILITY_QOS : 0
  * octet TRANSIENT_LOCAL_DURABILITY_QOS : 1

* DurabilityQosPolicy
  * DurabilityQosPolicyKind kind : VOLATILE_DURABILITY_QOS

* HistoryQosPolicyKind kind
  * KEEP_LAST_HISTORY_QOS : 0 
  * KEEP_ALL_HISTORY_QOS : 1

* HistoryQosPolicy
  * HistoryQosPolicyKind kind : KEEP_LAST_HISTORY_QOS
  * int32_t depth : 1000

* ResourceLimitsQosPolicy
  * int32_t max_samples : 5000
  * int32_t max_instances : 10
  * int32_t max_samples_per_instance : 400	
  * int32_t allocated_samples : 100

* ReliabilityQosPolicyKind
  * BEST_EFFORT_RELIABILITY_QOS : 0x01 # default for subscribers
  * RELIABLE_RELIABILITY_QOS : 0x02 # default for publishers

* ReliabilityQosPolicy
  * ReliabilityQosPolicyKind kind

* LivelinessQosPolicyKind
  * AUTOMATIC_LIVELINESS_QOS : 0
  * MANUAL_BY_PARTICIPANT_LIVELINESS_QOS: 1
  * MANUAL_BY_TOPIC_LIVELINESS_QOS: 2

* LivelinessQosPolicy 
  * LivelinessQosPolicyKind kind
  * Duration_t lease_duration : c_TimeInfinite
  * Duration_t announcement_period : c_TimeInfinite

* PublishModeQosPolicyKind
  * SYNCHRONOUS_PUBLISH_MODE : 0 # default for writers)
  * ASYNCHRONOUS_PUBLISH_MODE : 1 
 
* PublishModeQosPolicy
  * PublishModeQosPolicyKind kind : SYNCHRONOUS_PUBLISH_MODE

* MemoryManagmentPolicy historyMemoryPolicy
  * PREALLOCATED_MEMORY_MODE : 0
  * PREALLOCATED_WITH_REALLOC_MEMORY_MODE : 1
  * DYNAMIC_RESERVE_MEMORY_MODE : 2

* TopicAttributes
  * string topicKind : NO_KEY
  * string topicName : "UNDEF"
  * string topicDataType : "UNDEF"
  * HistoryQosPolicy historyQos
  * ResourceLimitsQosPolicy resourceLimitsQos

* ReaderQos
  * DurabilityQosPolicy m_durability
  * ReliabilityQosPolicy m_reliability
  * LivelinessQosPolicy m_liveliness

* Writer 
  * DurabilityQosPolicy m_durability
  * ReliabilityQosPolicy m_reliability
  * LivelinessQosPolicy m_liveliness
  * PublishModeQosPolicy m_publishMode

* RTPSParticipantAttributes
  *	func setName("RTPSParticipant")
  * uint32_t defaultSendPort : 10040
  * bool use_IP4_to_send : true
  * bool use_IP6_to_send : false

* Participant
  * RTPSParticipantAttributes rtps

* Subscriber
  * TopicAttributes topic
  * ReaderQos qos 
  * MemoryManagmentPolicy historyMemoryPolicy

* Publisher
  * TopicAttributes topic
  * WriterQos qos
  * MemoryManagmentPolicy historyMemoryPolicy
```
