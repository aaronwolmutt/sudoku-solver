#include <chrono>
#include <iostream>
#include <vector>

#include "puzzle.h"
#include "solver.h"

namespace sudoku {

bool solution_search(Puzzle &p, int i) {
  // Stop if we are at the end
  if (i == 81) return p.IsValid() && p.IsSolved();
  // Move to next position if this position is already assigned a value
  else if (p(i) != 0)
    return solution_search(p, i + 1);

  const auto values = p.PossibleValues(i);

  // Check that we have possible values for current position
  if (values.empty()) {
    return false;
  }
  for (auto &x : values) {
    p(i) = x;
    if (solution_search(p, i + 1)) {
      return true;
    }
  }

  // Back out current attempt
  p(i) = 0;
  return false;
}

Puzzle solve(Puzzle p) {
  // Check that puzzle is solvable
  if (!p.IsValid()) return p;

  // Time how long it takes to find a solution
  auto start = std::chrono::steady_clock::now();
  auto found_solution = solution_search(p, 0);
  auto stop = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed = stop - start;
  double runtime = elapsed.count();

  if (found_solution) {
    std::cout << "Found solution in " << runtime << " seconds\n";
  } else {
    std::cout << "Unable to find solution after " << runtime << " seconds \n";
  }

  return p;
}

}  // namespace sudoku
