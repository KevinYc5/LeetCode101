#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int res = 0, left = 0;
		unordered_map<char, int> m;
		for (int i = 0; i < s.size(); ++i) {
			++m[s[i]];
			while (m.size() > 2) {
				if (--m[s[left]] == 0) m.erase(s[left]);
				++left;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
};
//
// Created by Kevin on 2020/7/18 13:21.
// 求真求实，大气大为
//

