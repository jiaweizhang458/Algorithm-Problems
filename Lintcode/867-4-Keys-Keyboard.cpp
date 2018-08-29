//867. 4 Keys Keyboard
//Imagine you have a special keyboard with the following keys :
//
//Key 1 : (A) : Print one 'A' on screen.
//
//Key 2 : (Ctrl - A) : Select the whole screen.
//
//Key 3 : (Ctrl - C) : Copy selection to buffer.
//
//Key 4 : (Ctrl - V) : Print buffer on screen appending it after what has already been printed.
//
//Now, you can only press the keyboard for N times(with the above four keys), find out the maximum numbers of 'A' you can print on screen.
//
//Example
//Given N = 3, return 3.
//
//Explanation :
//	We can at most get 3 A's on screen by pressing following key sequence:
//	A, A, A
//	Given N = 7, return 9.
//
//	Explanation :
//	We can at most get 9 A's on screen by pressing following key sequence:
//	A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
//	Notice
//	1 <= N <= 50
//	Answers will be in the range of 32 - bit signed integer.

//Reference: https://blog.csdn.net/huanghanqian/article/details/76575003

//Solution 1: Sometimes TLE, sometimes pass
class Solution {
public:
	/**
	* @param N: an integer
	* @return: return an integer
	*/
	int maxA(int N) {
		int result = N;
		for (int i = 1; i <= N - 3; i++) { // N - 3: if use copy, at least need 3 steps.
			result = std::max(result, maxA(i)*(N - i - 1)); // N - i steps to copy can produce (N - i - 1) copies.
		}
		return result;
	}
};

//Solution 2: DP
class Solution {
public:
	/**
	* @param N: an integer
	* @return: return an integer
	*/
	int maxA(int N) {
		vector<int> vecDP(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			vecDP[i] = i;
			for (int j = 1; j <= i - 3; j++) {
				vecDP[i] = max(vecDP[i], vecDP[j] * (i - j - 1));
			}
		}
		return vecDP[N];
	}
};