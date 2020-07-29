#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		if(root == nullptr)
			return ans;
		unordered_map<TreeNode*, TreeNode*> next;
		dfs(root, root, root->left, next, ans);
		dfs(root, root, root->right, next, ans);
		return ans;
	}
	void dfs(TreeNode* root, TreeNode* father, TreeNode* son, unordered_map<TreeNode*, TreeNode*>& next, vector<string>& ans){
		next[father] = son;
		// 到达叶结点
		if(father->left == nullptr && father->right == nullptr){
			TreeNode* rt = root;
			string temp = to_string(rt->val);
			rt = next[rt];
			while(rt != nullptr){
				temp.append("->"+ to_string(root->val) );
				rt = next[rt];
			}
			ans.push_back(temp);
			return;
		}
		if(son == nullptr)
			return;
		dfs(root, son, son->right, next, ans);
		dfs(root, son, son->left, next, ans);
	}
};

class Solution0 {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector <string> res;
		if(root==nullptr) return res;//递归出口，当root为空时，返回空
		if(root->left==nullptr && root->right==nullptr) {//当root为叶子节点时，将叶子结点的val放入res，再返回
			res.push_back(to_string(root->val));
			return res;
		}
		vector <string> lefts=binaryTreePaths(root->left);//递归过程
		for(auto & left : lefts) {//求左子树的路径
			res.push_back(to_string(root->val)+"->"+left);//将根节点的值放入res，按题目要求储存
		}
		vector <string> rights=binaryTreePaths(root->right);//求右子树的路径
		for(auto & right : rights) {
			res.push_back(to_string(root->val)+"->"+right);
		}
		return res;
	}
};

//
// Created by Kevin on 2020/7/28 12:22.
// 求真求实，大气大为
//

