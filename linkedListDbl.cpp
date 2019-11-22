//Ben Rodgers 2019
//*************************************************************
//DOUBLY LINKED LIST:
//*************************************************************

struct list_t
{
	struct node_t
	{   node_t *prev;
		node_t *next;
	    void *data;
	};

	node_t anchor;

	dbllist()
	{	anchor.next = &anchor;
		anchor.next = &anchor;
	}

	void add(void *data)
	{//function to add new node.
		node_t *node = new node_t();
		node->data = data;
		node->next = anchor.next;
		node->next->prev = node;
		node->prev = &anchor;
		anchor.next = node;
	}

	void printAll()
	{//function to print all nodes
		for (node_t *node=anchor.next; node != anchor; node=node->next)
		{printTheNode(node->data);
		}
	}

	void del()
	{//function to delete a node
		node->next->prev = node->prev;
		node->prev->next = node->next;
		freeTheData(node->data);
		delete node;

	}
}
