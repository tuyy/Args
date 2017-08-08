#pragma once

#include <iostream>
#include <sstream>
#include <string>

class ArgsMarshal
{
public:
    static const std::string BOOLEAN_FORMAT;
    static const std::string INTEGER_FORMAT;
    static const std::string STRING_FORMAT;

public:
    ArgsMarshal(const std::string &aArgument)
    : mArgument(aArgument)
    {};

    virtual ~ArgsMarshal()
    {
    }

    virtual bool getBoolean()
    {
        return false; 
    };

    virtual int32_t getInteger()
    {
        return 0; 
    };

    virtual std::string getString()
    {
        return ""; 
    }

protected:
    std::string mArgument;
};

class BooleanArgsMarshal : public ArgsMarshal
{
public:
    BooleanArgsMarshal(const std::string &aArgument)
    : ArgsMarshal(aArgument)
    {};

    ~BooleanArgsMarshal() = default;

    bool getBoolean()
    {
        return true; 
    };
};

class IntegerArgsMarshal : public ArgsMarshal
{
public:
    IntegerArgsMarshal(const std::string &aArgument)
    : ArgsMarshal(aArgument)
    {};

    ~IntegerArgsMarshal() = default;

    int32_t getInteger()
    {
        std::stringstream ss(mArgument);
        int32_t val;
        ss >> val;
        return val;
    };
};

class StringArgsMarshal : public ArgsMarshal
{
public:
    StringArgsMarshal(const std::string &aArgument)
    : ArgsMarshal(aArgument)
    {};

    ~StringArgsMarshal() = default;

    std::string getString()
    {
        return mArgument; 
    };
};

class ArgsMarshalFactory
{
public:
    static ArgsMarshal* create(const std::string &aFormat, const std::string &aValue)
    {
        if (aFormat == ArgsMarshal::BOOLEAN_FORMAT)
        {
            return new BooleanArgsMarshal(aValue);
        }
        else if (aFormat == ArgsMarshal::INTEGER_FORMAT)
        {
            return new IntegerArgsMarshal(aValue);
        }
        else if (aFormat == ArgsMarshal::STRING_FORMAT)
        {
            return new StringArgsMarshal(aValue);
        }
        else
        {
            return nullptr; 
        }
    };
};

