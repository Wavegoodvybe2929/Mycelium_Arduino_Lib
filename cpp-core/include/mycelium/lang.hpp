#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace mycelium {

class Lang {
public:
    static std::vector<std::vector<size_t>> extractWords(const std::vector<size_t>& spikes, size_t theta);
    static std::unordered_map<std::string, std::vector<std::string>> buildStateGraph(const std::vector<std::vector<size_t>>& words);
    static double shannonEntropy(const std::string& sequence);
    static size_t lzComplexity(const std::string& sequence);
};

} // namespace mycelium
