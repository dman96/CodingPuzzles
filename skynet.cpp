/*
The Following is a Solution to the Skynet Revolution Problem (Episode 1) on Codinggame.com (https://www.codingame.com/training/medium/skynet-revolution-episode-1).

This problem was solved using a modified breadth-first search approach. Unlike a standard queue in a traditional breadth-first search, a priority queue was used. If the virus is in proximity to a gateway, the link between the gateway and the virus is prioritized.
*/

#include <iostream>
#include <list>

class Graph
{

	public:
		Graph(int N); //Constructor
		void addEdge(int A, int B); //Adding An Edge
		void markGateway(int G); //Labelling the Gateway Nodes
		void linkCut(int C); //Cutting a Link Neighbouring the Virus
	
	private:
		int V; //Number of Nodes
		std::list<int> *adj; //Adjacency List
		std::list<int> queue; //A Queue
		bool *gateway; //The Gateway Nodes

};

Graph::Graph(int N)
{

	this->V = N; //Set number of nodes
	
	adj = new std::list<int>[V];
	gateway = new bool[V];
	
	//Initialized all Severed Nodes to False and Gateway Nodes to False
	for (int i = 0; i < V; i++)
	{
		gateway[i] = false;
	}
	
	
}


void Graph::addEdge(int A, int B)
{
	//Forming an Adjacency List
    adj[A].push_back(B);
    adj[B].push_back(A); 
}


void Graph::markGateway(int G)
{
	gateway[G] = true; //Marking a Gateway
}

//We will sever neighbour links to the virus. If the virus is next to a gateway, we must sever that link. Otherwise, sever an arbitrary neighbour link
void Graph::linkCut(int C)
{
	for (std::list<int>::iterator it = adj[C].begin(); it != adj[C].end(); it++)
	{
		if (gateway[*it] == true) //If the Neighbouring Node to Skynet is a Gateway, Add it to the Front of the Queue, Otherwise Add it to the Back
		{
			queue.push_front(*it);
		}
		
		else //Add the other nodes to the Queue
		{
			queue.push_back(*it);
		}
	}
	
	if (!queue.empty())
	{
		std::cout << C << " " << queue.front() << std::endl;
        queue.pop_front(); //Release the Frontmost Node
	}
}

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    std::cin >> N >> L >> E; std::cin.ignore();
    Graph Network(N); //Create a Graph Object, passing in the number of nodes
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        std::cin >> N1 >> N2; std::cin.ignore();
        Network.addEdge(N1,N2); //Creating an Adjacency List
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        std::cin >> EI; std::cin.ignore();
        Network.markGateway(EI); //Marking the Gateways
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        std::cin >> SI; std::cin.ignore();

       Network.linkCut(SI);
    }
}
