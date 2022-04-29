#include "extended_content_description_object.hpp"

std::istream &ExtendedContentDescriptionObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&contentDescriptorsCount_),
                 sizeof(contentDescriptorsCount_))) {
        throw std::runtime_error("Reading error inside ExtendedContentDescriptionObject");
    }
    for (uint16_t i = 0; i < contentDescriptorsCount_; ++i) {
        ExtendedContentDescriptionObject::ContentDescriptor descriptor{};
        uint8_t x{};
        if (!in.read(reinterpret_cast<char *>(&descriptor.descriptorNameLength_),
                     sizeof(descriptor.descriptorNameLength_))) {
            throw std::runtime_error("Reading error inside ExtendedContentDescriptionObject");
        }
        for (uint16_t j = 0; j < descriptor.descriptorNameLength_; ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside ExtendedContentDescriptionObject");
            }
            descriptor.descriptorName_.push_back(x);
        }
        if (!in.read(reinterpret_cast<char *>(&descriptor.descriptorValueDataType_),
                     sizeof(descriptor.descriptorValueDataType_)) ||
            !in.read(reinterpret_cast<char *>(&descriptor.descriptorValueLength_),
                     sizeof(descriptor.descriptorValueLength_))) {
            throw std::runtime_error("Reading error inside ExtendedContentDescriptionObject");
        }
        for (uint16_t j = 0; j < descriptor.descriptorValueLength_; ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside ExtendedContentDescriptionObject");
            }
            descriptor.descriptorValue_.push_back(x);
        }
        contentDescriptors_.push_back(descriptor);
    }
    return in;
}

std::ostream &ExtendedContentDescriptionObject::output(std::ostream &out)
{
    out << "Extended Content Description Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ExtendedContentDescriptionObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, ExtendedContentDescriptionObject &obj)
{
    return obj.output(out);
}