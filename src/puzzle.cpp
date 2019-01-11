#include "puzzle.h"
#include <algorithm>
#include <map>
#include <memory>
#include <ostream>
#include <unordered_set>
#include <vector>
#include "solver.h"

namespace sudoku {

std::ostream &operator<<(std::ostream &os, const sudoku::Puzzle &p) {
  int count = 0;
  for (int i = 0; i < 9; ++i) {
    for (int i = 0; i < 9 * 4; ++i) {
      if (i % 4 == 0)
        std::cout << '+';
      else
        std::cout << "-";
    }
    std::cout << "+\n|";
    for (int j = 0; j < 9; ++j) {
      const auto x = p.puzzle_[i * 9 + j];
      if (x == 0) {
        os << "   |";
      } else {
        os << ' ' << x << " |";
      }
      if (j == 8) {
        os << "\n";
      }
    }
  }
  for (int i = 0; i < 9 * 4; ++i) {
    if (i % 4 == 0)
      std::cout << '+';
    else
      std::cout << "-";
  }
  std::cout << '+';
  return os;
}

bool Puzzle::IsValid() const {
  if (puzzle_.size() != 81) {
    return false;
  }
 for (auto it = puzzle_.begin(); it != puzzle_.end(); ++it) {
    if (*it < 0 || *it > 9) {
      return false;
    }
  }
  return true;
}

bool Puzzle::IsSolved() const {
  for (int i = 0; i < 81; ++i) {
    if (puzzle_[i] == 0) {
      return false;
    } else {
      auto cols = this->ValuesInCol(i);
      auto rows = this->ValuesInRow(i);
      auto blocks = this->ValuesInBlock(i);
      if (cols.size() == 9 | rows.size() == 9 | blocks.size() == 9) {
        return true;
      }
    }
  }

  return false;
}

std::vector<int> Puzzle::PossibleValues(int i) const {
  std::vector<int> v;
  auto cols = this->ValuesInCol(i);
  auto rows = this->ValuesInRow(i);
  auto blocks = this->ValuesInBlock(i);
  for (int i = 1; i < 10; ++i) {
    if (std::find(cols.begin(), cols.end(), i) != cols.end() |
        std::find(rows.begin(), rows.end(), i) != rows.end() |
        std::find(blocks.begin(), blocks.end(), i) != blocks.end()) {
    }  // pass
    else {
      v.push_back(i);
    }
  }
  return v;
}

std::unordered_set<int> Puzzle::ValuesInRow(int i) const {
  std::vector<int> temp;
  int j = 0;
  while (i % 9 != 0) {
    --i;
  }
  while (j < 9) {
    if (puzzle_[i] != 0) {
      temp.push_back(puzzle_[i]);
    }
    ++i;
    ++j;
  }

  return std::unordered_set<int>(temp.begin(), temp.end());
}

std::unordered_set<int> Puzzle::ValuesInCol(int i) const {
  std::vector<int> temp;
  int j = 0;
  while (i > 8) {
    i -= 9;
  }
  while (j < 9) {
    temp.push_back(puzzle_[i]);
    i += 9;
    ++j;
  }
  temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
  return std::unordered_set<int>(temp.begin(), temp.end());
}

std::unordered_set<int> Puzzle::ValuesInBlock(int i) const {
  std::vector<int> temp;
  int bound = ((i % 9) / 3) + 3 * (i / 27);
  std::map<int, int> bound_map = {{0, 0},  {1, 3},  {2, 6},  {3, 27}, {4, 30},
                                  {5, 33}, {6, 54}, {7, 57}, {8, 60}};
  auto find = bound_map.find(bound);
  int idx = find->second;
  for (int i = 1; i < 10; ++i) {
    if (i % 3 != 0) {
      temp.push_back(puzzle_[idx]);
      ++idx;
    } else {
      temp.push_back(puzzle_[idx]);
      idx += 7;
    }
  }
  temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
  return std::unordered_set<int>(temp.begin(), temp.end());
}
}