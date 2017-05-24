CXX := g++
AR := ar
ARFLAGS := rvs
CXXFLAGS := -I/usr/local/include -L/usr/local/lib -lfastcdr -lfastrtps -std=c++11

IDL_FILES := $(shell find -type f -name "*.idl")
HEADER_FILES := ${IDL_FILES:%.idl=%PubSubTypes.h} ${IDL_FILES:%.idl=%.h} 
SOURCE_FILES := ${IDL_FILES:%.idl=%PubSubTypes.cxx} ${IDL_FILES:%.idl=%.cxx}
SOURCE_AND_HEADER_FILES := ${SOURCE_FILES} ${HEADER_FILES}
OBJECT_FILES := ${SOURCE_FILES:%.cxx=%.o}
OUTPUT_LIB := lib.a 

.PHONY : clean

build : ${OUTPUT_LIB}

${SOURCE_AND_HEADER_FILES} : ${IDL_FILES} 
	@fastrtpsgen -replace ${IDL_FILES}

${OBJECT_FILES} : ${SOURCE_AND_HEADER_FILES}
	@${CXX} ${CXXFLAGS} -c ${SOURCE_FILES} 

${OUTPUT_LIB} : ${OBJECT_FILES}
	@${AR} ${ARFLAGS} ${OUTPUT_LIB} ${OBJECT_FILES} 
	@rm -f ${SOURCE_FILES} ${OBJECT_FILES}

clean :
	@rm -f ${SOURCE_AND_HEADER_FILES} ${OBJECT_FILES} ${OUTPUT_LIB}
