#ifndef ASF__EXTENDED_CONTENT_DESCRIPTION_OBJECT_HPP_
#define ASF__EXTENDED_CONTENT_DESCRIPTION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class ExtendedContentDescriptionObject : public Object
{
private:
    uint16_t contentDescriptorsCount_{};
    class ContentDescriptor
    {
    public:
        uint16_t descriptorNameLength_{};
        std::vector<uint8_t> descriptorName_{};
        uint16_t descriptorValueDataType_{};
        uint16_t descriptorValueLength_{};
        std::vector<uint8_t> descriptorValue_{};
    };
    std::vector<ContentDescriptor> contentDescriptors_{};
public:
    ExtendedContentDescriptionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ExtendedContentDescriptionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ExtendedContentDescriptionObject &obj);
std::ostream &operator<<(std::ostream &out, ExtendedContentDescriptionObject &obj);

#endif //ASF__EXTENDED_CONTENT_DESCRIPTION_OBJECT_HPP_
