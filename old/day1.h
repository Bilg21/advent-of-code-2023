#include "utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <ranges>
#include <string_view>

using namespace std;

class Day1 {
public:
  int part1(vector<string> &input) {
    int sum = 0;
    for (string &s : input) {
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

      cout << first << last << endl;
      sum += first * 10 + last;
    }
    return sum;
  }

  int part2(vector<string> &input) {
    unordered_map<string, int> digitMap = {
        {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"0", 0},    {"1", 1},   {"2", 2},     {"3", 3},     {"4", 4},
        {"5", 5},    {"6", 6},   {"7", 7},     {"8", 8},     {"9", 9},
    };

    int sum = 0;
    for (string &s : input) {
      int firstIdx = s.size(), lastIdx = -1;
      int first = -1, last = -1;

      for (auto &kv : digitMap) {
        int idx = s.find(kv.first);
        if (idx != string::npos && firstIdx > idx) {
          firstIdx = idx;
          first = kv.second;
        }

        idx = s.rfind(kv.first);
        if (idx != string::npos && idx > lastIdx) {
          lastIdx = idx;
          last = kv.second;
        }
      }

      cout << s << " -> " << first << last << endl;
      sum += first * 10 + last;
    }
    return sum;
  }

  void testWithSampleExample() {
    vector<string> input = {
        "1abc2",
        "pqr3stu8vwx",
        "a1b2c3d4e5f",
        "treb7uchet",
    };

    cout << "part1: " << part1(input) << endl;
    cout << "part2: " << part2(input) << endl;
  }

  void run() {
    vector<string> in = Utils::readInput("Day1.txt");
    cout << "Part1: " << part1(in) << endl;
    cout << "Part2: " << part2(in) << endl;
  }
};
