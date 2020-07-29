#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
void merge_sort(vector<int>nums, int l ,int r, vector<int>temp)
{
	int m = l + (r - l)/2;  // 左闭右开
	merge_sort(nums, l, m, temp);
	merge_sort(nums, m, r, temp);
	// conquer, 双指针
	int p = l, q = m, i = l;
	while(p < m && q < r){
		if(q >= r || (q < m && nums[q] < nums[p])){
			temp[i++] = nums[p++];
		}else{
			temp[i++] = nums[q++];
		}
	}
	for(int i = l; i < r; i++){
		nums[i] = temp[i];
	}
}
//
// Created by Kevin on 2020/7/22 10:59.
// 求真求实，大气大为
//

