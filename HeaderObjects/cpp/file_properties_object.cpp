#include "../hpp/file_properties_object.hpp"

std::istream &FilePropertiesObject::input(std::istream &in)
{
    if (!(in >> fileGuid_) ||
        !in.read(reinterpret_cast<char *>(&fileSize_), sizeof(fileSize_)) ||
        !in.read(reinterpret_cast<char *>(&creationDate_), sizeof(creationDate_)) ||
        !in.read(reinterpret_cast<char *>(&dataPacketsCount_), sizeof(dataPacketsCount_)) ||
        !in.read(reinterpret_cast<char *>(&playDuration_), sizeof(playDuration_)) ||
        !in.read(reinterpret_cast<char *>(&sendDuration_), sizeof(sendDuration_)) ||
        !in.read(reinterpret_cast<char *>(&preroll_), sizeof(preroll_)) ||
        !in.read(reinterpret_cast<char *>(&flags_), sizeof(flags_)) ||
        !in.read(reinterpret_cast<char *>(&minDataPacketSize_), sizeof(minDataPacketSize_)) ||
        !in.read(reinterpret_cast<char *>(&maxDataPacketSize_), sizeof(maxDataPacketSize_)) ||
        !in.read(reinterpret_cast<char *>(&maxBitrate_), sizeof(maxBitrate_))) {
        throw std::runtime_error("Reading error inside FilePropertiesObject");
    }
    return in;
}

std::ostream &FilePropertiesObject::output(std::ostream &out)
{
    out << "File Properties Object\n";
    out << "  File size: " << static_cast<double>(fileSize_) / 1024 << " Kb\n";
    time_t posix_time = creationDate_ / 10000000 - 11644473600;
    out << "  Creation date: " << ctime(&posix_time);
    out << "  Play duration in seconds: "
        << static_cast<double>(playDuration_) / 10000000 - static_cast<double>(preroll_) / 1000 << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, FilePropertiesObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, FilePropertiesObject &obj)
{
    return obj.output(out);
}