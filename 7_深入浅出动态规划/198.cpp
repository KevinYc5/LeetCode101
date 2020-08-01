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
	int rob(vector<int>& nums) {
		if(nums.empty()) return 0;
		int n = nums.size();
		if(n == 1) return nums[0];
		int pre1 = 0, pre2 = 0, cur;
		for(int i = 0; i < n; ++i){
			cur = max(pre2 + nums[i], pre1);
			pre2 = pre1;
			pre1 = cur;
		}
		return cur;
	}
};
//
// Created by Kevin on 2020/8/1 9:24.
// 求真求实，大气大为
//

