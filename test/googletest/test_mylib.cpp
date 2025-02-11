#include "mylib.h"
#include <gtest/gtest.h>

TEST(MyLibTest, AddFunction)
{
    EXPECT_EQ(add(2, 3),  5);
    EXPECT_EQ(add(7, 3),  10);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0),  0);
}