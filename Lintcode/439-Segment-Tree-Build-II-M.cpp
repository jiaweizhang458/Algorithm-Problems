//439. Segment Tree Build II
//The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.
//
//start and end are both integers, they should be assigned in following rules :
//
//The root's start and end is given by build method.
//The left child of node A has start = A.left, end = (A.left + A.right) / 2.
//The right child of node A has start = (A.left + A.right) / 2 + 1, end = A.right.
//if start equals to end, there will be no children for this node.
//Implement a build method with a given array, 
//so that we can create a corresponding segment tree with every node value represent the corresponding interval max value in the array, 
//return the root of this segment tree.
//
//Example
//Given[3, 2, 1, 4].The segment tree will be :
//
//[0, 3](max = 4)
/// \
//[0, 1](max = 3)[2, 3](max = 4)
/// \ / \
//[0, 0](max = 3)[1, 1](max = 2)[2, 2](max = 1)[3, 3](max = 4)
//Clarification
//Segment Tree(a.k.a Interval Tree) is an advanced data structure which can support queries like :
//
//which of these intervals contain a given point
//which of these points are in a given interval

/**
* Definition of SegmentTreeNode:
* class SegmentTreeNode {
* public:
*     int start, end, max;
*     SegmentTreeNode *left, *right;
*     SegmentTreeNode(int start, int end, int max) {
*         this->start = start;
*         this->end = end;
*         this->max = max;
*         this->left = this->right = NULL;
*     }
* }
*/

class Solution {
public:
	/**
	* @param A: a list of integer
	* @return: The root of Segment Tree
	*/
	SegmentTreeNode * build(vector<int> &A) {
		if (A.size() == 0) return NULL;
		int start = 0;
		int end = A.size() - 1;
		Adup.assign(A.begin(), A.end());
		SegmentTreeNode* root = new SegmentTreeNode(start, end, -1);
		buildTree(root);
		return root;
	}

	int buildTree(SegmentTreeNode* root) {
		if (root->start == root->end) {
			root->max = Adup[root->start];
			return root->max;
		}
		int mid = (root->start + root->end) / 2;
		SegmentTreeNode* leftNode = new SegmentTreeNode(root->start, mid, -1);
		SegmentTreeNode* rightNode = new SegmentTreeNode(mid + 1, root->end, -1);
		root->left = leftNode;
		root->right = rightNode;
		root->max = max(buildTree(leftNode), buildTree(rightNode));
		return root->max;
	}
private:
	vector<int> Adup;

};