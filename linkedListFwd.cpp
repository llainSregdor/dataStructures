//Ben Rodgers 2019
//*************************************************************
//LINKED LIST FORWARD:
//A collection of nodes (items) with two components: 
//Data, & Address of next node in list
//-------------------------------------------------------------
//Needs 3 ptrs to build list forward:
//Permanent ptr to 1st node, permanent ptr to last node, temp ptr to create new node.
//*************************************************************

struct list_t
{
	struct node_t
	{   node_t *next;
	    void *data;
	};

	node_t *head, *tail;

	list()
	{	head = nullptr;
		tail = nullptr;
	}

	void addEnd(void *data)
	{//function to add new node to queue. Building forwards
		node_t *pt = new node_t;
		pt->data = data;
		pt->next = nullptr;
		if(head == nullptr) {head = pt;}
		else {tail->next=pt;}
		tail = pt;
	}
}
