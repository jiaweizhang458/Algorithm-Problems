//902. Kth Smallest Element in a BST
//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Example
//Given root = { 1,#,2 }, k = 2, return 2.
//
//Challenge
//What if the BST is modified(insert / delete operations) often and you need to find the kth smallest frequently ? 
//How would you optimize the kthSmallest routine ?
//
//Notice
//You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

//Solution 1: Recursion:
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
	* @param root: the given BST
	* @param k: the given k
	* @return: the kth smallest element in BST
	*/

	void inOrder(TreeNode * root, int &k) {
		if (root == NULL) return;
		inOrder(root->left, k);
		k--;
		if (k == 0) {
			result = root->val;
			return;
		}
		inOrder(root->right, k);
	}

	int kthSmallest(TreeNode * root, int k) {
		inOrder(root, k);
		return result;
	}
private:
	int result;
};

//Solution 2: Without recursion, using stack
//Reference: https://www.cnblogs.com/grandyang/p/4620012.html
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
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        
        stack<TreeNode*> inOrder;
        TreeNode * curNode = root;
        while (curNode || !inOrder.empty()) {
            while (curNode) {
                inOrder.push(curNode);
                curNode = curNode->left;
            }
            curNode = inOrder.top();
            inOrder.pop();
            if (--k == 0) return curNode->val;
            curNode = curNode->right;
        }
    }
};
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
	* @param root: the given BST
	* @param k: the given k
	* @return: the kth smallest element in BST
	*/
	int kthSmallest(TreeNode * root, int k) {
		// write your code here

		stack<TreeNode*> inOrder;
		TreeNode * curNode = root;
		while (curNode || !inOrder.empty()) {
			while (curNode) {
				inOrder.push(curNode);
				curNode = curNode->left;
			}
			curNode = inOrder.top();
			inOrder.pop();
			if (--k == 0) return curNode->val;
			curNode = curNode->right;
		}
	}
};

//Follow up:
//Rebuild the tree, every node contains the node number of its left children and right children.