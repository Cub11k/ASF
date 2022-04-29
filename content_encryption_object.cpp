#include "content_encryption_object.hpp"

std::istream &ContentEncryptionObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&secretDataLength_), sizeof(secretDataLength_))) {
        throw std::runtime_error("Reading error inside ContentEncryptionObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < secretDataLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentEncryptionObject");
        }
        secretData_.push_back(x);
    }
    if (!in.read(reinterpret_cast<char *>(&protectionTypeLength_), sizeof(protectionTypeLength_))) {
        throw std::runtime_error("Reading error inside ContentEncryptionObject");
    }
    for (uint32_t i = 0; i < protectionTypeLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentEncryptionObject");
        }
        protectionType_.push_back(x);
    }
    if (!in.read(reinterpret_cast<char *>(&keyIDLength_), sizeof(keyIDLength_))) {
        throw std::runtime_error("Reading error inside ContentEncryptionObject");
    }
    for (uint32_t i = 0; i < keyIDLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentEncryptionObject");
        }
        keyID_.push_back(x);
    }
    if (!in.read(reinterpret_cast<char *>(&licenseURLLength_), sizeof(licenseURLLength_))) {
        throw std::runtime_error("Reading error inside ContentEncryptionObject");
    }
    for (uint32_t i = 0; i < licenseURLLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentEncryptionObject");
        }
        licenseURL_.push_back(x);
    }
    return in;
}

std::ostream &ContentEncryptionObject::output(std::ostream &out)
{
    out << "Content Encryption Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ContentEncryptionObject &obj)
{
    return obj.input(in);
}

std::ostream  &operator<<(std::ostream &out, ContentEncryptionObject &obj)
{
    return obj.output(out);
}