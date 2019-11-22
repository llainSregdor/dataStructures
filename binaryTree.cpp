//Ben Rodgers 2019
//*****************************************************************************
//BINARY TREE:
//Either:
// - empty or contains: A left tree, a node containing a value, and a right 
//   tree.
//-----------------------------------------------------------------------------
//BINARY SEARCH TREE:
//Either:
// - empty, or contains: A node containing a key and a value, a left binary se-
//   arch tree with keys < node's value, and a right binary search tree with 
//   keys > node's value.
//-----------------------------------------------------------------------------
//There will be a pointer to the root of the binary tree stored outside of the
//tree in a ptr variable
//-----------------------------------------------------------------------------
//A BINARY TREE WITH THREE NODES:
//                  A
//                 / \
//                B   C
//-----------------------------------------------------------------------------
//NOMENCLATURE:
//
//LEAF - Node with no left and right children
//U is PARENT of V is there is a path from U to V
//PATH - Unique route between each node
//PATH LENGTH - Num. of branches on a path
//NODE LEVEL - Num. branches on path from root to the node.(Root level=0)
//TREE HEIGHT - Num. of nodes from a given leaf node to a given parent node.
//              Often to Root node.
//
//*****************************************************************************

//The following struct defines the node of a binary tree.
template <class elemType>
struct nodeType
{
    elemType info;//stores data
    nodeType<elemType> *lLink;//ptr to left child
    nodeType<elemType> *rLink;//ptr to right child
};//end nodeType

void copyTree(nodeType<elemType>* &copiedTreeRoot,
              nodType<elemType>* otherTreeRoot)
{//Function to copy given tree
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->lLink
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}//end copyTree()

void inOrder(nodeType<elemType> *p) const
{//Function for in order traversal of tree
    if ( p!= NULL)
    {
        inOrder(p->lLink);
        cout << p->info << " ";
        inOrder(p->rLink);
    }
}//end inOrder

void preOrder(nodeType<elemType> *p) const
{//function for Pre-order traversal of tree
    if (p != NULL)
    {
        cout << p->info << " ";
        preOrder(p->lLink);
        preOrder(p->rLink);
    }
}//end preOrder

void postOrder(nodeType<elemType> *p) const
{//function for Post-order traversal of tree
    if (p != NUll)
    {
        postOrder(p->lLink);
        postOrder(p->rLink);
        cout << p->infor << " ";
    }
}//end postOrder

int height(nodeType<elemType> *p)}
{//function to find height of a Binary tree
 //uses function max() to determine larger of two integers
    if (p == NULL) 
        return 0;
    else 
        return 1+max(height(p->lLink), height(p->rLink));
}//end height()
