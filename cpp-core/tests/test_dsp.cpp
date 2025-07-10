#include "mycelium/dsp.hpp"
#include <gtest/gtest.h>

TEST(DSPTest, Normalize) {
    std::vector<float> data = {0.0f, 5.0f, 10.0f};
    auto norm = mycelium::DSP::normalize(data);
    EXPECT_NEAR(norm.front(), 0.0f, 1e-5);
    EXPECT_NEAR(norm.back(), 1.0f, 1e-5);
}

TEST(DSPTest, DetectSpikes) {
    std::vector<float> data(100, 0.0f);
    data[50] = 10.0f;
    auto spikes = mycelium::DSP::detectSpikes(data, 5, 5.0f);
    ASSERT_FALSE(spikes.empty());
    EXPECT_EQ(spikes.front(), 50);
}

TEST(DSPTest, BandpassPassthrough) {
    std::vector<float> data = {1.0f, 2.0f, 3.0f};
    auto filtered = mycelium::DSP::bandpassFilter(data, 0.1f, 2.0f);
    EXPECT_EQ(filtered, data);
}
