#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;



class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if(nums.empty())
			return vector<int>{-1, -1};
		int lower = lower_bound(nums, target);
		int upper = upper_bound(nums, target) - 1;
		if(lower == nums.size() || nums[lower] != target){
			return vector<int>{-1, -1};
		} else {
			return vector<int>{lower, upper};
		}
	}
	int lower_bound(vector<int>& nums, int target){ // 从数组二分查找第一个大于或等于target的数字
		int l = 0, r = nums.size(), mid;
		while(l < r){
			if(nums[mid] >= target){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		return l;
	}

	int upper_bound(vector<int>& nums, int target){ // 从数组二分查找第一个大于target的数字
		int l = 0, r = nums.size(), mid;
		while(l < r){
			if(nums[mid] > target){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		return l;
	}
};


//
// Created by Kevin on 2020/7/18 21:41.
// 求真求实，大气大为
//

