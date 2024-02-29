#pragma once
#include "utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct record {
  int id;
  vector<tuple<int, int, int>> sets;
};

class Day2 {
public:
  vector<record> parseInput(vector<string> &gameRecords) {
    vector<record> records;

    for (string &record : gameRecords) {
      vector<string> tokens = Utils::splitByStream(record, ':');

      string &header = tokens[0];
      string &body = tokens[1];

      struct record r;
      r.id = stoi(Utils::splitByStream(header, ' ')[1]);

      vector<string> sets = Utils::splitByStream(body, ';');
      for (string &set : sets) {
        vector<string> cubes = Utils::splitByStream(set, ',');
        int red = 0, green = 0, blue = 0;
        for (string &cube : cubes) {
          vector<string> cubeParts =
              Utils::splitByStream(Utils::trim(cube), ' ');
          if (cubeParts[1] == "red") {
            red = stoi(cubeParts[0]);
          } else if (cubeParts[1] == "green") {
            green = stoi(cubeParts[0]);
          } else if (cubeParts[1] == "blue") {
            blue = stoi(cubeParts[0]);
          }
        }
        r.sets.emplace_back(red, green, blue);
      }
      records.push_back(r);
    }

    return records;
  }

  int part1(vector<string> &gameRecords) {
    int idSum = 0;

    int redCubes = 12, greenCubes = 13, blueCubes = 14;

    vector<record> records = parseInput(gameRecords);

    for (record &r : records) {
      bool valid = true;
      // cout << "id:" << r.id << endl;
      int i = 1;
      for (auto &t : r.sets) {
        int &reds = std::get<0>(t);
        int &greens = std::get<1>(t);
        int &blues = std::get<2>(t);
        // cout << "set " << i++ << " -> red:" << reds << " green:" << greens <<
        // " blue:" << blues << endl;

        if (reds > redCubes || greens > greenCubes || blues > blueCubes)
          valid = false;
      }

      if (valid)
        idSum += r.id;
    }

    return idSum;
  }

  int part2(vector<string> &gameRecords) {
    int sumPowers = 0;

    vector<record> records = parseInput(gameRecords);

    for (record &r : records) {
      int redCubes = 0, greenCubes = 0, blueCubes = 0;
      for (auto &t : r.sets) {
        int &reds = std::get<0>(t);
        int &greens = std::get<1>(t);
        int &blues = std::get<2>(t);

        redCubes = max(redCubes, reds);
        greenCubes = max(greenCubes, greens);
        blueCubes = max(blueCubes, blues);
      }
      int power = redCubes * greenCubes * blueCubes;
      sumPowers += power;
    }

    return sumPowers;
  }

  void runExample() {
    vector<string> in = {
        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
        "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 "
        "red",
        "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 "
        "red",
        "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
    cout << "Part1: " << part1(in) << endl;
    cout << "Part2: " << part2(in) << endl;
  }

  void run() {
    vector<string> in = Utils::readInput("Day2.txt");
    cout << "Part1: " << part1(in) << endl;
    cout << "Part2: " << part2(in) << endl;
  }
};
