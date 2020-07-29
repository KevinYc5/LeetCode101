#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int l = 0, r = nums.size()-1, target = nums.size()-k;
		while(l < r){
			int mid = quickSelection(nums, l, r);
			if(mid == target){
				return nums[mid];
			}
			if(mid < target){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return nums[l];
	}
	int quickSelection(vector<int>& nums, int l, int r) {
		int i = l+1, j = r;
		while(true){
			while(i < r && nums[i] <= nums[l]){
				++i;
			}
			while(j > l && nums[j] >= nums[l]){
				--j;
			}
			if(i >= j)
				break;
			else
				swap(nums[i], nums[j]);
		}
		swap(nums[j], nums[l]);
		return j;
	}
};
//
// Created by Kevin on 2020/7/22 17:30.
// 求真求实，大气大为
//

