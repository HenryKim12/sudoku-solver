#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>

using namespace std;

class Solver {
    private:
        /*
        The sudoku board
        */
        vector<vector<int>> _board;
    public:
        /*
        Creates a new solver with a random, generated board
        */
        Solver();

        /*
        Creates a new solver with a given board
        */
        Solver(vector<vector<int>> board);

        /*
        Return whether the given board is valid or not
        */
        bool isValid(vector<vector<int>> board);

        /*
        Return the solved sudoku board, if the board is valid
        */
        vector<vector<int>> solveBoard(vector<vector<int>> board);

        /*
        Generate a random, valid sudoku board. Returns 17/81 spots filled
        */
        vector<vector<int>> generateRandomBoard();

        /*
        Backtracking algorithm to fill the board
        */
        vector<vector<int>> backtrack();
};

#endif