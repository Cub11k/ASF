#ifndef ASF__EXTENDED_CONTENT_ENCRYPTION_OBJECT_HPP_
#define ASF__EXTENDED_CONTENT_ENCRYPTION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class ExtendedContentEncryptionObject : public Object {
private:
    uint32_t dataSize_{};
    std::vector<uint8_t> data_{};
public:
    ExtendedContentEncryptionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ExtendedContentEncryptionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ExtendedContentEncryptionObject &obj);
std::ostream &operator<<(std::ostream &out, ExtendedContentEncryptionObject &obj);

#endif //ASF__EXTENDED_CONTENT_ENCRYPTION_OBJECT_HPP_
