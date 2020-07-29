#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0, r = numbers.size()-1, sum;
		while(l < r){
			sum = numbers[l] + numbers[r];
			if(sum == target)
				break;
			if(sum < target)
				++l;
			else
				--r;
		}
		return vector<int>{l+1, r+1};
	}
};
//
// Created by Kevin on 2020/7/17 9:55.
// 求真求实，大气大为
//

