#include <chrono>
#include <iostream>
#include <vector>
#include "puzzle.h"
#include "solver.h"
#include "util.h"

using Puzzle = sudoku::Puzzle;

int main(int argc, char *argv[]) {
  using namespace sudoku;
  using steady_clock = std::chrono::steady_clock;
  using duration = std::chrono::duration<double>;
  std::cout << "Loading puzzles\n";
  auto puzzles = util::load_puzzles();
  std::cout << puzzles.size() << " puzzles loaded successfully\n";
  auto start = steady_clock::now();
  for (const auto &puzzle : puzzles) {
    std::cout << solve(puzzle);
  }
  auto stop = steady_clock::now();
  duration elapsed = stop - start;
  std::cout << "Solved " << puzzles.size() << " puzzles in " << elapsed.count()
            << "s\n";

  return 0;
}
