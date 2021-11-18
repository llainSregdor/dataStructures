//Ben Rodgers 2019
//*****************************************************************************
//BINARY SEARCH TREE(BST)
//*****************************************************************************
//Binary search tree is either empty or:
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
                cout << "The item to be inserted is already in the tree \n";
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

template <clas elemType>
void bSearchTreeType<elemType>::deleteFromTree(nodeType<elemType>* &p)
{//
    nodeType<elemType> *current; //pointer to traverse tree
    nodeType<elemType> *trailCurrent; //pointer behind current
    nodeType<elemType> *temp; //pointer to delete node

    if (p == NULL)
    {
        cout << "Error: Node to be deleted is NULL" << endl;
    }
    else if (p->lLink == NULL && p->rLink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->lLink == NULL)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == NULL)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = NULL;

        while (current->rLink != NULL)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == NULL)
        p->lLink = current->lLink;

        else
            trailCurrent->rLink = current->lLink

        delete current;        
    }//end else
}//end deleteFromTree

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
    nodeType<elemType> *current; //Pointer to traverse tree
    nodeType<elemType> *trailCurrent; //Pointer behind current
    bool found = false;

    if(root = NULL)
    {
        cout<<"cannot delete from empty tree"<< endl;
    }

    else
    {
        while (current != NULL && !found)
        {
            if(current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }//end while
        
        if (current == NULL)
            cout << "Item to be delted is not in tree" << endl;
        else if (found)
        {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree" << endl;
    }

}//end deleteNode
