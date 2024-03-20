#include "../../external/Unity/src/unity.h"
#include "logic.h"

void test_sum(){
    TEST_ASSERT_EQUAL(2,sum(1,1));
}
void test_sum2(){
    TEST_ASSERT_EQUAL(3,sum(2,1));
}
void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_sum);
    RUN_TEST(test_sum2);
    return UNITY_END();
}