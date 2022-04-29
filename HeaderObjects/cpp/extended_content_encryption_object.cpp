#include "../hpp/extended_content_encryption_object.hpp"

std::istream &ExtendedContentEncryptionObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&dataSize_), sizeof(dataSize_))) {
        throw std::runtime_error("Reading error inside ExtendedContentEncryptionObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < dataSize_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ExtendedContentEncryptionObject");
        }
        data_.push_back(x);
    }
    return in;
}

std::ostream &ExtendedContentEncryptionObject::output(std::ostream &out)
{
    out << "Extended Content Encryption Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ExtendedContentEncryptionObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, ExtendedContentEncryptionObject &obj)
{
    return obj.output(out);
}