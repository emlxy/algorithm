#include "stdafx.h"
#include <string>
#include <vector>

/*
解数独问题.
主要还是回溯算法
*/

class Solution037 {
public:
    void test()
    {
        std::vector<std::vector<char>> board = 
        {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        solveSudoku(board);
    }
    bool isvalid(std::vector<std::vector<char>>& board, int row, int col, char c, int n)
    {
        for(int i = 0; i<n; i++)
        {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c) return false;
        }
        return true;
    }

    bool backtrack(std::vector<std::vector<char>>& board, int row, int col, int n)
    {
        if(col == n)
        {
            return backtrack(board, row+1, 0, n);
        }
        if(row == n)
        {
            return true;
        }
        if(board[row][col] != '.')
        {
            return backtrack(board, row, col+1, n);
        }

        for(char c = '1'; c <= '9'; c++)
        {
            if(!isvalid(board, row, col, c, n)) continue;
            board[row][col] = c;
            if(backtrack(board, row, col+1, n)) return true;
            board[row][col] = '.';
        }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        int n = board.size();

        backtrack(board, 0, 0, n);
    }
};
