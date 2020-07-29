#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
class Solution {
public:
	// 主函数
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int max_area = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				max_area = max(max_area, dfs(grid, i, j));
			}
		}
		return max_area;
	}
	// 辅函数
	int dfs(vector<vector<int>>& grid, int r, int c) {
		if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
			return 0;
		}
		grid[r][c] = 0;
		return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c)
		       + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
	}
};
//
// Created by Kevin on 2020/7/25 9:44.
// 求真求实，大气大为
//

