#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> chars(128,0);
		vector<bool> flag(128,false);
		for(int i = 0; i < t.size(); i++){
			flag[t[i]] = true;
			++chars[t[i]];
		}
		int l = 0, cnt = 0, min_l = l, min_size = s.size()+1;
		for(int r = 0; r < s.size(); r++){
			if(--chars[s[r]] >= 0){ // s 中存在剩余子串字符
				cnt++;
			}
			while(cnt == t.size()){ // 此时 r 已滑在使条件成立（包含字串）的位置
				if(r - l + 1 < min_size){   // 记录
					min_size = r - l + 1;
					min_l = l;
				}
				if(flag[s[l]] && ++chars[s[l]] > 0) // l 滑动时可能破环成立条件
					--cnt;
				l++;
			}
		}
		return min_size > s.size() ? "" : s.substr(min_l, min_size);
	}
};
//
// Created by Kevin on 2020/7/17 21:04.
// 求真求实，大气大为
//

