//Given a list accounts, each element accounts[i] is a list of strings, 
//where the first element accounts[i][0] is a name, 
//and the rest of the elements are emails representing emails of the account.
//
//Now, we would like to merge these accounts.
//Two accounts definitely belong to the same person if there is some email that is common to both accounts.
//Note that even if two accounts have the same name, they may belong to different people as people could have the same name.
//A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//
//After merging the accounts, return the accounts in the following format : 
//the first element of each account is the name, 
//and the rest of the elements are emails in sorted order.The accounts themselves can be returned in any order.

//Solution 1: Union find
//Reference: https://blog.csdn.net/qq_32335095/article/details/78879421
class Solution {
public:
	/**
	* @param accounts: List[List[str]]
	* @return: return a List[List[str]]
	*/

	string findRoot(string son, unordered_map<string, string>& unionSet) {
		return (unionSet[son] == son) ? son : findRoot(unionSet[son], unionSet);
	}

	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
		vector<vector<string>> result;
		unordered_map<string, string> unionSet;
		unordered_map<string, string> user;
		unordered_map<string, set<string>> hashResult;
		for (auto account : accounts) {
			for (int j = 1; j < account.size(); j++) {
				unionSet[account[j]] = account[j];
				user[account[j]] = account[0];
			}
		}

		for (auto account : accounts) {
			string curRoot = findRoot(account[1], unionSet);
			for (int j = 2; j < account.size(); j++) {
				unionSet[findRoot(account[j], unionSet)] = curRoot;
			}
		}

		for (auto account : accounts) {
			for (int j = 1; j < account.size(); j++) {
				hashResult[findRoot(account[j], unionSet)].insert(account[j]);
			}
		}

		for (auto element : hashResult) {
			vector<string> temp(element.second.begin(), element.second.end());
			temp.insert(temp.begin(), user[element.first]);
			result.push_back(temp);
		}

		return result;
	}
};

//Solution 2: BFS
//Reference: https://blog.csdn.net/carbon06/article/details/80497615\
class Solution {
public:
	/**
	* @param accounts: List[List[str]]
	* @return: return a List[List[str]]
	*/

	set<string> bfs(const vector<vector<string>> &accounts,
		const unordered_map<string, vector<int>> &emailIndices,
		unordered_set<string> &visited,
		const string &email) {
		set<string> result;
		queue<string> qBFS;
		qBFS.push(email);
		while (!qBFS.empty()) {
			string curEmail = qBFS.front();
			qBFS.pop();
			result.insert(curEmail);
			if (visited.count(curEmail) != 0) continue;
			auto indices = emailIndices.at(curEmail);
			for (int indice : indices) {
				for (int j = 1; j < accounts[indice].size(); j++) {
					if (visited.count(accounts[indice][j]) == 0) {
						qBFS.push(accounts[indice][j]);
					}
				}
			}
			visited.insert(curEmail);
		}
		return result;

	}


	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
		unordered_map<string, vector<int>> emailIndices;
		for (int i = 0; i < accounts.size(); i++) {
			for (int j = 1; j < accounts[i].size(); j++) {
				if (emailIndices.count(accounts[i][j])) {
					emailIndices[accounts[i][j]].push_back(i);
				}
				else {
					emailIndices[accounts[i][j]] = vector<int>{ i };
				}

			}
		}

		vector<vector<string>> result;
		unordered_set<string> visited;
		for (auto emailIndice : emailIndices) {
			string email = emailIndice.first;
			vector<int> indice = emailIndice.second;
			string name = accounts[indice[0]][0];
			vector<string> resTemp;
			resTemp.push_back(name);
			if (visited.count(email) == 0) {
				for (auto siblings : bfs(accounts, emailIndices, visited, email)) {
					resTemp.push_back(siblings);
				}
				result.push_back(resTemp);
			}
		}
		return result;
	}
};