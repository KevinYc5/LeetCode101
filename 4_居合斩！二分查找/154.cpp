#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size()-1, min = 1000;
		while(l <= r){
			int mid = l + (r-l)/2;
			if(nums[mid] < min){
				min = nums[mid];
			}
			if(nums[mid] == nums[l]){
				++l;
			}else{
				if(nums[mid] <= nums[r]){
					if(nums[mid] < min)
						min = nums[mid];
					r = mid - 1;
				} else {
					if(nums[l] < min)
						min = nums[l];
					l = mid + 1;
				}
			}
		}
		return min;
	}
};
//
// Created by Kevin on 2020/7/20 11:21.
// 求真求实，大气大为
//

