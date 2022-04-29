#ifndef ASF__FILE_PROPERTIES_OBJECT_HPP_
#define ASF__FILE_PROPERTIES_OBJECT_HPP_

#include <ctime>
#include "../../Object/hpp/object.hpp"

class FilePropertiesObject : public Object {
private:
    ObjectGuid fileGuid_{};
    uint64_t fileSize_{};
    uint64_t creationDate_{};
    uint64_t dataPacketsCount_{};
    uint64_t playDuration_{};
    uint64_t sendDuration_{};
    uint64_t preroll_{};
    uint32_t flags_{};
    uint32_t minDataPacketSize_{};
    uint32_t maxDataPacketSize_{};
    uint32_t maxBitrate_{};
public:
    FilePropertiesObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~FilePropertiesObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, FilePropertiesObject &obj);
std::ostream &operator<<(std::ostream &out, FilePropertiesObject &obj);

#endif //ASF__FILE_PROPERTIES_OBJECT_HPP_
