#include "gtest/gtest.h"
#include <StringUtil.h>

TEST(UtilTest, string_split)
{
    std::string inputStr = "one,two,three";
    std::vector<std::string> expected{"one", "two", "three"};
    std::vector<std::string> result = split(inputStr, ',');
    
    for (size_t i = 0; i < result.size(); i++)
    {
        EXPECT_TRUE(expected[i] == result[i]); 
    }
}

TEST(UtilTest, string_split_one)
{
    std::string inputStr = "-l 123 -k";
    std::vector<std::string> expected{"", "l123", "k"};
    std::vector<std::string> result = split(inputStr, '-');
    
    for (size_t i = 0; i < result.size(); i++)
    {
        ASSERT_EQ(expected[i], result[i]);
    }
}

TEST(UtilTest, string_endswith)
{
    EXPECT_FALSE(endsWith("hellobye", "longend1111111"));
    EXPECT_FALSE(endsWith("hellobye", "hello"));
    EXPECT_TRUE(endsWith("hellobye", "bye"));
    EXPECT_TRUE(endsWith("hellobye", "hellobye"));
}

TEST(UtilTest, string_substr)
{
    std::string str = "khello";
    ASSERT_EQ("hello", str.substr(1));
}

