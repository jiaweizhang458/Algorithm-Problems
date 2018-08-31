//976. 4Sum II
//Given four lists A, B, C, D of integer values, compute how many tuples(i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
//
//To make problem a bit easier, all A, B, C, D have same length of N where 0 ¡Ü N ¡Ü 500. All integers are in the range of - 2 ^ 28 to 2 ^ 28 - 1 and the result is guaranteed to be at most 2 ^ 31 - 1.
//
//Example
//Input :
//A = [1, 2]
//B = [-2, -1]
//C = [-1, 2]
//D = [0, 2]
//
//Output :
//	2
//
//	Explanation :
//	The two tuples are :
//1. (0, 0, 0, 1)->A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0)->A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

//Solution 1: n^4, 89% pass then TLE
class Solution {
public:
	/**
	* @param A: a list
	* @param B: a list
	* @param C: a list
	* @param D: a list
	* @return: how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero
	*/

	static bool comp(const int a, const int b) {
		return a < b;
	}

	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
		// Write your code here
		int resultNum = 0;
		sort(A.begin(), A.end(), comp);
		sort(B.begin(), B.end(), comp);
		sort(C.begin(), C.end(), comp);
		sort(D.begin(), D.end(), comp);
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				for (int k = 0; k < C.size(); k++) {
					for (int l = 0; l < D.size(); l++) {
						if (A[i] + B[j] + C[k] + D[l] == 0) resultNum++;
					}
				}
			}
		}
		return resultNum;
	}
};

//Solution 2: Hash Map
//Reference: https://www.cnblogs.com/grandyang/p/6073317.html
class Solution {
public:
	/**
	* @param A: a list
	* @param B: a list
	* @param C: a list
	* @param D: a list
	* @return: how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero
	*/

	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
		// Write your code here
		unordered_map<int, int> AB;
		int resultNum = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				AB[A[i] + B[j]] ++;
			}
		}

		for (int ii = 0; ii < C.size(); ii++) {
			for (int jj = 0; jj < B.size(); jj++) {
				resultNum += AB[-C[ii] - D[jj]];
			}
		}
		return resultNum;
	}
};