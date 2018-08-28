//57. 3Sum
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Example
//For example, given array S = { -1 0 1 2 - 1 - 4 }, A solution set is :
//
//(-1, 0, 1)
//(-1, -1, 2)
//Notice
//Elements in a triplet(a, b, c) must be in non - descending order. (ie, a ¡Ü b ¡Ü c)
//
//The solution set must not contain duplicate triplets.

//Solution 1: Intuitive, but time consuming.
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		vector<vector<int>> vecResult;
		sort(numbers.begin(), numbers.end());
		if (numbers.size() < 3) return vecResult;
		for (int i = 0; i < numbers.size() - 2; i++) {
			for (int j = i + 1; j < numbers.size() - 1; j++) {
				int numF = numbers[i];
				int numS = numbers[j];
				for (int k = j + 1; k < numbers.size(); k++) {
					int numT = numbers[k];
					if (numF + numS + numT == 0) {
						vector<int> vecTemp = { numT, numS, numF };
						sort(vecTemp.begin(), vecTemp.end());
						vector<vector<int>>::iterator it = find(vecResult.begin(), vecResult.end(), vecTemp);
						if (it != vecResult.end()) continue;
						std::cout << vecTemp[0] << " " << vecTemp[1] << " " << vecTemp[2] << std::endl;
						vecResult.push_back(vecTemp);
					}
				}
			}
		}
		return vecResult;
	}
};

//Solution 1 Improvement:
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		vector<vector<int>> vecResult;
		sort(numbers.begin(), numbers.end());
		if (numbers.size() < 3 || numbers[0] > 0) return vecResult;
		for (int i = 0; i < numbers.size() - 2; i++) {
			int numF = numbers[i];
			if (i > 0 && numF == numbers[i - 1]) continue;
			for (int j = i + 1; j < numbers.size() - 1; j++) {
				int numS = numbers[j];
				if (j > i + 1 && numS == numbers[j - 1]) continue;
				for (int k = j + 1; k < numbers.size(); k++) {
					int numT = numbers[k];
					if (k > j + 1 && numT == numbers[k - 1]) continue;
					if (numF + numS + numT == 0) {
						vector<int> vecTemp = { numF, numS, numT };
						vecResult.push_back(vecTemp);
					}
				}
			}
		}
		return vecResult;
	}
};