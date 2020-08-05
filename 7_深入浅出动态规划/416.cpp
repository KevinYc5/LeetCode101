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

// 空间压缩
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum%2) return false;
		int target = sum/2, n = nums.size();
		vector<bool> dp(target+1, false);
		dp[0] = true;
		for(int i = 1; i <= n; ++i){
			for(int j = target; j >= nums[i-1]; --j){
				dp[j] = dp[j] || dp[j - nums[i-1]];
			}
		}
		return dp[target];
	}
};


class Solution0 {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum%2) return false;
		int target = sum/2, n = nums.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(target+1, false));
		for(int i = 0; i < n+1; ++i){
			dp[i][0] = true;
		}
		for(int i = 1; i <= n; ++i){
			for(int j = nums[i - 1]; j <= target; ++j){
				dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
			}
		}
		return dp[n][target];
	}
};
//
// Created by Kevin on 2020/8/2 12:00.
// 求真求实，大气大为
//

