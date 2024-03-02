module;

#include <algorithm>
#include <cctype>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

export module part_one;

export namespace part_one {
int part1(const std::vector<std::string> &input) {
  int sum = 0;
  for (const std::string &s : input) {
    int first = -1, last = -1;

    for (int left = 0; left < s.size(); left++) {
      if (isdigit(s[left])) {
        first = s[left] - '0';
        break;
      }
    }

    for (size_t right = s.size() - 1; right >= 0; right--) {
      if (isdigit(s[right])) {
        last = s[right] - '0';
        break;
      }
    }

    sum += first * 10 + last;
  }
  return sum;
}

} // namespace part_one
