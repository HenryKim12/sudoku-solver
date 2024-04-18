#include "solver.hpp"
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <map>
#include <tuple>
#include <set>

using namespace std;

Solver::Solver() {
    _board = vector<vector<string>>();
}

Solver::Solver(vector<vector<string>> start_board) {
    _board = start_board;
}

bool Solver::isValid(vector<vector<string>> board) {
    
    int numRows = size(board);
    int numCols = size(board[0]);
    unordered_map<int, set<string>> rows; 
    unordered_map<int, set<string>> cols;
    map<tuple<int, int>, set<string>> squares;
    try {
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < numCols; c++) {
                string value = board[r][c];
                if (value == "") {
                    continue;
                }
                int rowIndex = r / 3;
                int colIndex = c / 3;
                tuple<int, int> pos = make_tuple(rowIndex, colIndex);

                // grab set of numbers in the row r
                auto rowIter = rows.find(r);
                set<string> currRow;
                if (rowIter != rows.end()) {
                    currRow = rowIter->second;
                }
                
                // grab set of numbers in the col c
                auto colIter = cols.find(c);
                set<string> currCol;
                if (colIter != cols.end()) {
                    currCol = colIter->second;
                }

                // grab set of numbers in the square pos
                auto squareIter = squares.find(pos);
                set<string> currSquare;
                if (squareIter != squares.end()) {
                    currSquare = squareIter->second;
                }

                // if curr value is in either of row, col, or square, it is a dupe -> return false
                if (currRow.find(value) != currRow.end() || currCol.find(value) != currCol.end() || currSquare.find(value) != currSquare.end()) {
                    return false;
                }
            }
        }
    } catch (exception err) {
        cout << "error" << endl;
    }
    
    return true;
}

vector<vector<string>> Solver::solveBoard(vector<vector<string>> board) {
    return board;
}

vector<vector<string>> Solver::generateRandomBoard() {
    return;
} 

vector<vector<string>> Solver::backtrack() {
    return;
}