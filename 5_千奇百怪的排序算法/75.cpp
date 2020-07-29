#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int l = 0, r = nums.size()-1;
		while(l < r){
			while(nums[l] != 1 && l < r) ++l;
			while(nums[r] != 0 && l < r) --r;
			if(l >= r) break;
			swap(nums[r], nums[l]);
			--r; ++l;
		}
		l = 0;
		r = nums.size()-1;
		while(l < r){
			while(nums[l] != 2 && l < r) ++l;
			while(nums[r] != 0 && l < r) --r;
			if(l >= r) break;
			swap(nums[r], nums[l]);
			--r; ++l;
		}
		l = 0;
		r = nums.size()-1;
		while(l < r){
			while(nums[l] != 2 && l < r) ++l;
			while(nums[r] != 1 && l < r) --r;
			if(l >= r) break;
			swap(nums[r], nums[l]);
			--r; ++l;
		}
	}
};
//
// Created by Kevin on 2020/7/24 9:41.
// 求真求实，大气大为
//

