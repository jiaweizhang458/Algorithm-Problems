//975. 2 Keys Keyboard
//Initially on a notepad only one character 'A' is present.You can perform two operations on this notepad for each step:
//
//Copy All : You can copy all the characters present on the notepad(partial copy is not allowed).
//Paste : You can paste the characters which are copied last time.
//	Given a number n.You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.Output the minimum number of steps to get n 'A'.
//	Example
//	Input : 3
//	Output : 3
//	Explanation :
//	Intitally, we have one character 'A'.
//	In step 1, we use Copy All operation.
//	In step 2, we use Paste operation to get 'AA'.
//	In step 3, we use Paste operation to get 'AAA'.
//	Notice
//	The n will be in the range[1, 1000].

//Solution 1: Recursion
//Reference: https://www.cnblogs.com/grandyang/p/7439616.html
class Solution {
public:
	/**
	* @param n: The number of 'A'
	* @return: the minimum number of steps to get n 'A'
	*/
	int minSteps(int n) {
		if (n == 1) return 0;
		int result = n;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				result = min(result, minSteps(n / i) + 1 + i - 1);
				// 1 for copy, i - 1 for paste, n/i = length, i = num
			}
		}
		return result;
	}
};

//Solution 2: DP, the same as recursion
class Solution {
public:
	/**
	* @param n: The number of 'A'
	* @return: the minimum number of steps to get n 'A'
	*/
	int minSteps(int n) {
		if (n == 1) return 0;
		int result = n;
		vector<int> vecDP(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			vecDP[i] = i;
			for (int j = 2; j < i; j++) {
				if (i % j == 0) {
					vecDP[i] = min(vecDP[i], vecDP[i / j] + 1 + j - 1);
				}
			}
		}
		return vecDP[n];
	}
};

//Solution 3:
//Reference: https://leetcode.com/problems/2-keys-keyboard/discuss/105897/loop-best-case-logn-no-dp-no-extra-space-no-recursion-with-explanation
//We look for a divisor d so that we can make d copies of(n / d) to get n
//The process of making d copies takes d steps(1 step of Copy All and d - 1 steps of Paste)
//We keep reducing the problem to a smaller one in a loop.
//The best cases occur when n is decreasing fast, and method is almost O(log(n))
//For example, when n = 1024 then n will be divided by 2 for only 10 iterations, which is much faster than O(n) DP method.
//The worst cases occur when n is some multiple of large prime, e.g.n = 997 but such cases are rare.

int minSteps(int n) {
	int s = 0;
	for (int d = 2; d <= n; d++) {
		while (n % d == 0) {
			s += d;
			n /= d;
		}
	}
	return s;
}