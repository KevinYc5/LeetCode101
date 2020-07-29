#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		int count = 0;
		vector<vector<int>> ans;
		vector<int> comb(k,0);
		backtracking(ans, comb, count, 1, n, k);
		return ans;
	}
	void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k){
		if(count == k){
			ans.push_back(comb);
			return;
		}
		for(int i = pos; i <= n; ++i){
			comb[count++] = i;
			backtracking(ans, comb, count, i + 1, n, k);
			--count;
		}
	}
};
//
// Created by Kevin on 2020/7/25 18:26.
// 求真求实，大气大为
//

