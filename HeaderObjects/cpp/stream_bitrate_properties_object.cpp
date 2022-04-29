#include "../hpp/stream_bitrate_properties_object.hpp"

std::istream &StreamBitratePropertiesObject::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&bitrateRecordsCount_), sizeof(bitrateRecordsCount_))) {
        throw std::runtime_error("Reading error inside StreamBitratePropertiesObject");
    }
    for (uint16_t i = 0; i < bitrateRecordsCount_; ++i) {
        StreamBitratePropertiesObject::BitrateRecord record{};
        if (!in.read(reinterpret_cast<char *>(&record.flags_), sizeof(record.flags_)) ||
            !in.read(reinterpret_cast<char *>(&record.averageBitrate_),
                     sizeof(record.averageBitrate_))) {
            throw std::runtime_error("Reading error inside StreamBitratePropertiesObject");
        }
        bitrateRecords_.push_back(record);
    }
    return in;
}

std::ostream &StreamBitratePropertiesObject::output(std::ostream &out)
{
    out << "Stream Bitrate Properties Object\n";
    out << "  Bitrate records count: " << bitrateRecordsCount_ << "\n";
    out << "  Bitrate records:";
    for (auto &record : bitrateRecords_) {
        out << "\n    Stream number: " << record.flags_ << ", ";
        out << "average bitrate: " << record.averageBitrate_;
    }
    out << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, StreamBitratePropertiesObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, StreamBitratePropertiesObject &obj)
{
    return obj.output(out);
}
