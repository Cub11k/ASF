#ifndef ASF__PADDING_OBJECT_HPP_
#define ASF__PADDING_OBJECT_HPP_

#include "object.hpp"

class PaddingObject : public Object
{
private:
    std::vector<uint8_t> paddingData_{};
public:
    PaddingObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~PaddingObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, PaddingObject &obj);
std::ostream &operator<<(std::ostream &out, PaddingObject &obj);

#endif //ASF__PADDING_OBJECT_HPP_
