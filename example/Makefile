PUBLISHER_BIN := ./publisher.out
SUBSCRIBER_BIN := ./subscriber.out

.PHONY : clean

publisher : ${PUBLISHER_BIN}
subscriber : ${SUBSCRIBER_BIN}

${PUBLISHER_BIN} : 
	@CGO_ENABLED=1 go build -tags 'publisher' -o ${PUBLISHER_BIN} . 

${SUBSCRIBER_BIN} : 
	@CGO_ENABLED=1 go build -tags 'subscriber' -o ${SUBSCRIBER_BIN} . 

clean :
	@rm -f ${SUBSCRIBER_BIN} ${PUBLISHER_BIN}
