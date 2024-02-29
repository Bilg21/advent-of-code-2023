#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Utils {
public:
  // Function to trim leading and trailing spaces from a string
  static string trim(string str) {
    // Find the first non-space character from the beginning of the string
    int start = str.find_first_not_of(" ");

    // If no non-space character is found, return an empty string
    if (start == string::npos) {
      return "";
    }

    // Find the last non-space character from the end of the string
    int end = str.find_last_not_of(" ");

    // Return the substring from the first non-space character to the last
    // non-space character
    return str.substr(start, end - start + 1);
  }

  static vector<string> readInput(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
      throw runtime_error("Failed to open input file: " + filename);
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
      lines.push_back(line);
    }

    file.close();
    return lines;
  }

  static vector<string> splitByIterator(const string &str,
                                        const string &delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
      pos = str.find(delim, prev);
      if (pos == string::npos)
        pos = str.length();
      string token = str.substr(prev, pos - prev);
      if (!token.empty())
        tokens.push_back(token);
      prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
  }

  static vector<string> splitByStream(string s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
    }
    return tokens;
  }

  static vector<string> splitCStyle(const string s, char delimeter) {
    vector<string> tokens;
    char *next_token;
    char *ch = strtok_s(const_cast<char *>(s.c_str()), &delimeter, &next_token);
    while (ch) {
      tokens.push_back(string(ch));
      ch = strtok_s(nullptr, ": :, ; ", &next_token);
    }
    return tokens;
  }
};

#endif
