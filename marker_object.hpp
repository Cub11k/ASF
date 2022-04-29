#ifndef ASF__MARKER_OBJECT_HPP_
#define ASF__MARKER_OBJECT_HPP_

#include "object.hpp"

class MarkerObject : public Object
{
private:
    ObjectGuid reserved_;
    uint32_t markersCount_{};
    uint16_t reserved2_;
    uint32_t nameLength_{};
    std::vector<uint8_t> name_;
    class Marker
    {
    public:
        uint64_t offset_{};
        uint64_t presentationTime_{};
        uint16_t entryLength_{};
        uint32_t sendTime_{};
        uint32_t flags_{};
        uint32_t markerDescriptionLength_{};
        std::vector<uint8_t> markerDescription_{};
    };
    std::vector<Marker> markers_{};
public:
    MarkerObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~MarkerObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, MarkerObject &obj);
std::ostream &operator<<(std::ostream &out, MarkerObject &obj);

#endif //ASF__MARKER_OBJECT_HPP_
