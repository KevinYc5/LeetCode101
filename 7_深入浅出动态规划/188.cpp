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
	int maxProfit(int k, vector<int>& prices) {
		int days = prices.size();
		if(days < 2){
			return 0;
		}
		if(k >= days){
			return maxProfitUnlimited(prices);
		}
		vector<int> buy(k+1, INT_MIN), sell(k+1, 0);
		for(int i = 0; i < days; ++i){
			for(int j = 1; j <= k; ++j){
				buy[j] = max(buy[j], sell[j-1] - prices[i]);
				sell[j] = max(sell[j], sell[j-1] + prices[i]);
			}
		}
		return sell[k];
	}

	int maxProfitUnlimited(vector<int>& prices){
		int maxProfit = 0;
		for(int i = 1; i < prices.size(); ++i){
			if(prices[i] > prices[i-1]){
				maxProfit += prices[i] - prices[i-1];
			}
		}
		return maxProfit;
	}
};
//
// Created by Kevin on 2020/8/6 22:03.
// 求真求实，大气大为
//

