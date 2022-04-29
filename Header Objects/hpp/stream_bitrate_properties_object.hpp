#ifndef ASF__STREAM_BITRATE_PROPERTIES_OBJECT_HPP_
#define ASF__STREAM_BITRATE_PROPERTIES_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class StreamBitratePropertiesObject : public Object
{
private:
    uint16_t bitrateRecordsCount_{};
    class BitrateRecord
    {
    public:
        uint16_t flags_{};
        uint32_t averageBitrate_{};
    };
    std::vector<BitrateRecord> bitrateRecords_{};
public:
    StreamBitratePropertiesObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~StreamBitratePropertiesObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, StreamBitratePropertiesObject &obj);
std::ostream &operator<<(std::ostream &out, StreamBitratePropertiesObject &obj);

#endif //ASF__STREAM_BITRATE_PROPERTIES_OBJECT_HPP_
