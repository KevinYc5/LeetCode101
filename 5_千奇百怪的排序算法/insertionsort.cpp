#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void insertion_sort(vector<int> nums, int n)
{
	for(int i = 0; i < n; i++){
		for(int j = i; j > 0 && nums[j] < nums[j-1]; j--){
			swap(nums[j], nums[j-1]);
		}
	}
}
//
// Created by Kevin on 2020/7/22 12:02.
// 求真求实，大气大为
//

