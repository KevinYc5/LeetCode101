#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> last(26, -1);
		int size = S.size();
		for(int i = 0; i < size; i++){
			last[S[i] - 'a'] = i;
		}
		vector<int> ans;
		int right = 0;
		for(int i = 0; i < size; i = right + 1){
			right = last[S[i] - 'a'];
			for(int j = i+1; j <= right; j++){  // 根据块内元素扩充块
				if(last[S[j] - 'a'] > right)
					right = last[S[j] - 'a'];
			}
			ans.insert(ans.end(), right);
			if(right == size - 1)               // 已经全部分类
				break;
		}
		for(int i = ans.size()-1; i > 0; i--){
			ans[i] = ans[i] - ans[i-1];
		}
		ans[0]++;
		return ans;
	}
};
//
// Created by Kevin on 2020/7/15.
//

