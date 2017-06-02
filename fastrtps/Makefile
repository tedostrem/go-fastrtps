VERSION := 1.0
DEB := gofastrtps_${VERSION}_armhf.deb

ARTIFACTS_DIR := artifacts
INSTALL_DIR := ${ARTIFACTS_DIR}/usr
INSTALL_LIB_DIR := ${INSTALL_DIR}/lib
INSTALL_INCLUDE_DIR := ${INSTALL_DIR}/include/gofastrtps

CXXFLAGS := -c -Wall -Werror -fpic -I/usr/local/include -L/usr/local/lib -lfastcdr -lfastrtps -std=c++11

IDL_FILES := $(shell find -type f -name "*.idl")
GENERATED_HEADER_FILES := ${IDL_FILES:%.idl=%PubSubTypes.h} ${IDL_FILES:%.idl=%.h}
GENERATED_SOURCE_FILES := ${IDL_FILES:%.idl=%PubSubTypes.cxx} ${IDL_FILES:%.idl=%.cxx}
GENERATED_TYPES_HEADER_FILE := Types.h
GENERATED_TYPES_SOURCE_FILE := Types.cxx

HEADER_FILES := \
	FastRTPS.h

SOURCE_FILES := \
	FastRTPS.cxx \

OBJECT_FILES := ${SOURCE_FILES:%.cxx=%.o} ${GENERATED_SOURCE_FILES:%.cxx=%.o} ${GENERATED_TYPES_SOURCE_FILE:%.cxx=%.o}
OUTPUT_LIB := libgofastrtps.so
PUBLISHER_BIN := ./publisher.out
SUBSCRIBER_BIN := ./subscriber.out

.PHONY : clean

deb : ${DEB}
lib : ${OUTPUT_LIB}
generate : ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES}

${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES} : ${IDL_FILES}
	@fastrtpsgen -replace ${IDL_FILES}

${GENERATED_TYPES_HEADER_FILE} ${GENERATED_TYPES_SOURCE_FILE} : ${IDL_FILES}
	@./generate_types.sh

${OBJECT_FILES} : ${SOURCE_FILES} ${GENERATED_SOURCE_FILES} ${GENERATED_TYPES_HEADER_FILE} ${GENERATED_TYPES_SOURCE_FILE}
	@${CXX} ${CXXFLAGS} -c ${SOURCE_FILES} ${GENERATED_SOURCE_FILES} ${GENERATED_TYPES_SOURCE_FILE}

${OUTPUT_LIB} : ${OBJECT_FILES}
	@${CXX} -shared -o ${OUTPUT_LIB} ${OBJECT_FILES}

install : ${INSTALL_LIB_DIR}/${OUTPUT_LIB}

${INSTALL_LIB_DIR}/${OUTPUT_LIB} : ${OUTPUT_LIB}
	mkdir -p ${INSTALL_LIB_DIR} ${INSTALL_INCLUDE_DIR}
	cp -f ${OUTPUT_LIB} ${INSTALL_LIB_DIR}
	cp -f ${HEADER_FILES} ${GENERATED_HEADER_FILES} ${GENERATED_TYPES_HEADER_FILE} ${INSTALL_INCLUDE_DIR}

clean :
	@rm -rf ${SUBSCRIBER_BIN} ${PUBLISHER_BIN} ${OBJECT_FILES} ${OUTPUT_LIB} ${GENERATED_HEADER_FILES} ${GENERATED_SOURCE_FILES} ${GENERATED_TYPES_HEADER_FILE} ${GENERATED_TYPES_SOURCE_FILE} ${ARTIFACTS_DIR}

arm :
	docker build -t tedostrem/gofastrtps-builder .
	docker run -it --rm \
		-v $(shell pwd):/build \
		-e VERSION=$(shell git describe --tags --long) \
		-e HOST_USER=$(shell id -u) \
		-e HOST_GROUP=$(shell id -g) \
		tedostrem/gofastrtps-builder \
		/bin/sh -c "cd /build && make deb"

${DEB} : ${INSTALL_LIB_DIR}/${OUTPUT_LIB}
	fpm -a armhf -f -s dir -t deb --deb-no-default-config-files -C artifacts --name gofastrtps --version ${VERSION} --iteration 1 --description "gofastrtps" .
	sudo chown -R ${HOST_USER}:${HOST_GROUP} .
