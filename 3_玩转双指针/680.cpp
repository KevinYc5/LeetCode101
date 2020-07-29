#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
	bool validPalindrome(string s) {
		int l = 0, r = s.size() - 1;
		while(l < r){
			if(s[l] == s[r]){
				++l, --r;
			}else{
				// 删左
				int i = l+1, j = r;
				for(; i < j && s[i] == s[j]; ++i, --j);
				bool flag1 = (i >= j);
				// 删右
				i = l; j = r - 1;
				for(; i < j && s[i] == s[j]; ++i, --j);
				bool flag2 = (i >= j);
				return flag1 && flag2;
			}
		}
		return l >= r;
	}
};
//
// Created by Kevin on 2020/7/17 22:24.
// 求真求实，大气大为
//

