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
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool> dp(n+1, false);
		dp[0] = true;
		for(int i = 1; i <= n; ++i){
			for(const string& word : wordDict){
				int len = word.size();
				if(i >= len && s.substr(i - len, len) == word){
					dp[i] = dp[i - len] || dp[i];
				}
			}
		}
		return dp[n];
	}
};
//
// Created by Kevin on 2020/8/2 8:36.
// 求真求实，大气大为
//

