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
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for(int i = 0; i <= m; ++i){
			for(int j = 0; j <=n; ++j){
				if(i == 0){
					dp[i][j] = i;
				} else if(j == 0){
					dp[i][j] = j;
				} else {
					dp[i][j] = min(dp[i-1][j-1] + (word1[i] == word2[j] ? 0:1),
							min(dp[i-1][j] + 1, dp[i][j-1] + 1));
				}
			}
		}
		return dp[m][n];
	}
};
//
// Created by Kevin on 2020/8/6 14:13.
// 求真求实，大气大为
//

