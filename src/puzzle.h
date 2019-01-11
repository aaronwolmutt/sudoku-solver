#ifndef PUZZLE_H__
#define PUZZLE_H__
#include <array>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace sudoku {
class Puzzle {
 public:
  // Takes a vector representation of a puzzle
  Puzzle(const std::vector<int>& p) : puzzle_(p) {}

  // Copy constructor
  Puzzle(const sudoku::Puzzle& p) {
    for (int i = 0; i < 81; ++i) {
      puzzle_.push_back(p.puzzle_[i]);
    }
  }

  friend ::std::ostream& operator<<(::std::ostream& os,
                                    const ::sudoku::Puzzle& p);

  // Returns true if puzzle is valid, false otherwise
  bool IsValid() const;

  // Returns true if puzzle is solved, false otherwise
  bool IsSolved() const;

  // Return a vector<int> of possible values for a given square
  std::vector<int> PossibleValues(int i) const;

  // Return the non-zero values in the row containing position i
  std::unordered_set<int> ValuesInRow(int i) const;

  // Return the non-zero values in the column containing position i
  std::unordered_set<int> ValuesInCol(int i) const;

  // Return the non-zero values in the 3x3 block containing position i
  std::unordered_set<int> ValuesInBlock(int i) const;

  // Access the ith element
  int& operator()(int i) { return puzzle_[i]; }

 private:
  std::vector<int> puzzle_;
};  // class Puzzle
}  // namespace sudoku

#endif  // PUZZLE_H__
