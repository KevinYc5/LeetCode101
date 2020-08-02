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
	int numDecodings(string s) {
		int n = s.size();
		if( n == 0 ) return n;
		int prev = s[0] - '0';
		if(prev == 0) return 0;
		vector<int> dp(n+1, 1);
		for(int i = 2; i <= n; ++i){
			int cur = s[i-1] - '0';
			if((prev == 0 || prev > 2) && cur == 0) return 0;
			if((prev == 1) || (prev == 2 && cur <= 6)){
				if(cur){
					dp[i] = dp[i-2] + dp[i-1];
				} else {
					dp[i] = dp[i-2];
				}
			} else {
				dp[i] = dp[i-1];
			}
			prev = cur;
		}
		return dp[n];
	}
};
//
// Created by Kevin on 2020/8/2 0:19.
// 求真求实，大气大为
//

