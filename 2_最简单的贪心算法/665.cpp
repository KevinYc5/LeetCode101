#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int cnt = 0;    // 记录"违法"次数, 超过1则return false
		int n = nums.size();
		for(int i = 0; i < n-1; i++){
			if(nums[i] > nums[i+1]){    // 尝试局部最优
				if(i > 0 && nums[i-1] > nums[i+1] && i < n-2 && nums[i] > nums[i+2]) return false;
				cnt++;
				if(cnt >= 2) return false;
			}
		}
		return true;
	}
};

//
// Created by Kevin on 2020/7/16.
//

