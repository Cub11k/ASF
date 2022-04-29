#include "../hpp/object_guid.hpp"

ObjectGuid &ObjectGuid::operator=(const ObjectGuid &obj)
{
    if (this == &obj) {
        return *this;
    }
    this->v1 = obj.v1;
    this->v2 = obj.v2;
    this->v3 = obj.v3;
    this->v4 = obj.v4;
    this->type_ = obj.type_;
    return *this;
}

bool ObjectGuid::operator==(const ObjectGuid &obj) const
{
    return (this->v1 == obj.v1
        && this->v2 == obj.v2
        && this->v3 == obj.v3
        && this->v4 == obj.v4
        && this->type_ == obj.type_);
}

bool ObjectGuid::operator==(const asf_guid_t &obj) const
{
    return (this->v1 == obj.v1
        && this->v2 == obj.v2
        && this->v3 == obj.v3
        && this->v4 == obj.v4);
}

std::istream &ObjectGuid::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&(v1)), sizeof(v1)) ||
        !in.read(reinterpret_cast<char *>(&(v2)), sizeof(v2)) ||
        !in.read(reinterpret_cast<char *>(&(v3)), sizeof(v3))) {
        if (in.eof()) {
            return in;
        }
        throw std::runtime_error("Reading error inside ObjectGuid");
    }
    for (auto &i : v4) {
        if (!(in.read(reinterpret_cast<char *>(&i), sizeof(i)))) {
            throw std::runtime_error("Reading error inside ObjectGuid");
        }
    }
    for (auto &i : VALID_OBJECT_GUIDS) {
        if (*this == i) {
            type_ = ObjectGuid::OBJECT;
            return in;
        }
    }
    type_ = ObjectGuid::ID;
    return in;
}

std::istream &operator>>(std::istream &in, ObjectGuid &obj)
{
    return obj.input(in);
}
