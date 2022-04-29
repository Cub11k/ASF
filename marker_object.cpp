#include "marker_object.hpp"

std::istream &MarkerObject::input(std::istream &in)
{
    if (!(in >> reserved_) ||
        !in.read(reinterpret_cast<char *>(&markersCount_), sizeof(markersCount_)) ||
        !in.read(reinterpret_cast<char *>(&reserved2_), sizeof(reserved2_)) ||
        !in.read(reinterpret_cast<char *>(&nameLength_), sizeof(nameLength_))) {
        throw std::runtime_error("Reading error inside MarkerObject");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < nameLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside MarkerObject");
        }
        name_.push_back(x);
    }
    for (uint32_t i = 0; i < markersCount_; ++i) {
        MarkerObject::Marker marker{};
        if (!in.read(reinterpret_cast<char *>(&marker.offset_), sizeof(marker.offset_)) ||
            !in.read(reinterpret_cast<char *>(&marker.presentationTime_),
                     sizeof(marker.presentationTime_)) ||
            !in.read(reinterpret_cast<char *>(&marker.entryLength_), sizeof(marker.entryLength_)) ||
            !in.read(reinterpret_cast<char *>(&marker.sendTime_), sizeof(marker.sendTime_)) ||
            !in.read(reinterpret_cast<char *>(&marker.flags_), sizeof(marker.flags_)) ||
            !in.read(reinterpret_cast<char *>(&marker.markerDescriptionLength_),
                     sizeof(marker.markerDescriptionLength_))) {
            throw std::runtime_error("Reading error inside MarkerObject");
        }
        for (long long unsigned int j = 0; j < marker.markerDescriptionLength_ * sizeof(wchar_t); ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside MarkerObject");
            }
            marker.markerDescription_.push_back(x);
        }
        markers_.push_back(marker);
    }
    return in;
}

std::ostream &MarkerObject::output(std::ostream &out)
{
    out << "Marker Object\n";
    out << "  Markers count: " << markersCount_ << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, MarkerObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, MarkerObject &obj)
{
    return obj.output(out);
}