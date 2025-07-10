#include "mycelium/lang.hpp"
#include <unordered_set>
#include <cmath>
#include <sstream>

namespace mycelium {

std::vector<std::vector<size_t>> Lang::extractWords(const std::vector<size_t>& spikes, size_t theta) {
    std::vector<std::vector<size_t>> words;
    std::vector<size_t> currentWord;

    for (size_t i = 0; i + 1 < spikes.size(); ++i) {
        currentWord.push_back(spikes[i]);
        if (spikes[i + 1] - spikes[i] > theta) {
            words.push_back(currentWord);
            currentWord.clear();
        }
    }

    if (!spikes.empty()) {
        currentWord.push_back(spikes.back());
        words.push_back(currentWord);
    }

    return words;
}

std::unordered_map<std::string, std::vector<std::string>> Lang::buildStateGraph(const std::vector<std::vector<size_t>>& words) {
    std::unordered_map<std::string, std::vector<std::string>> graph;

    for (size_t i = 0; i + 1 < words.size(); ++i) {
        std::ostringstream from_ss, to_ss;
        for (auto idx : words[i]) from_ss << idx << ",";
        for (auto idx : words[i + 1]) to_ss << idx << ",";

        graph[from_ss.str()].push_back(to_ss.str());
    }

    return graph;
}

double Lang::shannonEntropy(const std::string& sequence) {
    std::unordered_map<char, size_t> freq;
    for (char c : sequence) {
        freq[c]++;
    }

    double entropy = 0.0;
    double len = static_cast<double>(sequence.size());
    for (const auto& [c, count] : freq) {
        double p = count / len;
        entropy -= p * std::log2(p);
    }

    return entropy;
}

size_t Lang::lzComplexity(const std::string& sequence) {
    std::unordered_set<std::string> dict;
    std::string w;
    size_t c = 0;

    for (char ch : sequence) {
        w += ch;
        if (dict.find(w) == dict.end()) {
            dict.insert(w);
            w.clear();
            c++;
        }
    }

    return c;
}

} // namespace mycelium
