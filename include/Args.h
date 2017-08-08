#pragma once

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <ArgsMarshal.h>

class Args
{
public:
    Args(const std::string &aOptionFormat, const std::string &aArgs);

    bool        getBoolean(char aOptionChar);
    int32_t     getInteger(char aOptionChar);
    std::string getString(char aOptionChar);

private:
    void parseOptionFormat(const std::string &aOptionFormat);
    void parseArguments(const std::string &aArgs);
    void parseArgument(char aOption, const std::string &aValue);

private:
    std::map<char, std::shared_ptr<ArgsMarshal>> mArgsMarshalMap;
    std::map<char, std::string>                  mArgsFormatMap;
};
