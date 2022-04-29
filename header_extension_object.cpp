#include "header_extension_object.hpp"

std::istream &HeaderExtensionObject::input(std::istream &in)
{
    if (!(in >> reserved1_) ||
        !in.read(reinterpret_cast<char *>(&reserved2_), sizeof(reserved2_)) ||
        !in.read(reinterpret_cast<char *>(&headerExtensionDataSize_),
                 sizeof(headerExtensionDataSize_))) {
        throw std::runtime_error("Reading error inside HeaderExtensionObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < headerExtensionDataSize_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside HeaderExtensionObject");
        }
    }
    return in;
}

std::ostream &HeaderExtensionObject::output(std::ostream &out)
{
    out << "Header Extension Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, HeaderExtensionObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, HeaderExtensionObject &obj)
{
    return obj.output(out);
}