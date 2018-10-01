//1029. Cheapest Flights Within K Stops
//There are n cities connected by m flights.Each fight starts from city u and arrives at v with a price w.
//
//Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops.If there is no such route, output - 1.
//
//Example
//Input :
//n = 3, edges = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
//src = 0, dst = 2, k = 1
//Output : 200
//
//	Input :
//	n = 3, edges = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
//	src = 0, dst = 2, k = 0
//	Output : 500
//
//	Notice
//	The number of nodes n will be in range[1, 100], with nodes labeled from 0 to n - 1.
//	The size of flights will be in range[0, n * (n - 1) / 2].
//	The format of each flight will be(src, dst, price).
//	The price of each flight will be in the range[1, 10000].
//	k is in the range of[0, n - 1].
//	There will not be any duplicated flights or self cycles.


//Solution 1: BFS
//Reference: http://www.cnblogs.com/grandyang/p/9109981.html
class Solution {
public:
	/**
	* @param n: a integer
	* @param flights: a 2D array
	* @param src: a integer
	* @param dst: a integer
	* @param K: a integer
	* @return: return a integer
	*/
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
		unordered_map<int, vector<vector<int>>> mapFlights;
		for (auto flight : flights) {
			mapFlights[flight[0]].push_back({ flight[1], flight[2] });
		}

		int flyNum = 0;
		int res = INT_MAX;
		queue<pair<int, int>> bfsQueue;
		bfsQueue.push({ src, 0 });
		while (!bfsQueue.empty()) {
			for (int i = bfsQueue.size(); i > 0; i--) {// important. Queue size changes
				auto curFlight = bfsQueue.front(); bfsQueue.pop();
				if (curFlight.first == dst) res = min(res, curFlight.second);
				for (auto nextFlight : mapFlights[curFlight.first]) {
					if (curFlight.second + nextFlight[1] > res) continue;
					bfsQueue.push({ nextFlight[0], curFlight.second + nextFlight[1] });
				}
			}
			if (flyNum++ > K) break;
		}
		return res == INT_MAX ? -1 : res;
	}
};