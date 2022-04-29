#include "object_factory.hpp"

std::unique_ptr<Object> ObjectFactory(const Object &obj)
{
    switch (obj.type_) {
    case Object::ASF_UNKNOWN_OBJECT:
        throw std::runtime_error("Unknown object");
    case Object::ASF_HEADER_OBJECT:
        return std::make_unique<HeaderObject>(obj.guid_, obj.size_);
//    case Object::ASF_DATA_OBJECT:
//        return std::make_unique<DataObject>(obj.guid_, obj.size_);
//    case Object::ASF_SIMPLE_INDEX_OBJECT:
//        return std::make_unique<SimpleIndexObject>(obj.guid_, obj.size_);
//    case Object::ASF_INDEX_OBJECT:
//        return std::make_unique<IndexObject>(obj.guid_, obj.size_);
//    case Object::ASF_MEDIA_OBJECT_INDEX_OBJECT:
//        return std::make_unique<MediaObjectIndexObject>(obj.guid_, obj.size_);
//    case Object::ASF_TIMECODE_INDEX_OBJECT:
//        return std::make_unique<TimecodeIndexObject>(obj.guid_, obj.size_);
    case Object::ASF_FILE_PROPERTIES_OBJECT:
        return std::make_unique<FilePropertiesObject>(obj.guid_, obj.size_);
    case Object::ASF_STREAM_PROPERTIES_OBJECT:
        return std::make_unique<StreamPropertiesObject>(obj.guid_, obj.size_);
    case Object::ASF_HEADER_EXTENSION_OBJECT:
        return std::make_unique<HeaderExtensionObject>(obj.guid_, obj.size_);
    case Object::ASF_CODEC_LIST_OBJECT:
        return std::make_unique<CodecListObject>(obj.guid_, obj.size_);
    case Object::ASF_SCRIPT_COMMAND_OBJECT:
        return std::make_unique<ScriptCommandObject>(obj.guid_, obj.size_);
    case Object::ASF_MARKER_OBJECT:
        return std::make_unique<MarkerObject>(obj.guid_, obj.size_);
    case Object::ASF_BITRATE_MUTUAL_EXCLUSION_OBJECT:
        return std::make_unique<BitrateMutualExclusionObject>(obj.guid_, obj.size_);
    case Object::ASF_ERROR_CORRECTION_OBJECT:
        return std::make_unique<ErrorCorrectionObject>(obj.guid_, obj.size_);
    case Object::ASF_CONTENT_DESCRIPTION_OBJECT:
        return std::make_unique<ContentDescriptionObject>(obj.guid_, obj.size_);
    case Object::ASF_EXTENDED_CONTENT_DESCRIPTION_OBJECT:
        return std::make_unique<ExtendedContentDescriptionObject>(obj.guid_, obj.size_);
    case Object::ASF_CONTENT_BRANDING_OBJECT:
        return std::make_unique<ContentBrandingObject>(obj.guid_, obj.size_);
    case Object::ASF_STREAM_BITRATE_PROPERTIES_OBJECT:
        return std::make_unique<StreamBitratePropertiesObject>(obj.guid_, obj.size_);
    case Object::ASF_CONTENT_ENCRYPTION_OBJECT:
        return std::make_unique<ContentEncryptionObject>(obj.guid_, obj.size_);
    case Object::ASF_EXTENDED_CONTENT_ENCRYPTION_OBJECT:
        return std::make_unique<ExtendedContentEncryptionObject>(obj.guid_, obj.size_);
    case Object::ASF_DIGITAL_SIGNATURE_OBJECT:
        return std::make_unique<DigitalSignatureObject>(obj.guid_, obj.size_);
    case Object::ASF_PADDING_OBJECT:
        return std::make_unique<PaddingObject>(obj.guid_, obj.size_);
//    case Object::ASF_EXTENDED_STREAM_PROPERTIES_OBJECT:
//        return std::make_unique<ExtendedStreamPropertiesObject>(obj.guid_, obj.size_);
//    case Object::ASF_ADVANCED_MUTUAL_EXCLUSION_OBJECT:
//        return std::make_unique<AdvancedMutualExclusionObject>(obj.guid_, obj.size_);
//    case Object::ASF_GROUP_MUTUAL_EXCLUSION_OBJECT:
//        return std::make_unique<GroupMutualExclusionObject>(obj.guid_, obj.size_);
//    case Object::ASF_STREAM_PRIORITIZATION_OBJECT:
//        return std::make_unique<StreamPrioritizationObject>(obj.guid_, obj.size_);
//    case Object::ASF_BANDWIDTH_SHARING_OBJECT:
//        return std::make_unique<BandwidthSharingObject>(obj.guid_, obj.size_);
//    case Object::ASF_LANGUAGE_LIST_OBJECT:
//        return std::make_unique<LanguageListObject>(obj.guid_, obj.size_);
//    case Object::ASF_METADATA_OBJECT:
//        return std::make_unique<MetadataObject>(obj.guid_, obj.size_);
//    case Object::ASF_METADATA_LIBRARY_OBJECT:
//        return std::make_unique<MetadataLibraryObject>(obj.guid_, obj.size_);
//    case Object::ASF_INDEX_PARAMETERS_OBJECT:
//        return std::make_unique<IndexParametersObject>(obj.guid_, obj.size_);
//    case Object::ASF_MEDIA_OBJECT_INDEX_PARAMETERS_OBJECT:
//        return std::make_unique<MediaObjectIndexParametersObject>(obj.guid_, obj.size_);
//    case Object::ASF_TIMECODE_INDEX_PARAMETERS_OBJECT:
//        return std::make_unique<TimecodeIndexParametersObject>(obj.guid_, obj.size_);
//    case Object::ASF_COMPATIBILITY_OBJECT:
//        return std::make_unique<CompatibilityObject>(obj.guid_, obj.size_);
//    case Object::ASF_ADVANCED_CONTENT_ENCRYPTION_OBJECT:
//        return std::make_unique<AdvancedContentEncryptionObject>(obj.guid_, obj.size_);
    default:
        throw std::invalid_argument("This type is not supported yet");
    }
}