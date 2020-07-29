#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int child = 0, cookie = 0;
		while(cookie < s.size() && child < g.size()){
			if(g[child] <= s[cookie]) ++child;
			cookie++;
		}
		return child;
	}
};

//
// Created by Kevin on 2020/7/14.
//

