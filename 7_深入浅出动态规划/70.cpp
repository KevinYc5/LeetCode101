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
	int climbStairs(int n) {
		if(n <= 2) return n;
		int pre2 = 1, pre1 = 2, cur;
		for(int i = 3; i <= n; ++i){
			cur = pre1 + pre2;
			pre1 = pre2;
			pre2 = cur;
		}
		return cur;
	}
};

class Solution0 {
public:
	int climbStairs(int n) {
		if(n <= 2){
			return n;
		}
		vector<int> dp(n+1, 1);
		for(int i = 2; i <= n; ++i){
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}
};
//
// Created by Kevin on 2020/8/1 8:32.
// 求真求实，大气大为
//

