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
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if(matrix.empty()) return {};
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX-1));
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(matrix[i][j] == 0)
					dp[i][j] = 0;
				else {
					if( i > 0){
						dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
					}
					if( j > 0){
						dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
					}
				}
			}
		}
		for(int i = m-1; i > -1; --i){
			for(int j = n-1; j > -1; --j){
				if(j < n - 1){
					dp[i][j] = min(dp[i][j+1] + 1, dp[i][j]);
				}
				if(i < m - 1){
					dp[i][j] = min(dp[i+1][j] + 1, dp[i][j]);
				}
			}
		}
		return dp;
	}
};
class Solution0 {
private:
	static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dist(m, vector<int>(n));
		vector<vector<int>> seen(m, vector<int>(n));
		queue<pair<int, int>> q;
		// 将所有的 0 添加进初始队列中
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					q.emplace(i, j);
					seen[i][j] = 1;
				}
			}
		}

		// 广度优先搜索
		while (!q.empty()) {
			auto [i, j] = q.front();
			q.pop();
			for (int d = 0; d < 4; ++d) {
				int ni = i + dirs[d][0];
				int nj = j + dirs[d][1];
				if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
					dist[ni][nj] = dist[i][j] + 1;
					q.emplace(ni, nj);
					seen[ni][nj] = 1;
				}
			}
		}

		return dist;
	}
};

//作者：LeetCode-Solution
//		链接：https://leetcode-cn.com/problems/01-matrix/solution/01ju-zhen-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//
// Created by Kevin on 2020/8/1 11:54.
// 求真求实，大气大为
//

