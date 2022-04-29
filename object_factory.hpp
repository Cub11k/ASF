#ifndef ASF__OBJECT_FACTORY_HPP_
#define ASF__OBJECT_FACTORY_HPP_

#include "object.hpp"
#include "header_object.hpp"
#include "file_properties_object.hpp"
#include "stream_properties_object.hpp"
#include "header_extension_object.hpp"
#include "codec_list_object.hpp"
#include "script_command_object.hpp"
#include "marker_object.hpp"
#include "bitrate_mutual_exclusion_object.hpp"
#include "error_correction_object.hpp"
#include "content_description_object.hpp"
#include "extended_content_description_object.hpp"
#include "stream_bitrate_properties_object.hpp"
#include "content_branding_object.hpp"
#include "content_encryption_object.hpp"
#include "extended_content_encryption_object.hpp"
#include "digital_signature_object.hpp"
#include "padding_object.hpp"

std::unique_ptr<Object> ObjectFactory(const Object &obj);

#endif //ASF__OBJECT_FACTORY_HPP_