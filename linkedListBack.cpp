//Ben Rodgers
//*************************************************************
//LINKED LIST BACKWARD:
//A collection of nodes (items) with two components: 
//Data, & Address of next node in list
//*************************************************************

struct list_t
{
	struct node_t
	{   node_t *next;
	    void *data;
	};

	node_t *head;

	list()
	{	head = nullptr;
	}

	void add(void *data)
	{//function to add new node to stack. Building backwards
		node_t *pt = new node_t;
		pt->data = data;
		pt->next = head;
		head = pt;
	}

	void ~list()
	{//function to delete whole list
		node_t *p = head;
		while(p != NULL)
		{	deleteTheData(p->data);
			node_t *prev = p;
			p = p->next;
			delete prev;
		}
	}

	void *pop()
	{//function to delete single node
		list_t *pt = head;
		if(pt == nullptr) return nullptr;
		void *data = pt->data;
		head = pt->next;
		delete pt;
		return data;
	}
}

main(){
	//List traversal
	for(list_t *p=list; p!=nullptr; p=p->next)
	{	performAction(p->data);
	}

}
