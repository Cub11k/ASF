#include "digital_signature_object.hpp"

std::istream &DigitalSignatureObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&signatureType_), sizeof(signatureType_)) ||
        !in.read(reinterpret_cast<char *>(&signatureDataLength_), sizeof(signatureDataLength_))) {
        throw std::runtime_error("Reading error inside DigitalSignatureObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < signatureDataLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside DigitalSignatureObject");
        }
        signatureData_.push_back(x);
    }
    return in;
}

std::ostream &DigitalSignatureObject::output(std::ostream &out)
{
    out << "Digital Signature Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, DigitalSignatureObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, DigitalSignatureObject &obj)
{
    return obj.output(out);
}