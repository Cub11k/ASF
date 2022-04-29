#ifndef ASF__Object_HPP_
#define ASF__Object_HPP_

#include "object_guid.hpp"
#include <memory>

class Object {
private:
    enum ObjectType {
        ASF_UNKNOWN_OBJECT,
        ASF_HEADER_OBJECT,
        ASF_DATA_OBJECT,
        ASF_SIMPLE_INDEX_OBJECT,
        ASF_INDEX_OBJECT,
        ASF_MEDIA_OBJECT_INDEX_OBJECT,
        ASF_TIMECODE_INDEX_OBJECT,
        ASF_FILE_PROPERTIES_OBJECT,
        ASF_STREAM_PROPERTIES_OBJECT,
        ASF_HEADER_EXTENSION_OBJECT,
        ASF_CODEC_LIST_OBJECT,
        ASF_SCRIPT_COMMAND_OBJECT,
        ASF_MARKER_OBJECT,
        ASF_BITRATE_MUTUAL_EXCLUSION_OBJECT,
        ASF_ERROR_CORRECTION_OBJECT,
        ASF_CONTENT_DESCRIPTION_OBJECT,
        ASF_EXTENDED_CONTENT_DESCRIPTION_OBJECT,
        ASF_CONTENT_BRANDING_OBJECT,
        ASF_STREAM_BITRATE_PROPERTIES_OBJECT,
        ASF_CONTENT_ENCRYPTION_OBJECT,
        ASF_EXTENDED_CONTENT_ENCRYPTION_OBJECT,
        ASF_DIGITAL_SIGNATURE_OBJECT,
        ASF_PADDING_OBJECT,
        ASF_EXTENDED_STREAM_PROPERTIES_OBJECT,
        ASF_ADVANCED_MUTUAL_EXCLUSION_OBJECT,
        ASF_GROUP_MUTUAL_EXCLUSION_OBJECT,
        ASF_STREAM_PRIORITIZATION_OBJECT,
        ASF_BANDWIDTH_SHARING_OBJECT,
        ASF_LANGUAGE_LIST_OBJECT,
        ASF_METADATA_OBJECT,
        ASF_METADATA_LIBRARY_OBJECT,
        ASF_INDEX_PARAMETERS_OBJECT,
        ASF_MEDIA_OBJECT_INDEX_PARAMETERS_OBJECT,
        ASF_TIMECODE_INDEX_PARAMETERS_OBJECT,
        ASF_COMPATIBILITY_OBJECT,
        ASF_ADVANCED_CONTENT_ENCRYPTION_OBJECT
    };
protected:
    ObjectGuid guid_;
    uint64_t size_;
    ObjectType type_;
public:
    Object(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0);

    virtual ~Object() = default;

    virtual std::istream &input(std::istream &in);
    virtual std::ostream &output(std::ostream &out);
    friend std::unique_ptr<Object> ObjectFactory(const Object &obj);
};

std::istream &operator>>(std::istream &in, Object &obj);
std::ostream &operator<<(std::ostream &out, Object &obj);

#endif //ASF__Object_HPP_
