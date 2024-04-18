#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>

using namespace std;

class Solver {
    private:
        /*
        The sudoku board
        */
        vector<vector<string>> _board;
    public:
        /*
        Creates a new solver with a random, generated board
        */
        Solver();

        /*
        Creates a new solver with a given board
        */
        Solver(vector<vector<string>> board);

        /*
        Return whether the given board is valid or not
        */
        bool isValid(vector<vector<string>> board);

        /*
        Return the solved sudoku board, if the board is valid
        */
        vector<vector<string>> solveBoard(vector<vector<string>> board);

        /*
        Generate a random, valid sudoku board. Returns 17/81 spots filled
        */
        vector<vector<string>> generateRandomBoard();

        /*
        Backtracking algorithm to fill the board
        */
        vector<vector<string>> backtrack();
};

#endif