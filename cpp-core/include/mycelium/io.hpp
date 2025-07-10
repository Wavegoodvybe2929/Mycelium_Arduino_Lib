#pragma once

#include <string>
#include <vector>

namespace mycelium {

class IO {
public:
    static std::vector<std::string> readSerial(const std::string& port, unsigned int baudRate, unsigned int durationSec);
    static void readLoRaWAN();  // Placeholder for future LoRa support
};

} // namespace mycelium
