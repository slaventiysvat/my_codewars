#include "pch.h"
#include "../solved_tasks/simple_train_functions.h"

TEST(make_phone_number, simple_mobile_phone) {

    char phnum[15] = {};
    const unsigned char nums[10] = { '0','5','5','8','1','1','4','5','2','5' };

    char* phone_ptr = create_phone_number(phnum, nums);

    EXPECT_STREQ(phone_ptr, "(055) 811-4525");
}