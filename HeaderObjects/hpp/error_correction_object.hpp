#ifndef ASF__ERROR_CORRECTION_OBJECT_HPP_
#define ASF__ERROR_CORRECTION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class ErrorCorrectionObject : public Object {
private:
    ObjectGuid errorCorrectionType_{};
    uint32_t errorCorrectionDataLength_{};
    // just read, do not store errorCorrectionData(errorCorrectionDataLength_)
public:
    ErrorCorrectionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ErrorCorrectionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ErrorCorrectionObject &obj);
std::ostream &operator<<(std::ostream &out, ErrorCorrectionObject &obj);

#endif //ASF__ERROR_CORRECTION_OBJECT_HPP_
