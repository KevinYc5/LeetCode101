#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;


class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int n = people.size();
		// 根据身高从高到低排序
		// 身高相同时"前面人少"的优先
		// 可避免后面插入时矛盾
		sort(people.begin(), people.end(), [](vector<int>a, vector<int>b){
			return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
		});
		vector<vector<int>> ans;
		// 插入
		for(int i = 0; i < n; i++){
			ans.insert(ans.begin() + people[i][1], people[i]);
			// 连续身高相同插入且后者插入前者之前时，需要将前者前移一位
			// 注意 i 必须大于0
//			if( i > 0 &&people[i][0] == people[i-1][0] && people[i][1] < people[i-1][1]){
//				swap(ans[people[i-1][1]], ans[people[i-1][1]+1]);
//			}
		}
		return ans;
	}
};

//
// Created by Kevin on 2020/7/16.
//

