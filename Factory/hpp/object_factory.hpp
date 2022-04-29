#ifndef ASF__OBJECT_FACTORY_HPP_
#define ASF__OBJECT_FACTORY_HPP_

#include "../../Object/hpp/object.hpp"
#include "../../Header Objects/hpp/header_object.hpp"
#include "../../Header Objects/hpp/file_properties_object.hpp"
#include "../../Header Objects/hpp/stream_properties_object.hpp"
#include "../../Header Objects/hpp/header_extension_object.hpp"
#include "../../Header Objects/hpp/codec_list_object.hpp"
#include "../../Header Objects/hpp/script_command_object.hpp"
#include "../../Header Objects/hpp/marker_object.hpp"
#include "../../Header Objects/hpp/bitrate_mutual_exclusion_object.hpp"
#include "../../Header Objects/hpp/error_correction_object.hpp"
#include "../../Header Objects/hpp/content_description_object.hpp"
#include "../../Header Objects/hpp/extended_content_description_object.hpp"
#include "../../Header Objects/hpp/stream_bitrate_properties_object.hpp"
#include "../../Header Objects/hpp/content_branding_object.hpp"
#include "../../Header Objects/hpp/content_encryption_object.hpp"
#include "../../Header Objects/hpp/extended_content_encryption_object.hpp"
#include "../../Header Objects/hpp/digital_signature_object.hpp"
#include "../../Header Objects/hpp/padding_object.hpp"

std::unique_ptr<Object> ObjectFactory(const Object &obj);

#endif //ASF__OBJECT_FACTORY_HPP_