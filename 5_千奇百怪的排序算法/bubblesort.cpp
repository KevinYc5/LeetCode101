#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
void bubble_sort(vector<int>nums, int n)
{
	bool swaped;
	for(int i = 0; i < n; i++){
		swaped = false;
		for(int j = 1; j < n - i + 1; j++){
			if(nums[j] < nums[j-1]){
				swap(nums[j], nums[j-1]);
				swaped = true;
			}
		}
		if(!swaped){
			break;
		}
	}

}
//
// Created by Kevin on 2020/7/22 14:57.
// 求真求实，大气大为
//

