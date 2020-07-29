#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void selectionsort(vector<int>nums, int n){
	int mid;
	for(int i = 0; i < n-1; i++){
		mid = i;
		for(int j = i; j < n; j++){
			if(nums[j] < nums[mid])
				mid = j;
		}
		swap(nums[mid], nums[i]);
	}
}

//
// Created by Kevin on 2020/7/22 17:09.
// 求真求实，大气大为
//

