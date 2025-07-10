#include "mycelium/lang.hpp"
#include <gtest/gtest.h>

TEST(LangTest, ExtractWords) {
    std::vector<size_t> spikes = {1, 2, 10, 11, 25};
    auto words = mycelium::Lang::extractWords(spikes, 5);
    ASSERT_EQ(words.size(), 3);
}

TEST(LangTest, StateGraphBuild) {
    std::vector<std::vector<size_t>> words = {{1, 2}, {3, 4}, {5}};
    auto graph = mycelium::Lang::buildStateGraph(words);
    ASSERT_EQ(graph.size(), 2);
}

TEST(LangTest, Entropy) {
    std::string seq = "11110000";
    double ent = mycelium::Lang::shannonEntropy(seq);
    EXPECT_GT(ent, 0.0);
}

TEST(LangTest, LZComplexity) {
    std::string seq = "11110000";
    size_t lz = mycelium::Lang::lzComplexity(seq);
    EXPECT_GT(lz, 0u);
}
