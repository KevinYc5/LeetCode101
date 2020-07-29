#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		if(numBottles == 0 || numExchange == 0)
			return numBottles;
		int ans = numBottles;
		int num_ex;
		do{
			num_ex = numBottles/numExchange;
			numBottles = numBottles + num_ex - num_ex * numExchange;
			ans += num_ex;
		}while(num_ex > 0);
		return ans;
	}
};
//
// Created by Kevin on 2020/7/19 10:47.
// 求真求实，大气大为
//

