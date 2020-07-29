#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	// 主函数 
	int findCircleNum(vector<vector<int>>& friends) {
		int n = friends.size(), count = 0;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(friends, i, visited); ++count;
			}
		}
		return count;
	}
	// 辅函数
	void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited) {
		visited[i] = true;
		for (int k = 0; k < friends.size(); ++k) {
			if (friends[i][k] == 1 && !visited[k]) {
				dfs(friends, k, visited);
			}
		} 
	}
};
//
// Created by Kevin on 2020/7/25 10:04.
// 求真求实，大气大为
//

