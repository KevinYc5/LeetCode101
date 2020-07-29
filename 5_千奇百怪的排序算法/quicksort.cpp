#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r){
	if(l + 1 >= r){
		return;
	}
	int first = 0, last = r - 1, key = nums[first];
	while(first < last){
		while(first < last && nums[last] >= key){
			--last;
		}
		nums[first] = nums[last];
		while(first < last && nums[first] <= key){
			++first;
		}
		nums[last] = nums[first];
	}
	nums[last] = key;
	quick_sort(nums, l, first);
	quick_sort(nums, first + 1, r);
}

//
// Created by Kevin on 2020/7/20 18:52.
// 求真求实，大气大为
//

