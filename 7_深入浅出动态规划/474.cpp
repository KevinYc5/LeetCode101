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
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for(const string& str : strs){
			auto [count0, count1] = count(str);
			for(int i = m; i >= count0; --i){
				for(int j = n; j >= count1; --j){
					dp[i][j] = max(dp[i][j], dp[i-count0][j-count1]+1);
				}
			}
		}
		return dp[m][n];
	}
	pair<int, int> count(const string& s){
		int count0 = s.size(), count1 = 0;
		for(const char& c : s){
			if(c == '1'){
				--count0;
				++count1;
			}
		}
		return make_pair(count0, count1);
	}
};
//
// Created by Kevin on 2020/8/5 15:31.
// 求真求实，大气大为
//

