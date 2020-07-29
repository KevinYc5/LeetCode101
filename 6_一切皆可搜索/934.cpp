#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
class Solution {
public:
	vector<int> direction{-1, 0, 1, 0, -1};

	int shortestBridge(vector<vector<int>>& A) {
		int m = A.size(), n = A[0].size();
		queue<pair<int, int>> points;
		bool flipped = false;
		for(int i = 0; i < m; ++i){
			if(flipped) break;
			for(int j = 0; j < n; ++j){
				if(A[i][j] == 1){
					dfs(points, A, m, n, i, j);
					flipped = true;
					break;
				}

			}
		}
		int level = 0;
		int x, y;
		while (!points.empty()){
			++level;
			int n_points = points.size();
			while(n_points--){
				auto [r, c] = points.front();
				points.pop();
				for(int k = 0; k < 4; ++k){
					x = r + direction[k]; y = c + direction[k+1];
					if(x >= 0 && y >= 0 && x < m && y < n){
						if(A[x][y] == 2)
							continue;
						if(A[x][y] == 1)
							return level;
						points.push({x, y});
						A[x][y] = 2;
					}
				}
			}
		}
		return 0;
	}
	void dfs(queue<pair<int, int>>& points, vector<vector<int>>& A, int m, int n, int i, int j){
		if(i < 0 || j < 0 || i >= m || j >= n || A[i][j] == 2)
			return;
		if(A[i][j] == 0){
			points.push({i, j});
			return;
		}
		A[i][j] = 2;
		dfs(points, A, m, n, i+1, j);
		dfs(points, A, m, n, i-1, j);
		dfs(points, A, m, n, i, j+1);
		dfs(points, A, m, n, i, j-1);
	}
};
//
// Created by Kevin on 2020/7/26 10:02.
// 求真求实，大气大为
//

