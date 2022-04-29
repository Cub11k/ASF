#ifndef ASF__SCRIPT_COMMAND_OBJECT_HPP_
#define ASF__SCRIPT_COMMAND_OBJECT_HPP_

#include "object.hpp"

class ScriptCommandObject : public Object
{
private:
    ObjectGuid reserved_{};
    uint16_t commandsCount_{};
    uint16_t commandTypesCount_{};
    class CommandType
    {
    public:
        uint16_t commandTypeNameLength_{};
        std::vector<uint8_t> commandTypeName_{};
    };
    std::vector<CommandType> commandTypes_{};
    class Command
    {
    public:
        uint32_t presentationTime_{};
        uint16_t typeIndex_{};
        uint16_t commandNameLength_{};
        std::vector<uint8_t> commandName_{};
    };
    std::vector<Command> commands_{};
public:
    ScriptCommandObject(const ObjectGuid &guid = ObjectGuid{}, uint64_t size = 0x0)
        : Object(guid, size)
    {}

    ~ScriptCommandObject() override = default;

    std::istream &input(std::istream &in) override;
    std::ostream &output(std::ostream &out) override;
};

std::istream &operator>>(std::istream &in, ScriptCommandObject &obj);
std::ostream &operator<<(std::ostream &out, ScriptCommandObject &obj);

#endif //ASF__SCRIPT_COMMAND_OBJECT_HPP_
