//137. Clone Graph
//Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.
//
//How we serialize an undirected graph :
//
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
//
//As an example, consider the serialized graph{ 0,1,2#1,2#2,2 }.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
//Visually, the graph looks like the following :
//
//1
/// \
/// \
//0 -- - 2
/// \
//\_ /
//Example
//return a deep copied graph.

//Solution 1: BFS
/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/


class Solution {
public:
	/*
	* @param node: A undirected graph node
	* @return: A undirected graph node
	*/
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
		if (!node) return NULL;
		UndirectedGraphNode* resRoot = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> bfs;
		bfs.push(node);
		queue<UndirectedGraphNode*> resQueue;
		resQueue.push(resRoot);
		unordered_map<int, UndirectedGraphNode*> visited;
		visited[resRoot->label] = resRoot;
		while (!bfs.empty()) {
			UndirectedGraphNode* cur = bfs.front(); bfs.pop();
			UndirectedGraphNode* target = resQueue.front(); resQueue.pop();
			//if (visited.find(target->label) != visited.end()) continue;
			for (int i = 0; i < cur->neighbors.size(); i++) {
				UndirectedGraphNode* curNeigh = cur->neighbors[i];
				UndirectedGraphNode* newNeigh;
				if (visited.find(curNeigh->label) == visited.end()) {
					newNeigh = new UndirectedGraphNode(curNeigh->label);
					bfs.push(curNeigh);
					resQueue.push(newNeigh);
					visited[curNeigh->label] = newNeigh;
				}
				else newNeigh = visited.find(curNeigh->label)->second;
				target->neighbors.push_back(newNeigh);
			}
		}
		return resRoot;
	}
};

//Solution 2: BFS, one queue
//Reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-clone-graph.html
/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/


class Solution {
public:
	/*
	* @param node: A undirected graph node
	* @return: A undirected graph node
	*/
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
		if (!node) return NULL;
		queue<UndirectedGraphNode*> bfs;
		bfs.push(node);
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
		UndirectedGraphNode* resRoot = new UndirectedGraphNode(node->label);
		visited[node] = resRoot;
		while (!bfs.empty()) {
			UndirectedGraphNode* cur = bfs.front(); bfs.pop();
			UndirectedGraphNode* curTar = visited[cur];
			for (int i = 0; i < cur->neighbors.size(); i++) {
				UndirectedGraphNode* curNeigh = cur->neighbors[i];
				UndirectedGraphNode* newNeigh;
				if (visited.count(curNeigh)) {
					newNeigh = visited.find(curNeigh)->second;
				}
				else {
					newNeigh = new UndirectedGraphNode(curNeigh->label);
					bfs.push(curNeigh);
					visited[curNeigh] = newNeigh;
				}
				curTar->neighbors.push_back(newNeigh);
			}
		}
		return resRoot;
	}
};