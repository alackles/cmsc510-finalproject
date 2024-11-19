#include <iostream>
#include <vector>
#include <string>
#include <queue>

/*
WFS(s):
    put (null, s) into the bag
    while the bag is not empty
        take (p, v) from the bag
        if v is unmarked
            mark v
            parent(v) <- p 
            for each edge vw
            put (v, w) into the bag 
*/


class Graph {

private:

    std::vector<std::vector<int>> adjList;

public:

    // Constructor
    Graph(int numVertices) {
        adjList.resize(numVertices);
    }

    // Destructor
    ~Graph() {}

    // Add edge unidirectionally
    void addEdge(int i, int j) {
        adjList[i].push_back(j);
    }

    void DFS(int src) {
        std::vector<bool> visited(adjList.size(), false);   // initializes a vector to the size of the first argument, w/ second argument as default value
        std::queue<int> bag;                                //  *** bag in this case takes the form of a queue
        bag.push(src);
        while (!bag.empty()) {
            int v = bag.front();                              // ***    note the use of .front() instead of .top() 
            bag.pop();                                      // pop removes that element from the stack
            if (!visited[v]) {                              // our "visited" list is doing some heavy lifting here!
                std::cout << v << " ";                      // Print a node when we visit it for the first time
                visited[v] = true;
                for (auto elem : adjList[v]) {              // auto for-loop, only works on iterable items (like the linked list)
                    if (!visited[elem]) {                   // Add to bag if we haven't seen this one already
                        bag.push(elem);
                    }
                }
            }
        }
        std::cout << std::endl;                             // Flush the cout buffer
    }

    void toString() {
        for (int i = 0; i < adjList.size(); i++) {
            std::cout << i << " : ";
            for (int j = 0; j < adjList[i].size(); j++) {
                std::cout << adjList[i][j] <<  "->";
            }
            std::cout << "NULL\n";
        }
    }


};

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(3,1);
    g.toString();
    g.DFS(0);
    return 0;
}