#include "unity.h"
#include "mylib.h"

void setUp(void)
{
    // Set up test cases (if needed)
}

void tearDown(void)
{
    // Clean up (if needed)
}

void test_add_should_return_correct_sum(void)
{
    TEST_ASSERT_EQUAL_UINT8(5,  add(2, 3));
    TEST_ASSERT_EQUAL_UINT8(10, add(7, 3));
    TEST_ASSERT_EQUAL_UINT8(0,  add(0, 0));
}

// int main(void) {
//     UNITY_BEGIN();
//     RUN_TEST(test_add_should_return_correct_sum);
//     return UNITY_END();
// }


void test_add_1(void)
{
    TEST_ASSERT_EQUAL_UINT8(5,  add(2, 3));
}

void test_add_2(void)
{
    TEST_ASSERT_EQUAL_UINT8(10,  add(7, 3));
}

void test_add_3(void)
{
    TEST_ASSERT_EQUAL_UINT8(0,  add(0, 0));
}

int run_unity_test(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_add_1);
    RUN_TEST(test_add_2);
    RUN_TEST(test_add_3);

    return UNITY_END();
}

int main(void)
{
    return run_unity_test();
}