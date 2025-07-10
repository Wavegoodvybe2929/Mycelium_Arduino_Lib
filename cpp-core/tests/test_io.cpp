#include "mycelium/io.hpp"
#include <gtest/gtest.h>

TEST(IOTest, ReadSerialDummy) {
    auto data = mycelium::IO::readSerial("/dev/ttyUSB0", 9600, 3);
    ASSERT_EQ(data.size(), 3);
    for (const auto& line : data) {
        EXPECT_EQ(line, "S:0.05");
    }
}

TEST(IOTest, LoRaPlaceholder) {
    testing::internal::CaptureStdout();
    mycelium::IO::readLoRaWAN();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("not implemented"), std::string::npos);
}
