module;

#include <string>
#include <string_view>
#include <vector>

export module input;

export namespace input {
const std::string_view day1_test = R"(
        1abc2
        pqr3stu8vwx
        a1b2c3d4e5f
        treb7uchet
)";

std::vector<std::string> test_input = {
    "1abc2",
    "pqr3stu8vwx",
    "a1b2c3d4e5f",
    "treb7uchet",
};
} // namespace input
