#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <limits.h>
#include <queue>

using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.empty() || matrix[0].empty()) return 0;
		int m = matrix.size(), n = matrix[0].size(), maxsize = 0;
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for(int i = 1; i < m; ++i){
			for(int j = 1; j < n; ++j){
				if(matrix[i][j] == '1'){
					dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
					maxsize = max(maxsize, dp[i][j]);
				}
			}
		}
		return maxsize*maxsize;
	}
};
//
// Created by Kevin on 2020/8/1 18:00.
// 求真求实，大气大为
//

