#include "util.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include "puzzle.h"

namespace sudoku {
namespace util {

std::vector<int> puzzle2vec(const std::string &s) {
  std::vector<int> res;
  for (auto it = s.begin(); it != s.end(); ++it) {
    char s = *it;
    int i = s - '0';
    res.push_back(i);
  }
  return res;
}

std::vector<Puzzle> load_puzzles() {
  std::vector<Puzzle> p;
  std::string data;
  std::string pass;
  std::cin >> pass;
  // std::cout << pass;
  for (int i = 0; i < 49; ++i) {
    std::cin >> data;
    std::ostringstream ss(data);
    // std::cout << data << "\n";
    std::vector<int> v = puzzle2vec(data);
    Puzzle puzz = Puzzle(v);
    p.push_back(puzz);
  }

  return p;
}

}  // namespace util
}  // namespace sudoku
