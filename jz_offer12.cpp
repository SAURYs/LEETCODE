/*

    对每一个位置进行遍历，对某一点上下左右四个座标点判断其相邻的这4个点是不是在路径字符串中对应的下一个字符，若不是，则回溯。
    回溯的返回为真条件：最后的字符串长度为目标字符串长度。

*/
#include <vector>
#include <string>
#include<iostream>
#include<stack>
using std::string;
using std::vector;
bool exist(vector<vector<char>> &board, string word)
{
    int n_row = board.size();
    if (n_row == 0)
        return false;
    int n_col = board[0].size();
    vector<bool> tmp(n_col, false);
    vector<vector<bool>> visted(n_row, tmp);
    int pathLength = 0;
    for(int i = 0;i<n_row;++i){
        for(int j=0;j<n_col;++j){
            if(dfs(board,word,i,j,n_row,n_col,pathLength,visted)) return true;
        }
    }
    return false;
}
bool dfs(vector<vector<char>> &board,
         string &word,
         int row,
         int col,
         int n_row,
         int n_col,
         int pathLength,
         vector<vector<bool>> &visted)
{

    bool hasPath = false;
    if (pathLength == word.size())
        return true;
    if (row >= 0 && row < n_row && col >= 0 && col < n_col && board[row][col] == word[pathLength] && !visted[row][col])
    {
        ++pathLength;
        visted[row][col] = true;

        hasPath = dfs(board, word, row, col - 1, n_row, n_col, pathLength, visted) ||
                  dfs(board, word, row, col + 1, n_row, n_col, pathLength, visted) ||
                  dfs(board, word, row + 1, col, n_row, n_col, pathLength, visted) ||
                  dfs(board, word, row - 1, col, n_row, n_col, pathLength, visted);
        if (!hasPath)
        {
            pathLength--;
            visted[row][col] = false;
        }
    }
    return hasPath;
}
