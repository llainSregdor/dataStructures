//Ben Rodgers 2019
//*****************************************************************************
//GRAPHS AS ABSTRACT DATA TYPE
//*****************************************************************************

class graphType
{
public:
    bool isEmpty() const;
      //Function to determine whether the graphy is Empty.
      //Postcondition:  Returns True if graph is empty
      //                Otherwise returns False.

    void createGraph();
      //Function to create a graph.
      //Postcondition:  The graph is created using the 
      //                adjacency list representation.

    void clearGraph();
      //Function to clear graph.
      //Postcondition:  The memory occupied by each vertex is deallocated.

    void printGraph();
      //Function to print graph.
      //Postcondition:  The graph is printed.

    void depthFirstTraversal();
      //Function to perform depth first traversal of the entire graph.
      //Postcondition:  The vertices of the graph are printed using 
      //                depth first traversal algorithm.

    void dftAtVertex(int vertex);
      //Function to perform a depth first traversal of the graph at a 
      //specified node indicated by given vertex parameter.
      //Postcondition:  Starting at vertex, the vertices are returned
      //                using depth first traversal algorithm.

    void breadthFirstTraversal();
      //Function to perform breadth first traversal of entire graph.
      //Postcondition: The vertices of the graph are printed using
      //               breadth first traversal algorithm.

    graphType(int size = 0);
      //Constructor.
      //Postcondition:  gSize = 0, maxSize = size. Graph is an array of 
      //                pointers to linked lists.

    ~graphType();
      //Destructor.
      //Postcondition:  The storage occupied by the vertices is deallocated.

protected:
    int maxSize; //max number of vertices.
    int gSize;   //current number of vertices.
    unorderedLinkedList<int> *graph //array to create adjacency lists.

private:
    void dft(int v, bool visited[]);
      //Function to perform the depth first traversal of the graph at a a node
      //specified by the parameter v. This function is used by the public 
      //memberfunctions depthFirstTraversal & dftAtVertex/
      //Postcondition:  Starting at v, the vertices are printed using a depth
      //                first traversal algorithm.
}