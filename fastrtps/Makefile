CXX := g++
AR := ar
ARFLAGS := rvs
CXXFLAGS := -I/usr/local/include -L/usr/local/lib -lfastcdr -lfastrtps -std=c++11

IDL_FILES := $(shell find -type f -name "*.idl")
GENERATED_HEADER_FILES := ${IDL_FILES:%.idl=%PubSubTypes.h} ${IDL_FILES:%.idl=%.h}
GENERATED_SOURCE_FILES := ${IDL_FILES:%.idl=%PubSubTypes.cxx} ${IDL_FILES:%.idl=%.cxx}

SOURCE_FILES := \
	FastRTPS.cxx

OBJECT_FILES := ${SOURCE_FILES:%.cxx=%.o} ${GENERATED_SOURCE_FILES:%.cxx=%.o}
OUTPUT_LIB := lib.a
PUBLISHER_BIN := ./publisher.out
SUBSCRIBER_BIN := ./subscriber.out

.PHONY : clean

lib : ${OUTPUT_LIB}
generate : ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES}

${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES} : ${IDL_FILES}
	@fastrtpsgen -replace ${IDL_FILES}

${OBJECT_FILES} : ${SOURCE_FILES} ${GENERATED_SOURCE_FILES}
	@${CXX} ${CXXFLAGS} -c ${SOURCE_FILES} ${GENERATED_SOURCE_FILES}

${OUTPUT_LIB} : ${OBJECT_FILES}
	@${AR} ${ARFLAGS} ${OUTPUT_LIB} ${OBJECT_FILES}

clean :
	@rm -f ${SUBSCRIBER_BIN} ${PUBLISHER_BIN} ${OBJECT_FILES} ${OUTPUT_LIB} ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES}
