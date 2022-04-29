#include "../hpp/bitrate_mutual_exclusion_object.hpp"

std::istream &BitrateMutualExclusionObject::input(std::istream &in)
{
    if (!(in >> exclusionType_) ||
        !in.read(reinterpret_cast<char *>(&(streamNumbersCount_)), sizeof(streamNumbersCount_))) {
        throw std::runtime_error("Reading error inside BitrateMutualExclusionObject");
    }
    for (uint16_t i = 0; i < streamNumbersCount_; ++i) {
        uint16_t x{};
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside BitrateMutualExclusionObject");
        }
        streamNumbers_.push_back(x);
    }
    return in;
}

std::ostream &BitrateMutualExclusionObject::output(std::ostream &out)
{
    out << "Bitrate Mutual Exclusion Object\n";
    out << "  Stream numbers count: " << streamNumbersCount_ << "\n";
    out << "  Stream numbers:";
    for (auto &x : streamNumbers_) {
        out << "\n    " << x;
    }
    out << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, BitrateMutualExclusionObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, BitrateMutualExclusionObject &obj)
{
    return obj.output(out);
}