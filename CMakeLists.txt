cmake_minimum_required(VERSION 3.21)
project(ASF)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Werror)

add_executable(ASF main.cpp main.hpp
        Object/cpp/object_guid.cpp Object/hpp/object_guid.hpp
        Object/cpp/object.cpp Object/hpp/object.hpp
        "Header Objects/cpp/header_object.cpp" "Header Objects/hpp/header_object.hpp"
        "Factory/cpp/object_factory.cpp" "Factory/hpp/object_factory.hpp"
        "Header Objects/cpp/file_properties_object.cpp" "Header Objects/hpp/file_properties_object.hpp"
        "Header Objects/cpp/stream_properties_object.cpp" "Header Objects/hpp/stream_properties_object.hpp"
        "Header Objects/cpp/header_extension_object.cpp" "Header Objects/hpp/header_extension_object.hpp"
        "Header Objects/cpp/codec_list_object.cpp" "Header Objects/hpp/codec_list_object.hpp"
        "Header Objects/cpp/script_command_object.cpp" "Header Objects/hpp/script_command_object.hpp"
        "Header Objects/cpp/marker_object.cpp" "Header Objects/hpp/marker_object.hpp"
        "Header Objects/cpp/bitrate_mutual_exclusion_object.cpp" "Header Objects/hpp/bitrate_mutual_exclusion_object.hpp"
        "Header Objects/cpp/error_correction_object.cpp" "Header Objects/hpp/error_correction_object.hpp"
        "Header Objects/cpp/content_description_object.cpp" "Header Objects/hpp/content_description_object.hpp"
        "Header Objects/cpp/extended_content_description_object.cpp" "Header Objects/hpp/extended_content_description_object.hpp"
        "Header Objects/cpp/stream_bitrate_properties_object.cpp" "Header Objects/hpp/stream_bitrate_properties_object.hpp"
        "Header Objects/cpp/content_branding_object.cpp" "Header Objects/hpp/content_branding_object.hpp"
        "Header Objects/cpp/content_encryption_object.cpp" "Header Objects/hpp/content_encryption_object.hpp"
        "Header Objects/cpp/extended_content_encryption_object.cpp" "Header Objects/hpp/extended_content_encryption_object.hpp"
        "Header Objects/cpp/digital_signature_object.cpp" "Header Objects/hpp/digital_signature_object.hpp"
        "Header Objects/cpp/padding_object.cpp" "Header Objects/hpp/padding_object.hpp")