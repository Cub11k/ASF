#ifndef ASF__CONTENT_DESCRIPTION_OBJECT_HPP_
#define ASF__CONTENT_DESCRIPTION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class ContentDescriptionObject : public Object {
private:
    uint16_t titleLength_{};
    uint16_t authorLength_{};
    uint16_t copyrightLength_{};
    uint16_t descriptionLength_{};
    uint16_t ratingLength_{};
    std::vector<uint8_t> title_{};
    std::vector<uint8_t> author_{};
    std::vector<uint8_t> copyright_{};
    std::vector<uint8_t> description_{};
    std::vector<uint8_t> rating_{};
public:
    ContentDescriptionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ContentDescriptionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ContentDescriptionObject &obj);
std::ostream &operator<<(std::ostream &out, ContentDescriptionObject &obj);

#endif //ASF__CONTENT_DESCRIPTION_OBJECT_HPP_
