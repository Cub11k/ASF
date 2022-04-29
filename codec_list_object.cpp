#include "codec_list_object.hpp"

std::istream &CodecListObject::input(std::istream &in)
{
    if (!(in >> reserved_) ||
        !in.read(reinterpret_cast<char *>(&codecEntriesCount_),
                 sizeof(codecEntriesCount_))) {
        throw std::runtime_error("Reading error inside CodecListObject");
    }
    for (uint32_t i = 0; i < codecEntriesCount_; ++i) {
        CodecListObject::CodecEntry codec_entry{};
        uint8_t x{};
        if (!in.read(reinterpret_cast<char *>(&codec_entry.type_), sizeof(codec_entry.type_)) ||
            !in.read(reinterpret_cast<char *>(&codec_entry.codecNameLength_),
                     sizeof(codec_entry.codecNameLength_))) {
            throw std::runtime_error("Reading error inside CodecListObject");
        }
        for (long long unsigned int j = 0; j < codec_entry.codecNameLength_ * sizeof(wchar_t); ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside CodecListObject");
            }
            codec_entry.codecName_.push_back(x);
        }
        if (!in.read(reinterpret_cast<char *>(&codec_entry.codecDescriptionLength_),
                     sizeof(codec_entry.codecDescriptionLength_))) {
            throw std::runtime_error("Reading error inside CodecListObject");
        }
        for (long long unsigned int j = 0; j < codec_entry.codecDescriptionLength_ * sizeof(wchar_t); ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside CodecListObject");
            }
            codec_entry.codecDescription_.push_back(x);
        }
        if (!in.read(reinterpret_cast<char *>(&codec_entry.codecInformationLength_),
                     sizeof(codec_entry.codecInformationLength_))) {
            throw std::runtime_error("Reading error inside CodecListObject");
        }
        for (uint16_t j = 0; j < codec_entry.codecInformationLength_; ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside CodecListObject");
            }
            codec_entry.codecInformation_.push_back(x);
        }
        codecEntries_.push_back(codec_entry);
    }
    return in;
}

std::ostream &CodecListObject::output(std::ostream &out)
{
    out << "Codec List Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, CodecListObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, CodecListObject &obj)
{
    return obj.output(out);
}