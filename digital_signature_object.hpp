#ifndef ASF__DIGITAL_SIGNATURE_OBJECT_HPP_
#define ASF__DIGITAL_SIGNATURE_OBJECT_HPP_

#include "object.hpp"

class DigitalSignatureObject : public Object
{
private:
    uint32_t signatureType_{};
    uint32_t signatureDataLength_{};
    std::vector<uint8_t> signatureData_{};
public:
    DigitalSignatureObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~DigitalSignatureObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, DigitalSignatureObject &obj);
std::ostream &operator<<(std::ostream &out, DigitalSignatureObject &obj);

#endif //ASF__DIGITAL_SIGNATURE_OBJECT_HPP_
