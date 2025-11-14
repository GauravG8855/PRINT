#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> allSolutions;

bool isSafe(vector<vector<int>> &board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

int solveNQueens(int row, vector<vector<int>> &board, vector<int> &positions) {
    if (row == n) {
        allSolutions.push_back(positions);
        return 1;
    }

    int total = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            positions[row] = col;
            total += solveNQueens(row + 1, board, positions);
            board[row][col] = 0;
        }
    }
    return total;
}

void printBoard(const vector<int> &positions) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (j == positions[i] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> positions(n, -1);

    int totalSolutions = solveNQueens(0, board, positions);
    cout << "\nTotal number of solutions: " << totalSolutions << endl;

    for (int i = 0; i < (int)allSolutions.size(); i++) {
        cout << "\nSolution " << i + 1 << ": ";
        for (int col : allSolutions[i])
            cout << col << " ";
        cout << endl;

        cout << "\nBoard representation:\n";
        printBoard(allSolutions[i]);
        cout << "-----------------------------\n";
    }

    return 0;
}
