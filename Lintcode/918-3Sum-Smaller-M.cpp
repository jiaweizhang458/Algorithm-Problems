//918. 3Sum Smaller
//Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
//	Example
//	Given nums = [-2, 0, 1, 3], target = 2, return 2.
//
//	Explanation:
//Because there are two triplets which sums are less than 2 :
//	[-2, 0, 1]
//[-2, 0, 3]
//Challenge
//Could you solve it in O(n2) runtime ?

class Solution {
public:
	/**
	* @param nums:  an array of n integers
	* @param target: a target
	* @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
	*/

	static bool compAsc(const int a, const int b) {
		return a < b;
	};

	int threeSumSmaller(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end(), compAsc);
		int numsSize = nums.size();
		int result = 0;
		if (numsSize < 3) return result;
		for (int i = 0; i < numsSize - 2; i++) {
			int numF = nums[i];
			for (int j = i + 1; j < numsSize - 1; j++) {
				int numS = nums[j];
				for (int k = j + 1; k < numsSize; k++) {
					int numT = nums[k];
					if (numF + numS + numT < target) {
						result++;
					}
					else break;
				}
			}
		}
		return result;
	}
};