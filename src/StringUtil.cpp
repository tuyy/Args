#include <StringUtil.h>

#include <sstream>
#include <iostream>

using std::stringstream;
using std::vector;
using std::equal;
using std::string;

bool endsWith(const string &aValueStr, const string &aEndStr)
{
    bool sResult = false;
    if (aEndStr.size() <= aValueStr.size())
    {
        sResult = equal(aEndStr.rbegin(), aEndStr.rend(), aValueStr.rbegin());
    }
    return sResult;
}

vector<string> split(string aInputStr, char aDelim)
{
    vector<string> sResult;
    stringstream   ss(aInputStr);

    string str;
    char ch;
    while (ss >> ch)
    {
        if (ch == aDelim)
        {
            sResult.push_back(str);
            str.clear();
            continue;
        }
        str += ch;
    }
    sResult.push_back(str);
    return sResult;
}
