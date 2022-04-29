#include "error_correction_object.hpp"

std::istream &ErrorCorrectionObject::input(std::istream &in)
{
    if (!(in >> errorCorrectionType_) ||
        !in.read(reinterpret_cast<char *>(&errorCorrectionDataLength_), sizeof(errorCorrectionDataLength_))) {
        throw std::runtime_error("Reading error inside ErrorCorrectionObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < errorCorrectionDataLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside ErrorCorrectionObject");
        }
    }
    return in;
}

std::ostream &ErrorCorrectionObject::output(std::ostream &out)
{
    out << "Error Correction Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ErrorCorrectionObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, ErrorCorrectionObject &obj)
{
    return obj.output(out);
}
