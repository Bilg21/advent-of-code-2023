module;

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

export module part_two;

export namespace part_two {
int part2(std::vector<std::string> &input) {
  std::unordered_map<std::string, int> digitMap = {
      {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
      {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
      {"0", 0},    {"1", 1},   {"2", 2},     {"3", 3},     {"4", 4},
      {"5", 5},    {"6", 6},   {"7", 7},     {"8", 8},     {"9", 9},
  };

  int sum = 0;
  for (std::string &s : input) {
    int firstIdx = s.size(), lastIdx = -1;
    int first = -1, last = -1;

    for (auto &kv : digitMap) {
      int idx = s.find(kv.first);
      if (idx != std::string::npos && firstIdx > idx) {
        firstIdx = idx;
        first = kv.second;
      }

      idx = s.rfind(kv.first);
      if (idx != std::string::npos && idx > lastIdx) {
        lastIdx = idx;
        last = kv.second;
      }
    }

    std::cout << s << " -> " << first << last << std::endl;
    sum += first * 10 + last;
  }
  return sum;
}

} // namespace part_two
