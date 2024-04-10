#include "solver.hpp"
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <map>
#include <tuple>
#include <set>

using namespace std;

Solver::Solver() {
    board = vector<vector<int>>();
}

Solver::Solver(vector<vector<int>> start_board) {
    board = start_board;
}

bool Solver::isValid(vector<vector<int>> board) {
    int numRows = sizeof(board);
    int numCols = sizeof(board[0]);

    unordered_map<int, set<int>> rows; 
    unordered_map<int, set<int>> cols;
    map<tuple<int, int>, set<int>> squares;

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            int value = board[r][c];
            int rowIndex = r / 3;
            int colIndex = c / 3;
            tuple<int, int> pos = make_tuple(rowIndex, colIndex);

            auto rowIter = rows.find(r);
            set<int> currRow;
            if (rowIter != rows.end()) {
                currRow = rowIter->second;
            }
            
            auto colIter = cols.find(c);
            set<int> currCol;
            if (colIter != cols.end()) {
                currCol = colIter->second;
            }

            auto squareIter = squares.find(pos);
            set<int> currSquare;
            if (squareIter != squares.end()) {
                currSquare = squareIter->second;
            }

            if (currRow.find(value) != currRow.end() || currCol.find(value) != currCol.end() || currSquare.find(value) != currSquare.end()) {
                return false;
            }
        }
    }
    return true;
}

// vector<vector<int>> Solver::solveBoard(vector<vector<int>> board) {
//     return board;
// }

// vector<vector<int>> Solver::generateRandomBoard() {
//     return;
// } 

// vector<vector<int>> Solver::backtrack() {
//     return;
// }