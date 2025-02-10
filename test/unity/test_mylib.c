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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_should_return_correct_sum);
    return UNITY_END();
}
