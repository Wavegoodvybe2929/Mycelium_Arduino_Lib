#pragma once

#include <vector>

namespace mycelium {

class Utils {
public:
    static float min(const std::vector<float>& data);
    static float max(const std::vector<float>& data);
};

} // namespace mycelium
