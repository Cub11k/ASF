#include "hpp/content_branding_object.hpp"

std::istream &ContentBrandingObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&bannerImageType_), sizeof(bannerImageType_)) ||
        !in.read(reinterpret_cast<char *>(&bannerImageDataSize_), sizeof(bannerImageDataSize_))) {
        throw std::runtime_error("Reading error inside ContentBrandingObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < bannerImageDataSize_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentBrandingObject");
        }
        bannerImageData_.push_back(x);
    }
    if (!in.read(reinterpret_cast<char *>(&bannerImageURLLength_),
                 sizeof(bannerImageURLLength_))) {
        throw std::runtime_error("Reading error inside ContentBrandingObject");
    }
    for (uint32_t i = 0; i < bannerImageURLLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentBrandingObject");
        }
        bannerImageURL_.push_back(x);
    }
    if (!in.read(reinterpret_cast<char *>(&copyrightURLLength_), sizeof(copyrightURLLength_))) {
        throw std::runtime_error("Reading error inside ContentBrandingObject");
    }
    for (uint32_t i = 0; i < copyrightURLLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ContentBrandingObject");
        }
        copyrightURL_.push_back(x);
    }
    return in;
}

std::ostream &ContentBrandingObject::output(std::ostream &out)
{
    out << "Content Branding Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ContentBrandingObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, ContentBrandingObject &obj)
{
    return obj.output(out);
}