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


//*****************************************************************************
//MEMBER FUNCTION DEFINITIONS
//*****************************************************************************
//Definition of function create graph depends on how the data is input into the
//program. We assume data is input from file. In following form:
//5
//0 2 4 ... -999
//1 3 6 8 ... -999
//...
//*****************************************************************************

bool graphType::isEmpty() const
{
    return (gSize == 0);
}

void graphType::createGraph()
{
    ifstream inFile;
    char fileName[50];

    int index;
    int vertex;
    int adjacentVertex;

    if (gSize !=0) //if graph not empty, make it so.
        clearGraph();


    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;

    inFile.open(fileName);

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> gSize; //get num of vertices.

    for (index = 0; index < gSize; index++)
    {
        inFile >> vertex;
        inFile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        }//end while
    }//end for

    inFile.close();
}//end createGraph

void graphType::clearGraph()
{
    int index;

    for (index = 0; index < gSize; index++)
        graph[index].destroylist();

    gSize= 0;
}//end clearGraph.

void graphType::printGraph()
{
    int index;

    for(index = 0; index < gSize; index++)
    {
        cout << index << " ";
        graph[index].print();
        cout << endl;
    }
    
    cout << endl;
}//end printGraph

graphType::graphType(int size)
{//Constructor
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

graphType::~graphType()
{//Destructor
    clearGraph();
}
