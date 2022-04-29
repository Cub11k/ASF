#ifndef ASF__HEADER_EXTENSION_OBJECT_HPP_
#define ASF__HEADER_EXTENSION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class HeaderExtensionObject : public Object
{
private:
    ObjectGuid reserved1_{};
    uint16_t reserved2_{};
    uint32_t headerExtensionDataSize_{};
    // just read, do not store headerExtensionData(headerExtensionDataSize_)
public:
    HeaderExtensionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~HeaderExtensionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, HeaderExtensionObject &obj);
std::ostream &operator<<(std::ostream &out, HeaderExtensionObject &obj);

#endif //ASF__HEADER_EXTENSION_OBJECT_HPP_
