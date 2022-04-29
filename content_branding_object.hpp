#ifndef ASF__CONTENT_BRANDING_OBJECT_HPP_
#define ASF__CONTENT_BRANDING_OBJECT_HPP_

#include "object.hpp"

class ContentBrandingObject : public Object
{
private:
    uint32_t bannerImageType_{};
    uint32_t bannerImageDataSize_{};
    std::vector<uint8_t> bannerImageData_{};
    uint32_t bannerImageURLLength_{};
    std::vector<uint8_t> bannerImageURL_{};
    uint32_t copyrightURLLength_{};
    std::vector<uint8_t> copyrightURL_{};
public:
    ContentBrandingObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ContentBrandingObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ContentBrandingObject &obj);
std::ostream &operator<<(std::ostream &out, ContentBrandingObject &obj);

#endif //ASF__CONTENT_BRANDING_OBJECT_HPP_
