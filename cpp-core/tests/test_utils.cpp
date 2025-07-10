#include "mycelium/utils.hpp"
#include <gtest/gtest.h>

TEST(UtilsTest, MinMax) {
    std::vector<float> data = {3.0f, 1.0f, 5.0f, -2.0f};
    float minVal = mycelium::Utils::min(data);
    float maxVal = mycelium::Utils::max(data);

    EXPECT_FLOAT_EQ(minVal, -2.0f);
    EXPECT_FLOAT_EQ(maxVal, 5.0f);
}
