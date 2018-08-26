//1446. 01 Matrix Walking Problem
//Given an 01 matrix gird of size n*m, 1 is a wall, 0 is a road, now you can turn a 1 in the grid into 0, 
//Is there a way to go from the upper left corner to the lower right corner ? 
//If there is a way to go, how many steps to take at least ?
//
//Example
//Given a = [[0, 1, 0, 0, 0], [0, 0, 0, 1, 0], [1, 1, 0, 1, 0], [1, 1, 1, 1, 0]]，return 7.
//
//Explanation :
//	Change `1` at(0, 1) to `0`, the shortest path is as follows :
//(0, 0)->(0, 1)->(0, 2)->(0, 3)->(0, 4)->(1, 4)->(2, 4)->(3, 4) There are many other options of length `7`, not listed here.
//Given a = [[0, 1, 1], [1, 1, 0], [1, 1, 0]], return -1.
//
//Explanation:
//Regardless of which `1` is changed to `0`, there is no viable path.
//Notice
//1 <= n <= 1000
//1 <= m <= 1000
​​

//Solution 1: 73% accepted but TLE afterwards.
class Solution {
public:
	/**
	* @param grid: The gird
	* @return: Return the steps you need at least
	*/

	void BFS(const vector<vector<int>> grid, const std::pair<int, int> startPoint, const std::pair<int, int> endPoint,
		vector<vector<int>> &vecCur) {
		int distance = 0;
		int rows = grid.size();
		int cols = grid[0].size();

		vector<int> vecBoolTemp(cols, 0);
		vector<vector<int>> vecBool(rows, vecBoolTemp);

		queue<std::pair<int, int>> queueBFS;
		queueBFS.push(startPoint);
		while (!queueBFS.empty()) {
			int queueSize = queueBFS.size();
			for (int i = 0; i < queueSize; i++) {
				std::pair<int, int> curPoint = queueBFS.front();
				int curRow = curPoint.first;
				int curCol = curPoint.second;
				vecBool[curRow][curCol] = 1;
				queueBFS.pop();
				if (curPoint == endPoint || grid[curRow][curCol] == 1) {
					vecCur[curRow][curCol] = distance;
					continue;
				}

				if (curRow - 1 >= 0 && vecBool[curRow - 1][curCol] == 0)
					queueBFS.push(std::pair<int, int>(curRow - 1, curCol));
				if (curRow + 1 < rows && vecBool[curRow + 1][curCol] == 0)
					queueBFS.push(std::pair<int, int>(curRow + 1, curCol));
				if (curCol - 1 >= 0 && vecBool[curRow][curCol - 1] == 0)
					queueBFS.push(std::pair<int, int>(curRow, curCol - 1));
				if (curCol + 1 < cols && vecBool[curRow][curCol + 1] == 0)
					queueBFS.push(std::pair<int, int>(curRow, curCol + 1));
			}
			distance++;
		}
		return;
	};

	int getBestRoad(vector<vector<int>> &grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		std::pair<int, int> leftUp(0, 0);                    // (row, col)
		std::pair<int, int> rightDown(rows - 1, cols - 1);  //

		vector<int> vecDisTemp(cols, -1);
		vector<vector<int>> vecLeftUp(rows, vecDisTemp);    // distance to left up
		vector<vector<int>> vecRightDown(rows, vecDisTemp); // distance to right down


		BFS(grid, rightDown, leftUp, vecLeftUp);
		BFS(grid, leftUp, rightDown, vecRightDown);

		int result = 5000;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (vecLeftUp[i][j] == -1 || vecRightDown[i][j] == -1) continue;
				if (result > vecLeftUp[i][j] + vecRightDown[i][j]) result = vecLeftUp[i][j] + vecRightDown[i][j];
			}
		}
		if (result == 5000) return -1;
		return result;
	}

};
//Solution 1

//Solution 2: ugly but working
//Reference: https://www.jiuzhang.com/solution/01-matrix-walking-problem/#tag-highlight-lang-cpp
class Solution {
public:
	/**
	* @param grid: The gird
	* @return: Return the steps you need at least
	*/

	struct Point {
		int row;
		int col;
		int state;
	};

	void BFS(const vector<vector<int>> grid, vector<vector<int>> &vecZero, vector<vector<int>> &vecOne, const vector<std::pair<int, int>> vecNeighbor) {
		int rows = grid.size();
		int cols = grid[0].size();

		queue<Point> queueBFS; //
		vecZero[0][0] = 0;

		Point origin = { 0, 0, 0 };
		queueBFS.push(origin);
		while (!queueBFS.empty()) {
			Point curPoint = queueBFS.front();
			int curRow = curPoint.row;
			int curCol = curPoint.col;
			int curValue = curPoint.state;
			queueBFS.pop();

			for (int i = 0; i < vecNeighbor.size(); i++) {
				int nextRow = curRow + vecNeighbor[i].first;
				int nextCol = curCol + vecNeighbor[i].second;

				if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) continue;

				int nextValue = curValue + grid[nextRow][nextCol];
				if (nextValue > 1) continue;
				else if (nextValue == 1) {
					if (vecOne[nextRow][nextCol] != 5001) continue;
					if (curValue == 0) {
						vecOne[nextRow][nextCol] = vecZero[curRow][curCol] + 1;
						std::cout << vecOne[nextRow][nextCol] << std::endl;
					}
					else {
						vecOne[nextRow][nextCol] = vecOne[curRow][curCol] + 1;
						std::cout << vecOne[nextRow][nextCol] << std::endl;
					}
				}
				else { // nextValue = 0
					if (vecZero[nextRow][nextCol] != 5001) continue;
					vecZero[nextRow][nextCol] = vecZero[curRow][curCol] + 1;
					std::cout << vecZero[nextRow][nextCol] << std::endl;
				}
				Point nextPoint = { nextRow, nextCol, nextValue };
				queueBFS.push(nextPoint);
			}
		}
		return;
	};

	int getBestRoad(vector<vector<int>> &grid) {
		int rows = grid.size();
		int cols = grid[0].size();


		vector<int> vecDisTemp(cols, 5001);
		vector<vector<int>> vecZero(rows, vecDisTemp);    // distance to left up
		vector<vector<int>> vecOne(rows, vecDisTemp); // distance to right down
		vector<std::pair<int, int>> vecNeighbor(4);
		vecNeighbor[0] = std::pair<int, int>(-1, 0);
		vecNeighbor[1] = std::pair<int, int>(1, 0);
		vecNeighbor[2] = std::pair<int, int>(0, -1);
		vecNeighbor[3] = std::pair<int, int>(0, 1);

		BFS(grid, vecZero, vecOne, vecNeighbor);

		int result = 5001;
		if (result > vecZero[rows - 1][cols - 1]) result = vecZero[rows - 1][cols - 1];
		if (result > vecOne[rows - 1][cols - 1]) result = vecOne[rows - 1][cols - 1];
		if (result == 5001) return -1;
		return result;
	}

};