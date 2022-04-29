#include "../hpp/padding_object.hpp"

std::istream &PaddingObject::input(std::istream &in)
{
    uint8_t x{};
    for (uint64_t i = 0; i < size_ - 24; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside PaddingObject");
        }
        paddingData_.push_back(x);
    }
    return in;
}

std::ostream &PaddingObject::output(std::ostream &out)
{
    out << "Padding Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, PaddingObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, PaddingObject &obj)
{
    return obj.output(out);
}