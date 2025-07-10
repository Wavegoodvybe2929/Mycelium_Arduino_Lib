#include "mycelium/dsp.hpp"
#include "mycelium/utils.hpp"
#include <cmath>

namespace mycelium {

std::vector<float> DSP::bandpassFilter(const std::vector<float>& data, float lowCut, float highCut) {
    // Placeholder: In real code, use biquad or FIR filters
    return data;
}

std::vector<size_t> DSP::detectSpikes(const std::vector<float>& data, size_t windowSize, float delta) {
    std::vector<size_t> spikes;
    size_t n = data.size();

    for (size_t i = windowSize; i < n - windowSize; ++i) {
        float neighborhood = 0.0f;
        for (size_t j = i - windowSize; j < i + windowSize; ++j) {
            neighborhood += std::abs(data[j]);
        }
        neighborhood /= (2 * windowSize);

        if (std::abs(data[i]) - neighborhood > delta) {
            spikes.push_back(i);
        }
    }

    return spikes;
}

std::vector<float> DSP::normalize(const std::vector<float>& data) {
    float minVal = Utils::min(data);
    float maxVal = Utils::max(data);
    std::vector<float> result;

    for (auto x : data) {
        if (std::abs(maxVal - minVal) < 1e-6f) {
            result.push_back(0.0f);
        } else {
            result.push_back((x - minVal) / (maxVal - minVal));
        }
    }

    return result;
}

} // namespace mycelium
