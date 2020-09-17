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
//class Solution {
//public:
//	int minDistance(string word1, string word2) {
//		vector<vector<int>>memo(word2.size(), vector<int>(word1.size(), 0));
//		return word1.size() + word2.size() - 2 * lcs(word1, word2, word1.size(), word2.size(), memo);
//	}
//	int lcs(string s1, string s2, int m, int n, vector<vector<int>> memo){
//		if(m == 0 || n == 0){
//			return 0;
//		}
//		if(memo[m][n] > 0){
//			return memo[m][n];
//		} else if(s1[m-1] == s2[n-1]){
//			memo[m][n] = lcs(s1, s2, m - 1, n - 1, memo) + 1;
//		} else {
//			memo[m][n] = max(lcs(s1, s2, m-1, n, memo), lcs(s1, s2, m, n - 1, memo));
//		}
//		return memo[m][n];
//	}
//};
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for(int i = 1; i <= m; ++i){
			for(int  j = 1; j <= n; ++j){
				if(word1[i-1] == word2[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		return m + n - 2 * dp[m][n];
	}
};
//
// Created by Kevin on 2020/9/14 21:15.
// 求真求实，大气大为
//

