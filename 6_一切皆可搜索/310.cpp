#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// 时间超过限制
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> hight(n, 0);
		vector<vector<bool>> edge(n, vector<bool>(n, false));
		int minHight = n;
		vector<int> ans;
		for(auto p : edges){
			edge[p[0]][p[1]] = edge[p[1]][p[0]] = true;
		}
		for(int i = 0; i < n; ++i){
			hight[i] = dfs(edge, i);
		}

		for(int i = 0; i < n; ++i){
			if(hight[i] < minHight){
				minHight = hight[i];
			}
		}
		for(int i = 0; i < n; ++i){
			if(hight[i] == minHight){
				ans.push_back(i);
			}
		}
		return ans;
	}
	int dfs(vector<vector<bool>>& edge, int p){
		//if(edge[p].empty()) return;
		int n = edge.size();
		int maxhight = 0;
		for(int i = 0; i < n; ++i){
			if(edge[p][i] == true){
				edge[p][i] = edge[i][p] = false;
				maxhight =  max(maxhight, dfs(edge, i) + 1);
				edge[p][i] = edge[i][p] = true;
			}
		}
		return maxhight;
	}
};

class Solution0 {
public:
	void dfs1(const vector<vector<int> >& g, int i, int k, vector<int>& dfn) {
		dfn[i] = k;
		for (auto j : g[i]) {
			if (!dfn[j]) {
				dfs1(g, j, k + 1, dfn);
			}
		}
	}
	void dfs2(const vector<vector<int> >& g, const vector<int>& dfn, int i, int d1, int d2, vector<int>& res) {
		if (dfn[i] == d1 || dfn[i] == d2) {
			res.push_back(i);
		} else if (dfn[i] < d1 && dfn[i] < d2) {
			return;
		}
		for (auto j : g[i]) {
			if (dfn[j] < dfn[i]) {
				dfs2(g, dfn, j, d1, d2, res);
			}
		}
	}
	int getMaxInd(const vector<int>& nums) {
		return max_element(nums.begin(), nums.end()) - nums.begin();
	}
	int getMaxNum(const vector<int>& nums) {
		return nums[getMaxInd(nums)];
	}
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int> > g(n);
		for (auto& e : edges) {
			g[e[0]].push_back(e[1]);
			g[e[1]].push_back(e[0]);
		}
		vector<int> dfn(n, 0);
		dfs1(g, 0, 1, dfn);
		int k = getMaxInd(dfn);
		fill(dfn.begin(), dfn.end(), 0);
		dfs1(g, k, 1, dfn);

		int d = getMaxNum(dfn);
		int d1 = (1 + d) / 2;
		int d2 = 1 + d / 2;
		k = getMaxInd(dfn);
		vector<int> res;
		dfs2(g, dfn, k, d1, d2, res);
		return res;
	}
};

// 这道题的思路应该是找图的直径，即图里最远的两个点，
// 以直径的中间的一个或两个点作为根，图的高度是直径的一半，即为最小树高。
class Solution1 {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) return {0};
		vector<int> res;
		vector<unordered_set<int>> adj(n);
		queue<int> q;
		for (auto edge : edges) {
			adj[edge[0]].insert(edge[1]);
			adj[edge[1]].insert(edge[0]);
		}
		for (int i = 0; i < n; ++i) {
			if (adj[i].size() == 1) q.push(i);
		}
		while (n > 2) {
			int size = q.size();
			n -= size;
			for (int i = 0; i < size; ++i) {
				int t = q.front(); q.pop();
				for (auto a : adj[t]) {
					adj[a].erase(t);
					if (adj[a].size() == 1) q.push(a);
				}
			}
		}
		while (!q.empty()) {
			res.push_back(q.front()); q.pop();
		}
		return res;
	}
};
//作者：da-li-wang
//		链接：https://leetcode-cn.com/problems/minimum-height-trees/solution/c-shen-du-you-xian-sou-suo-ti-jie-by-da-li-wang/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//
// Created by Kevin on 2020/7/31 21:45.
// 求真求实，大气大为
//

