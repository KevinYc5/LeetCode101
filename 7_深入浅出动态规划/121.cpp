#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <limits.h>
#include <queue>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sell = 0, buy = INT_MAX, n = prices.size();
		for(int i = 0; i < n; ++i){
			buy = min(prices[i], buy);
			sell = max(prices[i] - buy, sell);
		}
		return sell;
	}
};
//
// Created by Kevin on 2020/8/6 21:43.
// 求真求实，大气大为
//

