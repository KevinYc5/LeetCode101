#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int, int> counts;
			int max_count = 0;
			for(const int &num : nums){
				max_count = max(max_count, ++counts[num]);
			}
			vector<vector<int>> buckets(max_count + 1);
			for(const auto &p : counts){
				buckets[p.second].push_back(p.first);
			}
			vector<int> ans;
			for(int i = max_count; i > 0 && ans.size() < k; i--){
				for(const int &num :buckets[i]){
					ans.push_back(num);
					if(ans.size() == k){
						break;
					}
				}
			}
			return ans;
	}
};
//
// Created by Kevin on 2020/7/22 23:10.
// 求真求实，大气大为
//

