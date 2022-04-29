#include "content_description_object.hpp"

std::istream &ContentDescriptionObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&titleLength_), sizeof(titleLength_)) ||
        !in.read(reinterpret_cast<char *>(&authorLength_), sizeof(authorLength_)) ||
        !in.read(reinterpret_cast<char *>(&copyrightLength_), sizeof(copyrightLength_)) ||
        !in.read(reinterpret_cast<char *>(&descriptionLength_), sizeof(descriptionLength_)) ||
        !in.read(reinterpret_cast<char *>(&ratingLength_), sizeof(ratingLength_))) {
        throw std::runtime_error("Reading error inside ContentDescriptionObject");
    }
    uint8_t x{};
    for (uint16_t i = 0; i < titleLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentDescriptionObject");
        }
        title_.push_back(x);
    }
    for (uint16_t i = 0; i < authorLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentDescriptionObject");
        }
        author_.push_back(x);
    }
    for (uint16_t i = 0; i < copyrightLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentDescriptionObject");
        }
        copyright_.push_back(x);
    }
    for (uint16_t i = 0; i < descriptionLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentDescriptionObject");
        }
        description_.push_back(x);
    }
    for (uint16_t i = 0; i < ratingLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentDescriptionObject");
        }
        rating_.push_back(x);
    }
    return in;
}

std::ostream &ContentDescriptionObject::output(std::ostream &out)
{
    out << "Content Description Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ContentDescriptionObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, ContentDescriptionObject &obj)
{
    return obj.output(out);
}