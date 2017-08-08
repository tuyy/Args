#include "gtest/gtest.h"
#include <Args.h>

TEST(ArgsTest, invalidOptionFormat)
{
    try
    {
        Args args = Args(",,", "");
        EXPECT_TRUE(false);
    }
    catch (std::exception &e)
    {
        ASSERT_STREQ("invalid option format", e.what());
    }
}

TEST(ArgsTest, optionFormat)
{
    try
    {
        Args args = Args("l,s#,k##", "");
    }
    catch (std::exception &e)
    {
        EXPECT_TRUE(false);
    }
}

TEST(ArgsTest, getBoolean)
{
    Args args = Args("l", "-l");
    EXPECT_FALSE(args.getBoolean('k'));
    EXPECT_TRUE(args.getBoolean('l'));
}

TEST(ArgsTest, getInteger)
{
    Args args = Args("i#", "-i123");
    ASSERT_EQ(123, args.getInteger('i'));
}

TEST(ArgsTest, getString)
{
    Args args = Args("s##", "-shello");
    ASSERT_EQ("hello", args.getString('s'));
}

TEST(ArgsTest, getMultiType)
{
    Args args = Args("l,j#,k##", "-l -j 123 -kking");
    ASSERT_EQ("king", args.getString('k'));
    ASSERT_EQ(123, args.getInteger('j'));
    EXPECT_TRUE(args.getBoolean('l'));
}
