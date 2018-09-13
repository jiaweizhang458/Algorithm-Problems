//85. Insert Node in a Binary Search Tree
//Given a binary search tree and a new tree node, insert the node into the tree.You should keep the tree still be a valid binary search tree.
//
//Example
//Given binary search tree as follow, after Insert node 6, the tree should be :
//
//2             2
/// \ / \
//1   4   -->   1   4
///             / \
//3             3   6
//Challenge
//Can you do it without recursion ?
//
//Notice
//You can assume there is no duplicate values in this tree + node.

//Solution 1: Recursion
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
	/*
	* @param root: The root of the binary search tree.
	* @param node: insert this node into the binary search tree
	* @return: The root of the new binary search tree.
	*/
	TreeNode * insertNode(TreeNode * root, TreeNode * node) {
		if (root == NULL) return node;
		int rootValue = root->val;
		int nodeValue = node->val;
		if (nodeValue > rootValue) {
			if (root->right == NULL) root->right = node;
			else { insertNode(root->right, node); }
		}
		else if (nodeValue < rootValue) {
			if (root->left == NULL) root->left = node;
			else { insertNode(root->left, node); }
		}
		return root;
	}
};

//Solution 2: without recursion
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
	/*
	* @param root: The root of the binary search tree.
	* @param node: insert this node into the binary search tree
	* @return: The root of the new binary search tree.
	*/
	TreeNode * insertNode(TreeNode * root, TreeNode * node) {
		if (root == NULL) {
			return node;
		}
		int nodeValue = node->val;
		TreeNode * temp = root;
		while (1) {
			if (nodeValue < temp->val) {
				if (temp->left) {
					temp = temp->left;
					continue;
				}
				else {
					temp->left = node;
					break;
				}
			}
			else {
				if (temp->right) {
					temp = temp->right;
					continue;
				}
				else {
					temp->right = node;
					break;
				}
			}
		}
		return root;
	}
};	