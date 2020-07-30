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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> comb;
		int sum = 0;
		backtracking(candidates, target, ans, comb, sum, 0);
		return ans;
	}
	void backtracking(vector<int>& candidates, int target,
			vector<vector<int>>& ans,vector<int>& comb, int& sum, int pos){
		if(sum > target){   // 退出递归
			return;
		}
		if(sum == target){  // 退出递归
			ans.push_back(comb);
			return;
		}
		int before = 100;   // 避免重复
		for(int i = pos; i < candidates.size(); ++i){
			if(candidates[i] != before){
				comb.push_back(candidates[i]); sum += candidates[i];
				before = candidates[i];
				backtracking(candidates, target, ans, comb, sum, i+1);  // 递归
				comb.erase(comb.end() - 1); sum -= candidates[i];
				// 注意!! end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.
			}
		}
	}
};


//
// Created by Kevin on 2020/7/30 12:17.
// 求真求实，大气大为
//

