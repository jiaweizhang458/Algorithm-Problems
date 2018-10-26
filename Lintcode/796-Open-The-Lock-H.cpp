//796. Open the Lock
//You have a lock in front of you with 4 circular wheels.Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.The wheels can rotate freely and wrap around : for example we can turn '9' to be '0', or '0' to be '9'.Each move consists of turning one wheel one slot.
//
//The lock initially starts at '0000', a string representing the state of the 4 wheels.
//
//You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
//
//Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
//
//Example
//Example 1:
//
//Given deadends = ["0201", "0101", "0102", "1212", "2002"], target = "0202"
//Return 6
//Explanation :
//	A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
//	Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
//	because the wheels of the lock become stuck after the display becomes the dead end "0102".
//	Example 2 :
//
//	Given deadends = ["8888"], target = "0009"
//	Return 1
//	Explanation :
//	We can turn the last wheel in reverse to move from "0000" -> "0009".
//	Notice
//	1.The length of deadends will be in the range[1, 500].
//	2.target will not be in the list deadends.
//	3.Every string in deadends and the string target will be a string of 4 digits from the 10, 000 possibilities '0000' to '9999'.

//CORNER CASE!
class Solution {
public:
	/**
	* @param deadends: the list of deadends
	* @param target: the value of the wheels that will unlock the lock
	* @return: the minimum total number of turns
	*/
	int openLock(vector<string> &deadends, string &target) {
		if (find(deadends.begin(), deadends.end(), target) != deadends.end()) return -1;
		if (find(deadends.begin(), deadends.end(), "0000") != deadends.end()) return -1;//IMPORTANT
		if (target == "0000") return 0;

		unordered_set<string> visited;
		queue<string> bfs;
		bfs.push("0000");
		visited.insert("0000");
		int step = 0;
		while (!bfs.empty()) {
			step++;
			for (int i = bfs.size(); i > 0; i--) {
				string qStr = bfs.front(); bfs.pop();
				for (int j = 0; j < 4; j++) {
					int curDigit = qStr[j] - '0';
					for (int k = -1; k <= 1; k += 2) {
						string cur = qStr;
						cur[j] = (curDigit + k + 10) % 10 + '0';
						if (cur == target) {
							return step;
						}
						if (visited.count(cur)) continue;
						visited.insert(cur);
						if (find(deadends.begin(), deadends.end(), cur) != deadends.end()) continue;
						bfs.push(cur);
					}
				}
			}

		}
		return -1;
	}


};