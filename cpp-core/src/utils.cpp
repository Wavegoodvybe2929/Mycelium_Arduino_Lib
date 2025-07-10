#include "mycelium/utils.hpp"
#include <limits>

namespace mycelium {

float Utils::min(const std::vector<float>& data) {
    float minVal = std::numeric_limits<float>::max();
    for (auto x : data) {
        if (x < minVal) {
            minVal = x;
        }
    }
    return minVal;
}

float Utils::max(const std::vector<float>& data) {
    float maxVal = std::numeric_limits<float>::lowest();
    for (auto x : data) {
        if (x > maxVal) {
            maxVal = x;
        }
    }
    return maxVal;
}

} // namespace mycelium
