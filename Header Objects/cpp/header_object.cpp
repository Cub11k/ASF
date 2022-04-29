#include "hpp/header_object.hpp"

std::istream &HeaderObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&objNum_), sizeof(objNum_)) ||
        !in.read(reinterpret_cast<char *>(&reserved1_), sizeof(reserved1_)) ||
        !in.read(reinterpret_cast<char *>(&reserved2_), sizeof(reserved2_))) {
        throw std::runtime_error("Reading error inside HeaderObject");
    }
    return in;
}

std::ostream &HeaderObject::output(std::ostream &out)
{
    out << "Header Object\n";
    out << "  Objects number: " << objNum_ << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, HeaderObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, HeaderObject &obj)
{
    return obj.output(out);
}