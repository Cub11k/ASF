#ifndef ASF__BITRATE_MUTUAL_EXCLUSION_OBJECT_HPP_
#define ASF__BITRATE_MUTUAL_EXCLUSION_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class BitrateMutualExclusionObject : public Object
{
private:
    ObjectGuid exclusionType_{};
    uint16_t streamNumbersCount_{};
    std::vector<uint16_t> streamNumbers_{};
public:
    BitrateMutualExclusionObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~BitrateMutualExclusionObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, BitrateMutualExclusionObject &obj);
std::ostream &operator<<(std::ostream &out, BitrateMutualExclusionObject &obj);

#endif //ASF__BITRATE_MUTUAL_EXCLUSION_OBJECT_HPP_
