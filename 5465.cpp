#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		vector<vector<int>> v(n);
		for (auto &e : edges)
		{
			int x = e[0], y = e[1];
			v[x].push_back(y);
			v[y].push_back(x);
		}
		vector<vector<int>> s(n, vector<int>(26));

		vector<int> res(n);
		function<void(int,int)> dfs = [&](int x, int pre)
		{
			s[x][labels[x]-'a'] ++;
			for (auto y : v[x])
			{
				if (y == pre) continue;
				dfs(y, x);
				for (int i = 0; i < 26; ++i) s[x][i] += s[y][i];
			}
			res[x] = s[x][labels[x]-'a'];
		};

		dfs(0, -1);
		return res;
	}
};




class Solution1 {
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		vector<int> anss(n,0);
		vector<int> faa;
		faa = getfaa(n, edges);
		for(int i = 0; i < n; i++){
			anss[i] = getnum(faa, i, edges, labels);
		}
		return anss;
	}
	vector<int> getfaa(int n, vector<vector<int>>& edges){
		queue<int> q;
		vector<int> faa(n, -1);
		q.push(0);
		while(!q.empty()){
			int fa = q.front();
			q.pop();
			int size = edges.size();
			for(int i = 0; i < size; i++){
				if((edges[i][0] == fa ||edges[i][1] == fa ) && faa[i] == -1){
					faa[i] = fa;
					if(edges[i][0] == fa)
						q.push(edges[i][1]);
					else
						q.push(edges[i][0]);
				}
			}
		}
		return faa;
	}
	int getnum(vector<int> faa, int pos, vector<vector<int>>& edges, string labels){
		int ans = 0;
		bool flag = false;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int fa = q.front();
			q.pop();
			if(fa == pos){
				flag = true;
			}
			if(flag && labels[fa] == labels[pos]){
				++ans;
			}
			int size = edges.size();
			for(int i = 0; i < size; i++){
				if(edges[i][0] == fa && edges[i][1] != faa[fa]){
					q.push(edges[i][1]);
				} else if(edges[i][1] == fa && edges[i][0] != faa[fa]){
					q.push(edges[i][0]);
				}
			}
		}
		return ans;
	}
};
//
// Created by Kevin on 2020/7/19 11:02.
// 求真求实，大气大为
//

