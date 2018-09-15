//1577. Sum of leaf nodes
//Given a binary tree, find the sum of all leaf nodes.Use O(1) space.
//
//Example
//Given binary tree :
//
//1
/// \
//2   3
/// \
//4   5
//Return : 12
//
//	Notice
//	1.²Î¿¼Morris Ëã·¨

/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/

class Solution {
public:
	/**
	* @param root:
	* @return: the sum of leafnode
	*/
	int sumLeafNode(TreeNode * root) {
		// Write your code here
		int sum = 0;
		if (root == NULL) return sum;
		TreeNode *node1 = root;
		TreeNode *node2 = NULL;
		while (node1 != NULL) {
			node2 = node1->left;
			if (node2 != NULL) {
				while (node2->right != NULL && node2->right != node1) node2 = node2->right;
				if (node2->right == NULL) {
					node2->right = node1;
					node1 = node1->left;
					continue;
				}
				else if (node2->right == node1) {
					node2->right = NULL;
				}
			}
			if (node1->left == NULL && node1->right == NULL) sum += node1->val;
			if (node2 && node2->left == NULL && node2->right == NULL) sum += node2->val;
			node1 = node1->right;
		}
		return sum;
	}
};