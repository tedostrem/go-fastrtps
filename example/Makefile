PUBLISHER_BIN := ./publisher.out
SUBSCRIBER_BIN := ./subscriber.out

IDL_FILES := $(shell find -type f -name "*.idl")
GENERATED_HEADER_FILES := ${IDL_FILES:%.idl=%PubSubTypes.h} ${IDL_FILES:%.idl=%.h}
GENERATED_SOURCE_FILES := ${IDL_FILES:%.idl=%PubSubTypes.cxx} ${IDL_FILES:%.idl=%.cxx}

.PHONY : clean

generate : ${GENERATED_HEADER_FILES} ${GENERATES_SOURCE_FILES}
publisher : ${PUBLISHER_BIN}
subscriber : ${SUBSCRIBER_BIN}

${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES} : ${IDL_FILES}
	@fastrtpsgen -replace ${IDL_FILES}

${PUBLISHER_BIN} : ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES}
	CGO_ENABLED=1 go build -tags 'publisher' -o ${PUBLISHER_BIN} .

${SUBSCRIBER_BIN} : ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES}
	CGO_ENABLED=1 go build -tags 'subscriber' -o ${SUBSCRIBER_BIN} .

clean :
	@rm -f ${SUBSCRIBER_BIN} ${PUBLISHER_BIN} ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES}
