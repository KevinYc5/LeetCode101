#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
	    backtracking(nums, 0, ans);
	    return ans;
    }
    void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
    	if(level == nums.size() - 1)
    		ans.push_back(nums);
    	for(int i = level; i < nums.size(); ++i){
    		swap(nums[level], nums[i]);
    		backtracking(nums, level + 1, ans);
    		swap(nums[level], nums[i]);
    	}
    }
};
//
// Created by Kevin on 2020/7/25 17:53.
// 求真求实，大气大为
//

