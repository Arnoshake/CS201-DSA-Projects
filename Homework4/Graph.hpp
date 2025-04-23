#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <limits>

class Vertex {
public:
	bool visited;
	int distance;
	int previous;
	int finish;
	std::list<int> adj;
};

class Graph {
public:
	Graph(int V, int E, std::pair<int, int> *edges) {
		_V = V;
		_E = E;
		vertices = new Vertex[_V];
		for (int i = 0; i < _V; i++) {
                    vertices[i].visited = false;
                    vertices[i].distance = 65535; // Instead using INFINITY, you can use a large int number to initialize your graph
                    vertices[i].previous = -1;
		}
		for (int i = 0; i < _E; i++) {
		    addEdge(edges[i].first, edges[i].second);
		}
	}

	virtual ~Graph() {
		for (int i=0; i<_V; ++i) {
		    auto adj = vertices[i].adj;
		    adj.clear(); // clear list
		}

		delete[] vertices; // delete array of vertices
	}

	int V() {
		return _V;
	}

	int E() {
		return _E;
	}

	void addEdge(int u, int v) {
		vertices[u].adj.push_back(v);
	}

	std::list<int> getEdges(int u) {
		return vertices[u].adj;
	}

	int degree(int u) {
		return vertices[u].adj.size();
	}

	void bfs(int s) {
		// s tracks the index of the vertex within the array repersenting the graph
		for (int i = 0; i < _V;i++){ //clears the vertex traversal data
			vertices[i].visited = false;
			vertices[i].distance = INT_MAX;
			vertices[i].previous = -1;
		}
		
		vertices[s].visited = true;
		int distanceTraveled = 0;
		vertices[s].distance = distanceTraveled;
		
		std::list<int> queue; //using std::list as other variables use it
		queue.push_back(s);
		std::cout <<"Process started!\n";
		int currentVertexIndex;
		while (!queue.empty()){
			currentVertexIndex = queue.front(); // store the value, then delete it
			queue.pop_front();
			std::list<int>::iterator it; 
			for (it = vertices[currentVertexIndex].adj.begin() ; it !=  vertices[currentVertexIndex].adj.end() ;it++){ //iterate through every adjacent node/vertex
					int adjacent = *it;
				if (vertices[adjacent].visited == false){ //if this node has not been visited
					vertices[adjacent].visited = true;
					vertices[adjacent].distance = ++distanceTraveled; //update this vertex's distance from origin
					vertices[adjacent].previous = currentVertexIndex;
					//std::cout <<"\nAdding: " << adjacent;
					queue.push_back(adjacent); //add the adjacent
				}
			}
		}

	}
	int time;
	int finishedTime;
	enum{
		white, gray, black
	};
	void dfs() {
		finishedTime = 0;
		time = 0;
		for (int i = 0; i < _V;i++){ //clears the vertex traversal data
			vertices[i].visited = white;
			vertices[i].distance = 0;
			vertices[i].previous = -1;
		}
		
		// your implementation goes here
		for (int u = 0; u < _V ; u++){
			if (vertices[u].visited == white){
				dfs_visit(u);
			}
		}
	}

	void dfs_visit(int u) {
		time++;
		vertices[u].distance = time;
		vertices[u].visited = gray;
		std::cout << u << " "; // On discover
		std::list<int>::iterator it; 
		for (it = vertices[u].adj.begin() ; it !=  vertices[u].adj.end() ;it++){ //iterate through every adjacent node/vertex
			int v = *it;
			if (vertices[v].visited == white){
				vertices[v].previous = u;
				dfs_visit(v);
			}
		}
		time++;
		finishedTime = time;
		vertices[u].distance = finishedTime;

		std::cout << u << " "; // On finish
	}

	void print_path(int s, int v) {
		if (v == s)
		   std::cout << s;
		else if (vertices[v].previous == -1)
		   std::cout << "not connected";
		else {
		   print_path(s,vertices[v].previous);
		   std::cout << "->" << v;
		}
	}

	std::string toString() {
		std::stringbuf buffer;
		std::ostream os(&buffer);
		os << "Vertices = " << _V << ", Edges = " << _E << std::endl;
		for (int i = 0; i < _V; ++i) {
		    os << i << "(" << degree(i) << "): ";
		    for (const auto& l : vertices[i].adj) 
			os << l << " ";
		    os << std::endl;
		}

		return buffer.str();
	}
private:
	int _V; // no. of vertices
	int _E; // no. of edges
	Vertex *vertices; // array of vertices
};

#endif
