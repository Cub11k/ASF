cmake_minimum_required(VERSION 3.21)
project(ASF)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Werror)

add_executable(ASF main.cpp main.hpp
        Object/cpp/object_guid.cpp Object/hpp/object_guid.hpp
        Object/cpp/object.cpp Object/hpp/object.hpp
        HeaderObjects/cpp/header_object.cpp HeaderObjects/hpp/header_object.hpp
        Factory/cpp/object_factory.cpp Factory/hpp/object_factory.hpp
        HeaderObjects/cpp/file_properties_object.cpp HeaderObjects/hpp/file_properties_object.hpp
        HeaderObjects/cpp/stream_properties_object.cpp HeaderObjects/hpp/stream_properties_object.hpp
        HeaderObjects/cpp/header_extension_object.cpp HeaderObjects/hpp/header_extension_object.hpp
        HeaderObjects/cpp/codec_list_object.cpp HeaderObjects/hpp/codec_list_object.hpp
        HeaderObjects/cpp/script_command_object.cpp HeaderObjects/hpp/script_command_object.hpp
        HeaderObjects/cpp/marker_object.cpp HeaderObjects/hpp/marker_object.hpp
        HeaderObjects/cpp/bitrate_mutual_exclusion_object.cpp HeaderObjects/hpp/bitrate_mutual_exclusion_object.hpp
        HeaderObjects/cpp/error_correction_object.cpp HeaderObjects/hpp/error_correction_object.hpp
        HeaderObjects/cpp/content_description_object.cpp HeaderObjects/hpp/content_description_object.hpp
        HeaderObjects/cpp/extended_content_description_object.cpp HeaderObjects/hpp/extended_content_description_object.hpp
        HeaderObjects/cpp/stream_bitrate_properties_object.cpp HeaderObjects/hpp/stream_bitrate_properties_object.hpp
        HeaderObjects/cpp/content_branding_object.cpp HeaderObjects/hpp/content_branding_object.hpp
        HeaderObjects/cpp/content_encryption_object.cpp HeaderObjects/hpp/content_encryption_object.hpp
        HeaderObjects/cpp/extended_content_encryption_object.cpp HeaderObjects/hpp/extended_content_encryption_object.hpp
        HeaderObjects/cpp/digital_signature_object.cpp HeaderObjects/hpp/digital_signature_object.hpp
        HeaderObjects/cpp/padding_object.cpp HeaderObjects/hpp/padding_object.hpp)