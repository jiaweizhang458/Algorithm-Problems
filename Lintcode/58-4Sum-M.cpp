//58. 4Sum
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ?
//
//Find all unique quadruplets in the array which gives the sum of target.
//
//Example
//Given array S = { 1 0 - 1 0 - 2 2 }, and target = 0. A solution set is :
//
//(-1, 0, 0, 1)
//(-2, -1, 1, 2)
//(-2, 0, 0, 2)
//Notice
//Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
//The solution set must not contain duplicate quadruplets.

class Solution {
public:
	/**
	* @param numbers: Give an array
	* @param target: An integer
	* @return: Find all unique quadruplets in the array which gives the sum of zero
	*/

	static bool compare(const int a, const int b) {
		return a < b;
	}

	vector<vector<int>> fourSum(vector<int> &numbers, int target) {
		sort(numbers.begin(), numbers.end(), compare);
		vector<vector<int>> result;
		int vecSize = numbers.size();
		for (int i = 0; i < vecSize - 3; i++) {
			int numF = numbers[i];
			if (i > 0 && numbers[i - 1] == numF) continue;
			for (int j = i + 1; j < vecSize - 2; j++) {
				int numS = numbers[j];
				if (j > i + 1 && numbers[j - 1] == numS) continue;
				for (int k = j + 1; k < vecSize - 1; k++) {
					int numT = numbers[k];
					if (k > j + 1 && numbers[k - 1] == numT) continue;
					for (int l = k + 1; l < vecSize; l++) {
						int numFth = numbers[l];
						if (l > k + 1 && numbers[l - 1] == numFth) continue;
						if (numF + numS + numT + numFth == target) {
							vector<int> temp = { numF, numS, numT, numFth };
							result.push_back(temp);
						}
					}
				}
			}
		}
		return result;
	}
};