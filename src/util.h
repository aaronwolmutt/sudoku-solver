#ifndef UTIL_H__
#define UTIL_H__
#include <string>
#include <vector>

namespace sudoku {
class Puzzle;
namespace util {

/**
 * Returns a vector of ints from the given space separated string. A value of 0
 * represents a missing value.
 *
 * @param s string representation of the puzzle
 * @returns std::vector<int> representation of puzzle
 */
std::vector<int> puzzle2vec(const std::string& s);

/**
 * Creates a vector of Puzzle objects using data read from stdin
 */
std::vector<Puzzle> load_puzzles();

}  // namespace util
}  // namespace sudoku

#endif  // UTIL_H__
