#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int l = 0, r = nums.size()-1;
		if(r == l){
			return nums[l];
		}
		while(l <= r){
			int mid = l + (r-l)/2;
			if(   (mid == 0 && nums[mid] != nums[mid+1])
			      ||(mid == nums.size()-1 && nums[mid] != nums[mid-1])
			      ||(nums[mid] != nums[mid-1]  && nums[mid] != nums[mid+1]) ){
				return nums[mid];
			}
			if( mid % 2 ){
				// 奇数
				if(nums[mid] == nums[mid+1]){
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			} else {
				// 偶数
				if(nums[mid] == nums[mid-1]){
					r = mid - 2;
				} else {
					l = mid + 1;
				}
			}
		}
		return -1;
	}
};
//
// Created by Kevin on 2020/7/20 11:46.
// 求真求实，大气大为
//

