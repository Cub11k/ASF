#ifndef ASF__HEADER_OBJECT_HPP_
#define ASF__HEADER_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class HeaderObject : public Object {
private:
    enum Defaults {
        OBJECT_NUMBER = 3,
        RESERVED_1 = 0x01,
        RESERVED_2 = 0x02
    };
    uint32_t objNum_ = OBJECT_NUMBER;
    uint8_t reserved1_ = RESERVED_1;
    uint8_t reserved2_ = RESERVED_2;
public:
    HeaderObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~HeaderObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, HeaderObject &obj);
std::ostream &operator<<(std::ostream &out, HeaderObject &obj);

#endif //ASF__HEADER_OBJECT_HPP_
