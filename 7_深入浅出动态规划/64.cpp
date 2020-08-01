#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(i == 0 && j == 0){
					dp[i][j] = grid[i][j];
				} else if(i == 0){
					dp[i][j] = dp[i][j - 1] + grid[i][j];
				} else if(j == 0){
					dp[i][j] = dp[i-1][j] + grid[i][j];
				} else {
					dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
				}
			}
		}
		return dp[m-1][n-1];
	}
};
// 空间压缩
class Solution0 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n, 0);
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(i == 0 && j == 0){
					dp[j] = grid[i][j];
				} else if(i == 0){
					dp[j] = dp[j - 1] + grid[i][j];
				} else if(j == 0){
					dp[j] = dp[j] + grid[i][j];
				} else {
					dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
				}
			}
		}
		return dp[n-1];
	}
};
//
// Created by Kevin on 2020/8/1 11:00.
// 求真求实，大气大为
//

