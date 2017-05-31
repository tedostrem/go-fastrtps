CXX := g++
AR := ar
ARFLAGS := rvs
CXXFLAGS := -I/usr/local/include -L/usr/local/lib -lfastcdr -lfastrtps -std=c++11

# IDL_FILES := $(shell find -type f -name "*.idl")
# GENERATED_HEADER_FILES := ${IDL_FILES:%.idl=%PubSubTypes.h} ${IDL_FILES:%.idl=%.h}
# GENERATED_SOURCE_FILES := ${IDL_FILES:%.idl=%PubSubTypes.cxx} ${IDL_FILES:%.idl=%.cxx}
SOURCE_FILES := \
	FastRTPS.cxx \
	PubListener.cxx \
	AttributesFactory.cxx \
	FastRTPSPublisherWrapper.cxx \
	FastRTPSSubscriberWrapper.cxx

OBJECT_FILES := ${SOURCE_FILES:%.cxx=%.o}
OUTPUT_LIB := lib.a
PUBLISHER_BIN := ./publisher.out
SUBSCRIBER_BIN := ./subscriber.out

.PHONY : clean

lib : ${OUTPUT_LIB}
publisher : ${PUBLISHER_BIN}
subscriber : ${SUBSCRIBER_BIN}

${OBJECT_FILES} : ${SOURCE_FILES}
	@${CXX} ${CXXFLAGS} -c ${SOURCE_FILES}

${OUTPUT_LIB} : ${OBJECT_FILES}
	@${AR} ${ARFLAGS} ${OUTPUT_LIB} ${OBJECT_FILES}

clean :
	@rm -f ${SUBSCRIBER_BIN} ${PUBLISHER_BIN} ${OBJECT_FILES} ${OUTPUT_LIB}
