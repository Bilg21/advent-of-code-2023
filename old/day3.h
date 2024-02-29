#pragma once
#include "utils.h"
#include <iostream>
#include <unordered_set>

struct pairhash {
  size_t operator()(const pair<int, int> &p) const {
    size_t h1 = hash<int>()(p.first);
    size_t h2 = hash<int>()(p.second);
    // XOR the two hashes together to avoid collisions when `p.first ==
    // p.second`.
    return (h1 << 2) ^ (h2 << 1) ^ (p.first == p.second);
  }
};

class Day3 {
public:
  int part1(vector<string> &in) {
    vector<pair<int, int>> symbolCoordinates;

    for (int row = 0; row < in.size(); row++) {
      for (int col = 0; col < in[row].size(); col++) {
        char c = in[row][col];
        if (c != '.' && !isdigit(c)) {
          symbolCoordinates.push_back({row, col});
        }
      }
    }

    vector<pair<int, int>> directions = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                                         {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    unordered_map<pair<int, int>, int, pairhash> numTaken;

    int sum = 0;
    for (auto &pii : symbolCoordinates) {
      for (int dir = 0; dir < 8; dir++) {
        int r = pii.first + directions[dir].first;
        int c = pii.second + directions[dir].second;
        if (r >= 0 && r < in.size() && c >= 0 && c < in[0].size() &&
            isdigit(in[r][c])) {
          auto tpl = expand(in, r, c);
          numTaken.emplace(make_pair(get<0>(tpl), get<1>(tpl)), get<2>(tpl));
        }
      }
    }

    for (pair<pair<int, int>, int> kv : numTaken) {
      sum += kv.second;
    }

    return sum;
  }

  tuple<int, int, int> expand(vector<string> &in, int r, int c) {
    int left = c, right = c;
    while (isdigit(in[r][left]) && left > 0) {
      left--;
    }
    if (!isdigit(in[r][left]))
      left++;

    while (isdigit(in[r][right]) && right < in[0].size()) {
      right++;
    }
    if (!isdigit(in[r][right]))
      right--;

    int num = stoi(in[r].substr(left, right - left + 1));
    return {r, left, num};
  }

  int part2(vector<string> &in) {
    vector<pair<int, int>> gearsCandidates;

    for (int row = 0; row < in.size(); row++) {
      for (int col = 0; col < in[row].size(); col++) {
        char c = in[row][col];
        if (c == '*') {
          gearsCandidates.push_back({row, col});
        }
      }
    }

    vector<pair<int, int>> directions = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                                         {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    int sum = 0;
    for (auto &pii : gearsCandidates) {
      unordered_map<pair<int, int>, int, pairhash> numTaken;
      for (int dir = 0; dir < 8; dir++) {
        int r = pii.first + directions[dir].first;
        int c = pii.second + directions[dir].second;
        if (r >= 0 && r < in.size() && c >= 0 && c < in[0].size() &&
            isdigit(in[r][c])) {
          auto tpl = expand(in, r, c);
          int num = get<2>(tpl);
          numTaken.emplace(make_pair(get<0>(tpl), get<1>(tpl)), get<2>(tpl));
          // numbers.push_back(num);
        }
      }
      if (numTaken.size() > 1) {
        auto it = numTaken.begin();
        int product = 1;
        for (int i = 0; i < 2; i++) {
          product *= it->second;
          it++;
        }
        sum += product;
      }
    }
    return sum;
  }

  void runExample() {
    vector<string> in = {"467..114..", "...*......", "..35..633.", "......#...",
                         "617*......", ".....+.58.", "..592.....", "......755.",
                         "...$.*....", ".664.598.."};
    cout << "Part1: " << part1(in) << " expected: 4361" << endl;
    cout << "Part2: " << part2(in) << endl;
  }

  void run() {
    auto in = Utils::readInput("Day3.txt");
    cout << "Part1: " << part1(in) << endl;
    cout << "Part2: " << part2(in) << endl;
  }
};
