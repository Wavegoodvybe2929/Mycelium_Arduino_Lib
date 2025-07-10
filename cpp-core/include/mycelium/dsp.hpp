#pragma once

#include <vector>

namespace mycelium {

class DSP {
public:
    static std::vector<float> bandpassFilter(const std::vector<float>& data, float lowCut, float highCut);
    static std::vector<size_t> detectSpikes(const std::vector<float>& data, size_t windowSize, float delta);
    static std::vector<float> normalize(const std::vector<float>& data);
};

} // namespace mycelium
