#include "object.hpp"

Object::Object(const ObjectGuid &guid, uint64_t size)
    : guid_(guid), size_(size)
{
    if (!guid.isObject()) {
        throw std::runtime_error("Couldn't create object with non-object GUID");
    }
    auto const_guids = guid_.getValidGuids();
    for (size_t i = 0; i < const_guids.size(); ++i) {
        if (guid_ == const_guids[i]) {
            type_ = static_cast<ObjectType>(i);
            return;
        }
    }
    guid_ = ObjectGuid();
    type_ = ASF_UNKNOWN_OBJECT;
    size_ = 0;
}

std::istream &Object::input(std::istream &in)
{
    if (!(in >> guid_) ||
        !in.read(reinterpret_cast<char *>(&(size_)), sizeof(size_))) {
        if (in.eof()) {
            return in;
        }
        throw std::runtime_error("Reading error inside Object");
    }
    auto const_guids = guid_.getValidGuids();
    for (size_t i = 0; i < const_guids.size(); ++i) {
        if (guid_ == const_guids[i]) {
            type_ = static_cast<Object::ObjectType>(i);
            return in;
        }
    }
    uint8_t x{};
    for (uint64_t i = 0; i < size_ - 24; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside Object");
        }
    }
    guid_ = ObjectGuid();
    type_ = Object::ASF_UNKNOWN_OBJECT;
    size_ = 0;
    return in;
}

std::ostream &Object::output(std::ostream &out)
{
    out << "Output of this object is not implemented yet" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Object &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, Object &obj)
{
    return obj.output(out);
}