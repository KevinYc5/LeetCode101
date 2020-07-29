#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		vector<string> ans;
		int n1 = s.size();
		int n2 = d.size();
		for(int i = 0; i < n2; i++){
			int r1 = n1-1, r2 = d[i].size()-1;  // 双尾指针
			while(r1 >= 0 && r2 >= 0){
				if(s[r1] == d[i][r2]){
					r1--; r2--;
				} else {
					r1--;
				}
			}
			if(r2 < 0){    // 符合条件
				ans.push_back(d[i]);
			}
		}
		if(ans.empty())     // 不存在答案
			return "";

		int maxsizePos = 0;     // 确定最长串
		int n3 = ans.size();
		for(int i = 1; i < n3; i++){
			if(ans[i].size() > ans[maxsizePos].size())
				maxsizePos = i;
		}
		vector<string> maxsizeAns;
		for(int i = 0; i < n3; i++){
			if(ans[i].size() == ans[maxsizePos].size())
				maxsizeAns.push_back(ans[i]);
		}
		sort(maxsizeAns.begin(), maxsizeAns.end());     //确定字典序最小的

		return maxsizeAns[0];
	}
};
//
// Created by Kevin on 2020/7/17 22:51.
// 求真求实，大气大为
//

