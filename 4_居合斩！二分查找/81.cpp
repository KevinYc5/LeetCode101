#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1, mid;
		while(l <= r){
			mid = (l + r)/2;
			if(nums[mid] == target){
				return true;
			}
			if(nums[mid] == nums[l]){ // 无法判断左右序列规律
				++l;
			} else if(nums[mid] <= nums[r]){  // 右侧为递增序列
				if(nums[mid] < target && target <= nums[r]){
					l = mid + 1;
				}else{
					r = mid - 1;
				}
			} else {    // 左侧为递增序列
				if(nums[l] <= target && target < nums[mid]){
					r = mid - 1;
				} else{
					l = mid + 1;
				}
			}
		}
		return  false;
	}
};

//
// Created by Kevin on 2020/7/19 12:36.
// 求真求实，大气大为
//

class Solution1 {
public:
	bool search(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (nums[mid] == target) {
				return true;
			}
			if (nums[start] == nums[mid]) { // 无法判断哪个区间是增序的
				++start;
			} else if (nums[mid] <= nums[end]) { // 右区间是增序的
				if (target > nums[mid] && target <= nums[end]) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			} else {
			// 左区间是增序的
				if (target >= nums[start] && target < nums[mid]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			}
		}
		return false;
	}
};