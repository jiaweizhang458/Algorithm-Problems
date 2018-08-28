//59. 3Sum Closest
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.
//
//Example
//For example, given array S = [-1 2 1 - 4], and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//Challenge
//O(n ^ 2) time, O(1) extra space
//
//Notice
//You may assume that each input would have exactly one solution.

class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @param target: An integer
	* @return: return the sum of the three integers, the sum closest target.
	*/
	int threeSumClosest(vector<int> &numbers, int target) {
		int minDiff = INT_MAX;
		int result;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size() - 2; i++) {
			int numF = numbers[i];
			if (i > 0 && numF == numbers[i - 1]) continue;
			for (int j = i + 1; j < numbers.size() - 1; j++) {
				int numS = numbers[j];
				if (j > i + 1 && numS == numbers[j - 1]) continue;
				for (int k = j + 1; k < numbers.size(); k++) {
					int numT = numbers[k];
					if (k > j + 1 && numT == numbers[k - 1]) continue;
					int sum = numF + numS + numT;
					int diff = abs(sum - target);
					if (diff < minDiff) {
						minDiff = diff;
						result = sum;
					}
				}
			}
		}
		return result;
	}
};