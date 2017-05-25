CXX := g++
AR := ar
ARFLAGS := rvs
CXXFLAGS := -I/usr/local/include -L/usr/local/lib -lfastcdr -lfastrtps -std=c++11

IDL_FILES := $(shell find -type f -name "*.idl")
GENERATED_HEADER_FILES := ${IDL_FILES:%.idl=%PubSubTypes.h} ${IDL_FILES:%.idl=%.h} 
GENERATED_SOURCE_FILES := ${IDL_FILES:%.idl=%PubSubTypes.cxx} ${IDL_FILES:%.idl=%.cxx}
SOURCE_FILES := Publisher.cxx PubListener.cxx
OBJECT_FILES := ${GENERATED_SOURCE_FILES:%.cxx=%.o} ${SOURCE_FILES:%.cxx=%.o}
OUTPUT_LIB := lib.a 
PUBLISHER_TEST_BIN := ./publisher_test.out

.PHONY : clean


generate : ${GENERATED_HEADER_FILES} ${GENERATES_SOURCE_FILES}
lib : ${OUTPUT_LIB}
publisher : ${PUBLISHER_BIN}
run : ${PUBLISHER_BIN}
	@${PUBLISHER_BIN}	

${GENERATED_HEADER_FILES} ${GENERAED_SOURCE_FILES} : ${IDL_FILES} 
	@fastrtpsgen -replace ${IDL_FILES}

${OBJECT_FILES} : ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES} ${SOURCE_FILES}
	@${CXX} ${CXXFLAGS} -c ${GENERATED_SOURCE_FILES} ${SOURCE_FILES} 

${OUTPUT_LIB} : ${OBJECT_FILES}
	@${AR} ${ARFLAGS} ${OUTPUT_LIB} ${OBJECT_FILES} 

${PUBLISHER_TEST_BIN} : 
	@CGO_ENABLED=1 go build -o ${PUBLISHER_TEST_BIN} .

clean :
	@rm -f ${PUBLISHER_TEST_BIN} ${GENERATED_SOURCE_FILES} ${GENERATED_HEADER_FILES} ${OBJECT_FILES} ${OUTPUT_LIB}
