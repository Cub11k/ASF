#include "../hpp/stream_properties_object.hpp"

std::istream &MediaData::input(std::istream &in)
{
    return in;
}

std::ostream &MediaData::output(std::ostream &out)
{
    return out;
}

std::istream &AudioData::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&codecID_), sizeof(codecID_)) ||
        !in.read(reinterpret_cast<char *>(&channelsNum_), sizeof(channelsNum_)) ||
        !in.read(reinterpret_cast<char *>(&samplesPerSecond_), sizeof(samplesPerSecond_)) ||
        !in.read(reinterpret_cast<char *>(&avgBytesPerSecondNum_), sizeof(avgBytesPerSecondNum_)) ||
        !in.read(reinterpret_cast<char *>(&blockAlignment_), sizeof(blockAlignment_)) ||
        !in.read(reinterpret_cast<char *>(&bitsPerSample_), sizeof(bitsPerSample_)) ||
        !in.read(reinterpret_cast<char *>(&codecSpecificDataSize_), sizeof(codecSpecificDataSize_))) {
        throw std::runtime_error("Reading error inside AudioData");
    }
    uint8_t x{};
    for (uint16_t i = 0; i < codecSpecificDataSize_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside AudioData");
        }
    }
    return in;
}

std::ostream &AudioData::output(std::ostream &out)
{
    out << "  Audio Data\n";
    out << "    Number of channels: " << channelsNum_ << "\n";
    out << "    Samples per second: " << samplesPerSecond_ << std::endl;
    return out;
}

std::istream &VideoData::input(std::istream &in)
{
    if (!in.read(reinterpret_cast<char *>(&encodedImageWidth_), sizeof(encodedImageWidth_)) ||
        !in.read(reinterpret_cast<char *>(&encodedImageHeight_), sizeof(encodedImageHeight_)) ||
        !in.read(reinterpret_cast<char *>(&reservedFlags_), sizeof(reservedFlags_)) ||
        !in.read(reinterpret_cast<char *>(&formatDataSize_), sizeof(formatDataSize_))) {
        throw std::runtime_error("Reading error inside VideoData");
    }
    if (!in.read(reinterpret_cast<char *>(&formatData_.formatDataSize_), sizeof(formatData_.formatDataSize_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.imageWidth_), sizeof(formatData_.imageWidth_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.imageHeight_), sizeof(formatData_.imageHeight_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.reserved_), sizeof(formatData_.reserved_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.bitsPerPixelCount_), sizeof(formatData_.bitsPerPixelCount_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.compressionID_), sizeof(formatData_.compressionID_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.imageSize_), sizeof(formatData_.imageSize_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.horizontalPixelsPerMeter_),
                 sizeof(formatData_.horizontalPixelsPerMeter_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.verticalPixelsPerMeter_),
                 sizeof(formatData_.verticalPixelsPerMeter_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.colorsUsedCount_), sizeof(formatData_.colorsUsedCount_)) ||
        !in.read(reinterpret_cast<char *>(&formatData_.importantColorsCount_),
                 sizeof(formatData_.importantColorsCount_))) {
        throw std::runtime_error("Reading error inside VideoData");
    }
    uint8_t x{};
    for (uint32_t i = 0; i < formatData_.formatDataSize_ - 40; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside VideoData");
        }
        formatData_.codecSpecificData_.push_back(x);
    }
    return in;
}

std::ostream &VideoData::output(std::ostream &out)
{
    out << "  Video Data\n";
    out << "    Image size: " << formatData_.imageWidth_ << "x" << formatData_.imageHeight_ << "\n";
    out << "    Bits per pixel: " << formatData_.bitsPerPixelCount_ << std::endl;
    return out;
}

std::istream &StreamPropertiesObject::input(std::istream &in)
{
    if (!(in >> streamType_ >> errorCorrectionType_) ||
        !in.read(reinterpret_cast<char *>(&timeOffset_), sizeof(timeOffset_)) ||
        !in.read(reinterpret_cast<char *>(&typeSpecificDataLength_), sizeof(typeSpecificDataLength_)) ||
        !in.read(reinterpret_cast<char *>(&errorCorrectionDataLength_), sizeof(errorCorrectionDataLength_)) ||
        !in.read(reinterpret_cast<char *>(&flags_), sizeof(flags_)) ||
        !in.read(reinterpret_cast<char *>(&reserved_), sizeof(reserved_))) {
        throw std::runtime_error("Reading error inside StreamPropertiesObject");
    }
    if (streamType_ == MEDIA_GUIDS[0]) {
        typeSpecificData_ = std::make_shared<AudioData>();
    } else if (streamType_ == MEDIA_GUIDS[1]) {
        typeSpecificData_ = std::make_shared<VideoData>();
    } else {
        uint8_t x{};
        for (uint32_t i = 0; i < typeSpecificDataLength_; ++i) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside StreamPropertiesObject");
            }
        }
    }
    if (typeSpecificData_) {
        if (!typeSpecificData_->input(in)) {
            throw std::runtime_error("Reading error inside StreamPropertiesObject");
        }
    }
    uint8_t x{};
    for (uint32_t i = 0; i < errorCorrectionDataLength_; ++i) {
        if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
            throw std::runtime_error("Reading error inside StreamPropertiesObject");
        }
    }
    return in;
}

std::ostream &StreamPropertiesObject::output(std::ostream &out)
{
    out << "Stream Properties Object\n";
    if (typeSpecificData_) {
        return typeSpecificData_->output(out);
    }
    return out;
}

std::istream &operator>>(std::istream &in, StreamPropertiesObject &obj)
{
    return obj.input(in);
}