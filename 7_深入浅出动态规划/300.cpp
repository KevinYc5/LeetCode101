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
	int lengthOfLIS(vector<int>& nums) {
		int maxLength = 0, n = nums.size();
		if(n < 2) return n;
		vector<int> dp(n, 1);
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < i; ++j){
				if(nums[i] > nums[j]){
					dp[i] = max(dp[i], dp[j]);
				}
			}
			maxLength = max(maxLength, dp[i]);
		}
		return maxLength;
	}
};

//  二分查找
class Solution0 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if(n < 2) return n;
		vector<int> dp;
		dp.push_back(nums[0]);
		for(int i = 1; i < n; ++i){
			if(nums[i] > dp.back())
				dp.push_back(nums[i]);
			else {
				auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
				*itr = nums[i];
			}
		}
		return dp.size();
	}
};
//
// Created by Kevin on 2020/8/2 8:52.
// 求真求实，大气大为
//

