//*****************************************************************************
//BINARY SEARCH TREE(BST)
//*****************************************************************************
//Binary search tre is either empty or:
//Has a root node, two sets of nodes: the left subtree and right subtree.
//Key in root node is larger than every key in the left subtree & smaller
//than every key in the right subtree. The left and right subtrees are
//binary search trees.
//*****************************************************************************
//The following defines a binary search tree as an ADT by extending the 
//definition of the binary tree.
//*****************************************************************************


template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
     //Function to determine i searchItem is in the binary
     //searc tree.
     //Postcondition:   Returns true if searchItem is found
     //                 within the binary search tree.
     //                 Otherwise, returns false.

    void insert(const elemType& insertItem);
     //Function to insert insertItem into the binary search tree.
     //Postcondition:   If no node in BST that has same info as
     //                 insertItem, a node with the info provided
     //                 is created and inserted in the BST.
    
    void deleteNode(const elemType& deleteItem);
     //Function to delete deleteItem from BST
     //Postcondition:   If a node with the same info as deleteItem
     //                 is found, it is deleted from the BST.
     //                 If BST is empty or deleteItem is not found
     //                 an appropriate error message is printed.

private:
    void deleteFromTree(nodeType<elemType>* &p);
     //Function to delete the node to which p points.
     //Postcondition:   The node to which p points is deleted
     //                 from the BST.
};

//*****************************************************************************
//NON ABSTRACT MEMBER FUNCTION DECLARATIONS OF bSearchTreeType
//*****************************************************************************

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const;
{
    nodeType<elemType> *current;
    bool found = false;

    if (root == NULL)
        cout<< "cannot search an empty tree."<< endl
    else
    {
            current = root;

            while (current != NULL && !found)
            {
                if (current->info == searchItem)
                    found = true;
                else if (current->info > searchItem)
                    current = current->lLink;
                else
                    current = current->rLink;                
            }//End while
    }//End else

    return found;
}//End search

template <class elemType>
void bSearchTree<elemType>::insert(const elemtype& insertItem)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *newNode;

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = NULL;
    newNode->rLink = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;

        while (current != NULL)
        {
            trailCurrent = current;

            if(current->info)
            {
                cout << "The item to be inserted is already in the tree \n"
                cout << "Duplicates are not allowed." << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailcurrent->lLink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
    
}//end insert
