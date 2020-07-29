#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if(board.empty() || board[0].empty())
			return;
		int m = board.size(), n = board[0].size();
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O'){
					dfs(board, i, j, m, n);
				}
			}
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'Z')
					board[i][j] = 'O';
			}
		}
	}
	void dfs(vector<vector<char>>& board, int i,int j, int m, int n){
		if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || board[i][j] == 'Z'){
			return;
		}
		board[i][j] = 'Z';
		dfs(board, i + 1, j, m, n);
		dfs(board, i - 1, j, m, n);
		dfs(board, i, j + 1, m, n);
		dfs(board, i, j - 1, m, n);
	}
};
//
// Created by Kevin on 2020/7/28 11:35.
// 求真求实，大气大为
//

