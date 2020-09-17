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
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int dp = 0;
		int res = nums[0];
		for(int i = 0; i < n; ++i){
			dp = max(dp + nums[i], nums[i]);
			res = max(res, dp);
		}
		return res;
	}
};
//
// Created by Kevin on 2020/9/7 18:29.
// 求真求实，大气大为
//
