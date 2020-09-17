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
	int findLongestChain(vector<vector<int>>& pairs) {
		int n = pairs.size();
		int maxlen = 0;
		vector<int> dp(n, 1);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		return dp[n-1];
	}
};
//
// Created by Kevin on 2020/9/14 21:48.
// 求真求实，大气大为
//

