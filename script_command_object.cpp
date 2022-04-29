#include "script_command_object.hpp"

std::istream &ScriptCommandObject::input(std::istream &in)
{
    if (!(in >> reserved_) ||
        !in.read(reinterpret_cast<char *>(&commandsCount_), sizeof(commandsCount_)) ||
        !in.read(reinterpret_cast<char *>(&commandTypesCount_), sizeof(commandTypesCount_))) {
        throw std::runtime_error("Reading error inside ScriptCommandObject");
    }
    for (uint16_t i = 0; i < commandTypesCount_; ++i) {
        ScriptCommandObject::CommandType type{};
        uint8_t x{};
        if (!in.read(reinterpret_cast<char *>(&type.commandTypeNameLength_),
                     sizeof(type.commandTypeNameLength_))) {
            throw std::runtime_error("Reading error inside ScriptCommandObject");
        }
        for (long long unsigned int j = 0; j < type.commandTypeNameLength_ * sizeof(wchar_t); ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside ScriptCommandObject");
            }
            type.commandTypeName_.push_back(x);
        }
        commandTypes_.push_back(type);
    }
    for (uint16_t i = 0; i < commandsCount_; ++i) {
        ScriptCommandObject::Command command{};
        uint8_t x{};
        if (!in.read(reinterpret_cast<char *>(&command.presentationTime_),
                     sizeof(command.presentationTime_)) ||
            !in.read(reinterpret_cast<char *>(&command.typeIndex_), sizeof(command.typeIndex_)) ||
            !in.read(reinterpret_cast<char *>(&command.commandNameLength_),
                     sizeof(command.commandNameLength_))) {
            throw std::runtime_error("Reading error inside ScriptCommandObject");
        }
        for (long long unsigned int j = 0; j < command.commandNameLength_ * sizeof(wchar_t); ++j) {
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(x))) {
                throw std::runtime_error("Reading error inside ScriptCommandObject");
            }
            command.commandName_.push_back(x);
        }
        commands_.push_back(command);
    }
    return in;
}

std::ostream &ScriptCommandObject::output(std::ostream &out)
{
    out << "Script Command Object" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, ScriptCommandObject &obj)
{
    return obj.input(in);
}

std::ostream &operator<<(std::ostream &out, ScriptCommandObject &obj)
{
    return obj.output(out);
}