#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int>counts;
		int max_count = 0;
		for( const char &p : s){
			max_count = max(max_count, ++counts[p]);
		}
		vector<vector<char>> buckets(max_count + 1);
		for(const auto &p : counts){
			buckets[p.second].push_back(p.first);
		}
		string ans;
		for(int i = max_count; i >= 0; i--){
			for(const char & p : buckets[i]){
				for(int j = 0; j < i; j++){
					ans.push_back(p);
				}
			}
		}
		return ans;
	}
};
//
// Created by Kevin on 2020/7/22 23:27.
// 求真求实，大气大为
//

