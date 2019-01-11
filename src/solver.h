#ifndef SOLVER_H__
#define SOLVER_H__
#include "puzzle.h"

namespace sudoku {
// Puzzle forward declaration

/**
 * Solves the given Sudoku puzzle, returning a solved puzzle.
 *
 * @param p Sudoku Puzzle object
 * @return solved Puzzle object
 */
Puzzle solve(Puzzle p);
}  // namespace sudoku
#endif  // SOLVER_H__
