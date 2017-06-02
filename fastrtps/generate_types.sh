GENERATED_TYPES_HEADER_FILE=Types.h
GENERATED_TYPES_SOURCE_FILE=Types.cxx
IDL_FILES=$(find -type f -name "*.idl")
rm -f ${GENERATED_TYPES_HEADER_FILE} ${GENERATED_TYPES_SOURCE_FILE}
for idl in ${IDL_FILES}
do
	typeName=$(basename ${idl} .idl)
	echo "void *FastRTPSNew${typeName}TopicDataType();" >> ${GENERATED_TYPES_HEADER_FILE}
	echo "#include \"${typeName}PubSubTypes.h\"" >> ${GENERATED_TYPES_SOURCE_FILE}
done
for idl in ${IDL_FILES}
do
	typeName=$(basename ${idl} .idl)
	echo "extern \"C\" void *FastRTPSNew${typeName}TopicDataType() {" >> ${GENERATED_TYPES_SOURCE_FILE}
	echo "	return (void*)new ${typeName}PubSubType();" >> ${GENERATED_TYPES_SOURCE_FILE}
	echo "}" >> ${GENERATED_TYPES_SOURCE_FILE}
done
