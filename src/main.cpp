#include <iostream>
#include <string>

//#include "solver.hpp"
#include <vector>
#include <unordered_map>
#include <map>
#include <tuple>
#include <set>

using namespace std;

class Solver {
    public: 
        std::vector<std::vector<int>> board;
        Solver(std::vector<std::vector<int>> startBoard);
        bool isValid(vector<vector<int>> startBoard);
};

Solver::Solver(std::vector<std::vector<int>> startBoard) {
    board = startBoard;
}

bool Solver::isValid(std::vector<std::vector<int>> startBoard) {
    int numRows = size(startBoard);
    int numCols = size(startBoard[0]);

    unordered_map<int, set<int>> rows; 
    unordered_map<int, set<int>> cols;
    map<tuple<int, int>, set<int>> squares;

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            int value = startBoard[r][c];
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

int main() //int argc, char *argv[]
{
    vector<vector<int> > board(9);
    int rows = 9;
    int cols = 9;
    board.resize(rows);
    for (int i = 0; i < rows; ++i) {
        board[i].resize(cols);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = i * cols + j;
        }
    }

    Solver solver(board);
    bool valid = solver.isValid(board);
}