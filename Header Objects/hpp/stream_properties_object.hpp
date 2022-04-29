#ifndef ASF__STREAM_PROPERTIES_OBJECT_HPP_
#define ASF__STREAM_PROPERTIES_OBJECT_HPP_

#include "../../Object/hpp/object.hpp"

class MediaData {
public:
    MediaData() = default;
    virtual ~MediaData() = default;

    virtual std::istream &input(std::istream &in);
    virtual std::ostream &output(std::ostream &out);
};

class AudioData : public MediaData {
private:
    uint16_t codecID_{};
    uint16_t channelsNum_{};
    uint32_t samplesPerSecond_{};
    uint32_t avgBytesPerSecondNum_{};
    uint16_t blockAlignment_{};
    uint16_t bitsPerSample_{};
    uint16_t codecSpecificDataSize_{};
    // just read, do not store codecSpecificData(codecSpecificDataSize_)
public:
    AudioData() = default;
    ~AudioData() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

class VideoData : public MediaData {
private:
    uint32_t encodedImageWidth_{};
    uint32_t encodedImageHeight_{};
    uint8_t reservedFlags_{};
    uint16_t formatDataSize_{};
    class FormatData {
    public:
        uint32_t formatDataSize_{};
        uint32_t imageWidth_{};
        uint32_t imageHeight_{};
        uint16_t reserved_{};
        uint16_t bitsPerPixelCount_{};
        uint32_t compressionID_{};
        uint32_t imageSize_{};
        uint32_t horizontalPixelsPerMeter_{};
        uint32_t verticalPixelsPerMeter_{};
        uint32_t colorsUsedCount_{};
        uint32_t importantColorsCount_{};
        std::vector<uint8_t> codecSpecificData_{};
    } formatData_{};
public:
    VideoData() = default;
    ~VideoData() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

class StreamPropertiesObject : public Object {
private:
    ObjectGuid streamType_{};
    ObjectGuid errorCorrectionType_{};
    uint64_t timeOffset_{};
    uint32_t typeSpecificDataLength_{};
    uint32_t errorCorrectionDataLength_{};
    uint16_t flags_{};
    uint32_t reserved_{};
    std::shared_ptr<MediaData> typeSpecificData_{};
    // just read, do not store errorCorrectionData(errorCorrectionDataLength_)
    const std::vector<ObjectGuid> MEDIA_GUIDS {
        {
            0xF8699E40,
            0x5B4D,
            0x11CF,
            {0xA8, 0xFD, 0x00, 0x80, 0x5F, 0x5C, 0x44, 0x2B},
            ObjectGuid::id()
        },
        {
            0xBC19EFC0,
            0x5B4D,
            0x11CF,
            {0xA8, 0xFD, 0x00, 0x80, 0x5F, 0x5C, 0x44, 0x2B},
            ObjectGuid::id()
        }
    };
public:
    StreamPropertiesObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~StreamPropertiesObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, StreamPropertiesObject &obj);
std::ostream &operator<<(std::ostream &out, StreamPropertiesObject &obj);

#endif //ASF__STREAM_PROPERTIES_OBJECT_HPP_