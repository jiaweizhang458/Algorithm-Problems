//636. 132 Pattern
//Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
//
//	n will be less than 20, 000.
//
//	Example
//	Given nums = [1, 2, 3, 4]
//	return False // There is no 132 pattern in the sequence.
//
//	Given nums = [3, 1, 4, 2]
//	return True // There is a 132 pattern in the sequence: [1, 4, 2].

//Solution 1: Naive (77% pass)
class Solution {
public:
	/**
	* @param nums: a list of n integers
	* @return: true if there is a 132 pattern or false
	*/
	bool find132pattern(vector<int> &nums) {
		if (nums.size() < 3) return false;
		int one = INT_MAX;
		for (int i = 0; i < nums.size() - 1; i++) {
			one = min(nums[i], one);
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] > one && nums[j] < nums[i]) return true;
			}
		}
		return false;
	}
};

//Solution 2: Stack!
class Solution {
public:
	/**
	* @param nums: a list of n integers
	* @return: true if there is a 132 pattern or false
	*/
	bool find132pattern(vector<int> &nums) {
		if (nums.size() < 3) return false;
		vector<int>minVec(nums.size(), INT_MAX);
		minVec[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) minVec[i] = min(nums[i], minVec[i - 1]);

		stack<int> s;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] == minVec[i]) continue;
			if (s.empty() || nums[i] < s.top()) s.push(nums[i]);
			else {
				while (!s.empty() && s.top() >= nums[i]) s.pop();
				if (!s.empty()) return true;
			}
		}
		return false;
	}
};