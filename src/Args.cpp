#include <Args.h>

#include <StringUtil.h>
#include <sstream>
#include <iostream>
#include <stdexcept>

using std::stringstream;
using std::string;
using std::map;

Args::Args(const string &aOptionFormat, const string &aArgs)
{
    parseOptionFormat(aOptionFormat);
    parseArguments(aArgs);
}

void Args::parseOptionFormat(const string &aOptionFormat)
{
    for (auto option : split(aOptionFormat, ','))
    {
        if (option.size() == 0)
        {
            throw std::runtime_error("invalid option format");
        }
        else
        {
            char sOptionChar = option[0];
            string sTypeFormat = option.substr(1);
            mArgsFormatMap[sOptionChar] = sTypeFormat;
        }
    }
}

void Args::parseArguments(const std::string &aArguments)
{
    for (auto arg : split(aArguments, '-'))
    {
        if (arg.size() > 0)
        {
            char sOptionChar = arg[0];
            string sValue = arg.substr(1);
            parseArgument(sOptionChar, sValue);
        }
    }
}

void Args::parseArgument(char aOption, const std::string &aValue)
{
    map<char, string>::const_iterator pos = mArgsFormatMap.find(aOption);
    if (pos != mArgsFormatMap.end())
    {
        string sFormat = pos->second; 
        std::shared_ptr<ArgsMarshal> sArgsMarshal(ArgsMarshalFactory::create(sFormat, aValue));
        mArgsMarshalMap[aOption] = sArgsMarshal;
    }
}

bool Args::getBoolean(char aOptionChar)
{
    bool sResult = false;
    map<char, std::shared_ptr<ArgsMarshal>>::const_iterator pos = mArgsMarshalMap.find(aOptionChar);
    if (pos != mArgsMarshalMap.end())
    {
        sResult = pos->second->getBoolean();
    } 
    return sResult;
}

int32_t Args::getInteger(char aOptionChar)
{
    int32_t sResult = 0;
    map<char, std::shared_ptr<ArgsMarshal>>::const_iterator pos = mArgsMarshalMap.find(aOptionChar);
    if (pos != mArgsMarshalMap.end())
    {
        sResult = pos->second->getInteger();
    } 
    return sResult;
}

string Args::getString(char aOptionChar)
{
    string sResult;
    map<char, std::shared_ptr<ArgsMarshal>>::const_iterator pos = mArgsMarshalMap.find(aOptionChar);
    if (pos != mArgsMarshalMap.end())
    {
        sResult = pos->second->getString();
    }
    return sResult;
}
