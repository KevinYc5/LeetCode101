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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		backtracking(nums, 0, ans);
		return ans;
	}
	void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
		if(level == nums.size() - 1){
			ans.push_back(nums);
		}
		unordered_set<int>before;
		for(int i = level; i < nums.size(); ++i){
			if(i != level && (nums[i] == nums[level] || before.count(nums[i]))){

			} else {
				swap(nums[level], nums[i]);
				before.insert(nums[level]);
				backtracking(nums, level + 1, ans);
				swap(nums[level], nums[i]);
			}
		}
	}
};
//
// Created by Kevin on 2020/7/29 19:17.
// 求真求实，大气大为
//
