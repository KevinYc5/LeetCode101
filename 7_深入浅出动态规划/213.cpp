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
	int rob(vector<int>& nums) {
		if(nums.empty()) return 0;
		int n = nums.size();
		if(n == 1) return nums[0];
		int pre1_0 = 0, pre1_1 = 0, pre2_0 = 0, pre2_1 = 0, cur_0, cur_1;
		for(int i = 0; i < n-1; ++i){
			cur_0 = max(pre2_0 + nums[i], pre1_0);
			pre2_0 = pre1_0;
			pre1_0 = cur_0;
		}
		for(int i = 1; i < n; ++i){
			cur_1 = max(pre2_1 + nums[i], pre1_1);
			pre2_1 = pre1_1;
			pre1_1 = cur_1;
		}

		return max(cur_1, cur_0);
	}
};
//
// Created by Kevin on 2020/9/7 17:24.
// 求真求实，大气大为
//

