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
	int minSteps(int n) {
		vector<int> dp(n+1);
		int h = sqrt(n);
		for(int i = 2; i <= n; ++i){
			dp[i] = i;
			for(int j = 2; j <=h; ++j){
				if(i % j == 0){
					dp[i] = dp[j] +dp[i/j];
					break;
				}
			}
		}
		return dp[n];
	}
};
//
// Created by Kevin on 2020/8/6 15:05.
// 求真求实，大气大为
//

