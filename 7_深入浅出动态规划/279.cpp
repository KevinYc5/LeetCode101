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
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j * j <= n; ++j){
				if(dp[i - j*j] + 1 < dp[i]){
					dp[i] = dp[i - j*j] + 1;
				}
			}
		}
		return dp[n];
	}
};
//
// Created by Kevin on 2020/8/2 0:12.
// 求真求实，大气大为
//

