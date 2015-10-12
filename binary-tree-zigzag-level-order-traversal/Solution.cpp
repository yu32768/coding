#include <vector>
using namespace std;

//url: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		visit(root, result, 0);
		for (int i = 0; i < result.size(); i++) {
			if (i % 2 == 1) {
				reverse(result[i].begin(), result[i].end());
			}
		}
		return result;
	}

	void visit(TreeNode *node, vector<vector<int>> result, int level) {
		if (node == NULL) {
			return;
		}
		else {
			if (result.size() == level) {
				result.push_back(vector<int>(0));
			}
			result[level].push_back(node->val);
		}

		visit(node->left, result, level + 1);
		visit(node->right, result, level + 1);
	}
};