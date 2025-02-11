#include "CppUTest/TestHarness.h"
#include "mylib.h"

TEST_GROUP(ADDTest)
{
    void setup() {}
    void teardown() {}
};

TEST(ADDTest, test_add_1)
{
    CHECK_EQUAL(5, add(2, 3));
}

TEST(ADDTest, test_add_2)
{
    CHECK_EQUAL(10, add(7, 3));
}

TEST(ADDTest, test_add_3)
{
    CHECK_EQUAL(0, add(0, 0));
}
