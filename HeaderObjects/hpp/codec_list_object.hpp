#ifndef ASF__CODEC_LIST_OBJECT_HPP_
#define ASF__CODEC_LIST_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class CodecListObject : public Object {
private:
    ObjectGuid reserved_{};
    uint32_t codecEntriesCount_{};
    class CodecEntry {
    public:
        uint16_t type_{};
        uint16_t codecNameLength_{};
        std::vector<uint8_t> codecName_{};
        uint16_t codecDescriptionLength_{};
        std::vector<uint8_t> codecDescription_{};
        uint16_t codecInformationLength_{};
        std::vector<uint8_t> codecInformation_{};
    };
    std::vector<CodecEntry> codecEntries_{};
public:
    CodecListObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~CodecListObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, CodecListObject &obj);
std::ostream &operator<<(std::ostream &out, CodecListObject &obj);

#endif //ASF__CODEC_LIST_OBJECT_HPP_
