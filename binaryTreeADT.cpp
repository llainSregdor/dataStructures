//Ben Rodgers 2019
//*****************************************************************************
//BINARY TREE IMPLEMENTED AS AN ABSTRACT DATA TYPE (ADT)
//*****************************************************************************

//Definition of the Node
template<class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

//definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
                (const binaryTreeType<elemType>&);
        //overload assignment operator

    bool isEmpty() const;
     //Function to determine whether the binary tree is empty.
     //Postcondition:    returns true if the binary tree is empty:
     //                  otherwise, returns false

    void inOrderTraversal() const;
     //Function to do an inorder traversal of the binary tree.
     //Postcondition:    Nodes are printed in inorder sequence.

    void preOrderTraversal() const;
     //Function to do a preorder traversal of the binary tree.
     //Postcondition:    Nodes are printed in preorder sequence.

    void postOrderTraversal() const;
     //Function to do a postorder traversal of the binary tree.
     //Postcondition:    Nodes are printed in postorder sequence.

    int treeHeight() const;
     //Function to determine height of a binary tree.
     //Postcondition:    Return height of the binary tree.

    int treeNodeCount() const;
     //Function to determine number of nodes in a 
     //binary tree.
     //Postcondition:    Returns number of nodes in
     //                  a binary tree.

    int treeLeavesCount() const;
     //Function to determine the number of leaves
     //within a binary tree.
     //Postcondition:    Returns number of leaves
     //                  in a binary tree.

    void destroyTree();
     //Function to destroy the binary tree.
     //postcondition:    Memory space occupied by
     //                  each node is deallocated

    virtual bool search(const elemType& searchItem) = 0;
     //Function to determine if searchItem is within the 
     //binary tree.
     //Postcondition:   Returns true if searchItem is found
     //                 otherwise, returns false
    
    virtual void insert(const elemType& insertItem) = 0;
     //Function to insert insertItem into the binary tree.
     //Postcondition:   If there is no node in the binary tree
     //                 that has the same info as insertItem
     //                 a node with the new info is created and
     //                 and inserted into the binary tree.

    virtual void deleteItem(const elemType& deleteItem) = 0;
     //Function to delete deleteItem from binary tree.
     //Postcondition:   If a node with the same info as
     //                 deleteItem is found, it is removed
     //                 from the binary tree. 
     //                 If binary tree is empty, or deleteItem
     //                 is not within tree, then an appropriate
     //                 error is thrown.

    binaryTreeType (const binaryTreeType<elemType>& otherTree);
     //copy constructor
    
    binaryTreeType();
     //Default constructor

    ~binaryTreeType();
     //Default destructor

protected:
    nodeType<elemType> *root;

private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
     //Makes a copy of the binary tree to which
     //otherTreeRoot points.
     //Postcondition:   The pointer copiedTreeRoot points to
     //                 the root of the copied binary tree

    void destroy(nodeType<elemType>* &p);
     //Function to destroy the binary tree to which p points.
     //Postcondition:   Memory space occupied by each node in
     //                 which p points is deallocated.
     //                 P=NULL

    void inOrder(nodeType<elemType> *p) const;
     //Function to do an inorder traversal of the binary tree
     //to which p points.
     //Postcondition:   Nodes of the binary tree are printed
     //                 in inorder sequence.

    void postOrder(nodeType<elemType> *p) const;
     //Function to perform a postorder traversal of the
     //binary tree to which p points.
     //Postcondition:   Nodes of the binary tree are printed
     //                 in postorder sequence.

    void preOrder(nodeType<elemType> *p) const;
     //Function to perform a preorder traversal of the
     //binary tree to which p points.
     //Postcondition:   Nodes of the binary tree are printed
     //                 in preorder sequence.

    int height(nodeType<elemType> *p) const;
     //Function to determine the height of the binary tree
     //to which p points.
     //Postcondition:   Integer value of the height of binary
     //                 tree to which p points is returned.

    int max(int x, int y) const;
     //Function to determine the larger of x and y.
     //Postcondition:   Return the larger of x and y.

    int nodeCount(nodeType<elemType> *p) const;
     //Function to determine the number of nodes within the
     //binary tree to which p points.
     //Postcondition:   The number of nodes in the binary
     //                 tree pointed to by p is returned.

    int leaveCount(nodeType<elemType> *p) const;
     //Function to determine the number of leaves within the
     //binary tree to which p points.
     //Postcondition:   The number of leaves in the binary tree
     //                 pointed to by p is returned.
};

//*****************************************************************************
//NON ABSTRACT MEMBER FUNCTION DECLARATIONS OF binaryTreeType
//*****************************************************************************
//NOTE MISSING: nodeCount, leavesCount (To be added at a later time)

template <class elemType>
bool binaryTreeType<elemType>::isEmpty()
{//Binary tree is empty, if binary tree's root = NULL
    return(root==NULL);
}//end isEmpty

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{ //defualt constructor
    root = NULL;
}//end Constructor

template <class elemType>
void binaryTreeType<elemType>::inOrderTraversal() const
{
    inOrder(root);
}//end inOrderTraversal

template <class elemType>
void binaryTreeType<elemType>::preOrderTraversal() const
{
    preOrder(root);
}//end preOrderTraversal

template <class elemType>
void binaryTreeType<elemType>::postOrderTraversal() const
{
    postOrder(root);
}//end postOrderTraversal

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}//end treeHeight

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return treeNodeCount(root);
}//end treeNodeCount

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}//end treeLeavesCount

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}//end destroyTree

template <class elemType>
void binaryTreeType<elemType>::inOrder
                                (nodeType<elemType> *p) const
{
    if (p != NULL)
    {
        inOrder(p->lLink);
        cout << p->lLink << " ";
        inOrder(p->rLink);
    }
}//end inOrder

template <class elemType>
void binaryTreeType<elemType>::preOrder
                                (nodeType<elemType> *p) const
{
    if (p != NULL)
    {
        cout<< p->info << " ";
        preOrder(p->lLink);
        preOrder(p->rLink);
    }
}//end preOrder

template <class elemType>
void binaryTreeType<elemType>::postOrder
                                (nodeType<elemType> *p) const
{
    if(p != NULL)
    {
        postOrder(p->lLink);
        postOrder(p->rLink)l
        cout << p->info << " ";
    }
}//end postOrder

template <class elemType>
int binaryTreeType<elemType>::height
                                (nodeType<elemType> *p) const
{
    if (p==NULL) 
        return 0;
    else
        return 1+max(height(p->lLink), height(p->rLink));
}//end height

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x>- y)
        return x;
    else
        return y;
}//end max

template <class elemType>
void binaryTreeType<elemType>::copyTree
                        (nodeType<elemType>* &copiedTreeRoot,
                         nodeType<elemType>* &otherTreeRoot)
{
    if(otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}//end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }
}//end destroy


template <class elemType>
binaryTreeType<elemType>::binaryTreeType
                (const binaryTreeType<elemType>& otherTree)
{//copy constructor to avoid shallow copying of data
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}//end copy constructor

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{//Destructor
    destroy(root);
}

template <class elemType>
const binaryTreeTyp<elemType>& binaryTreeType<elemType>::
        operator= (const binaryTreeType<elemType>& otherTree)
{//Overloading the assignment operator
    if (this != otherTree) // avoid self-copy
    {
        if (root != NULL)
            destroy(root);

        if (otherTree.root == NULL)//otherTree is empty
            root = NULL;
        else
            copyTree(root,otherTree.root);
    }

    return *this;
}
