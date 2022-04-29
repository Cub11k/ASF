#ifndef ASF__CONTENT_ENCRYPTION_OBJECT_HPP_
#define ASF__CONTENT_ENCRYPTION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class ContentEncryptionObject : public Object {
private:
    uint32_t secretDataLength_{};
    std::vector<uint8_t> secretData_{};
    uint32_t protectionTypeLength_{};
    std::vector<uint8_t> protectionType_{};
    uint32_t keyIDLength_{};
    std::vector<uint8_t> keyID_{};
    uint32_t licenseURLLength_{};
    std::vector<uint8_t> licenseURL_{};
public:
    ContentEncryptionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ContentEncryptionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ContentEncryptionObject &obj);
std::ostream &operator<<(std::ostream &out, ContentEncryptionObject &obj);

#endif //ASF__CONTENT_ENCRYPTION_OBJECT_HPP_
