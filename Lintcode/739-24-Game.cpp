//You have 4 cards each containing a number from 1 to 9. You need to compute whether they could operated through *, / , +, -, (, ) to get the value of 24.
//
//Example
//Given nums = [4, 1, 8, 7], return true // 8 * £¨7 - 4£© * 1 = 24
//
//Given nums = [1, 1, 1, 2], return false
//
//Given nums = [3, 3, 8, 8], return true // 8 / ( 3 - 8 / 3) = 24
//
//Notice
//The division operator / represents real division, not integer division.so 4 / (1 - 2 / 3) = 12.
//Every operation done is between two numbers.In particular, we cannot use - as a unary operator. For example, with[1, 1, 1, 1] as input, the expression - 1 - 1 - 1 - 1 is not allowed.
//You cannot concatenate numbers together.For example, if the input is[1, 2, 1, 2], we cannot write this as 12 + 12.


//Solution 1: 
//Reference: https://www.cnblogs.com/grandyang/p/8395062.html
class Solution {
public:
	/**
	* @param nums: 4 cards
	* @return: whether they could get the value of 24
	*/
	bool compute24(vector<double> &nums) {
		return recurstion(nums);
	}

	bool recurstion(vector<double> &nums) {
		if (nums.size() == 1 && abs(nums[0] - 24) < 0.001) return true;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				double numF = nums[i];
				double numS = nums[j];
				nums.erase(nums.begin() + j);
				nums.erase(nums.begin() + i - 1);
				vector<double> op = { numF + numS, numF - numS, numS - numF, numF * numS };
				if (numS != 0) op.push_back(numF / numS);
				if (numF != 0) op.push_back(numS / numF);
				for (int k = 0; k < op.size(); k++) {
					nums.push_back(op[k]);
					bool result = recurstion(nums);
					if (result == true) return true;
					nums.pop_back();
				}
				nums.insert(nums.begin() + i - 1, numF);
				nums.insert(nums.begin() + j, numS);
			}
		}
		return false;
	}
};