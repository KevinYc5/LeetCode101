#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector <int> income(n, 0);
		//今日买，次日卖的收益
		for(int i = 0; i < n-1; i++){
			income[i] = prices[i+1] - prices[i];
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(income[i] > 0){
				ans += income[i];
			}
		}
		return ans;
	}
};


class Solution_1 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>>income(n);
		// 构建上三角邻接矩阵
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++)
				income[i].push_back(prices[j] - prices[i]);
		}
		// 从倒数第二天逆序遍历，最高价卖出（局部最优）
		int ans = 0, sellDay = n, temp_sellday;
		for(int i = n-2; i > -1; i--){
			// 寻找最高价，注意不得迟于sellday（上次购入）
			int maxPrice = 0;
			for(int j = 0; j < sellDay - (i+1); j++){
				if(income[i][j] > maxPrice){
					maxPrice = income[i][j];
					temp_sellday = j;
				}
			}
			// 最高价大于 0 时， 购入（更新ans,sellday）
			if(maxPrice > 0){
				ans += maxPrice;
				sellDay = temp_sellday + i + 1;
			}
		}
		return ans;
	}
};

//
// Created by Kevin on 2020/7/15.
//

