#include<iostream>
using namespace std;

struct node
{
	node* next;
	node* previous;
	int number;

	node()
	{
		next = NULL;
		previous = NULL;
		number = 0;
	}
};



class LinkedList
{
private:
	node* head;
	node* prev;
	node* cur; // pointer to current node

	//static int size; // variable that keeps track of the number of nodes created (size of linked list)
public:

	LinkedList()
	{
		head = NULL; // pointer to very first node
		prev = NULL; // pointer to previous node
		cur = NULL; // pointer to current node
		//size = 0;
	}

	//static void setSize()
	//{
	//	size = 0;
	//}



	void first() const
	{
		if (head == NULL)
		{
			cout << "No first element found since the list is empty" << endl;
		}
		else
		{
			cout << "First number in list is " << head->number << endl;
		}
	}


	void last()
	{
		if (head == NULL)
		{
			cout << "No last element found since the list is empty" << endl;
		}
		else
		{
			node* k = head;
			while (k->next != NULL)
			{
				k = k->next;
			}
			cout << "Last number in list is " << k->number << endl;
		}
	}
	
	
	void insert(int element)
	{
		bool found = false, reachedLastNode = false;
		//checking if element already exists, if so then it wont get inserted
		cur = head;

		if (cur != NULL)
		{
			while ((found == false) && (reachedLastNode == false)) // checks if element is already present until we reach the last node (head points to NULL)
			{
				if (cur->number != element)
				{
					cur = cur->next;
					if (cur == NULL)
					{
						reachedLastNode = true;
					}
				}
				else
				{
					found = true;
				}
			}
		}

		// inserting
		if (found == true)
		{
			cout << "\nCannot insert element " << element << " again since it's already in the list\n";
		}
		else
		{ // inserting the very first node, it's a special case
			if (head == NULL)
			{
				// inserting at end of list everytime:
				cur = new node;
				cur->number = element;
				cur->next = NULL;
				cur->previous = NULL;
				head = cur;

				//size++;

				cout << "Element " << element << " added (first node)\n";
			}

			else
			{
				prev = head;
				// we want head to point at last node so we:
				while (prev->next != NULL)
				{
					prev = prev->next;
				}
				// ^ now the pointer prev is pointing to last node
				cur = new node;
				cur->number = element;

				cur->next = NULL;
				prev->next = cur;
				cur->previous = prev;
				//size++;
				
				
				// sorting algorithm
				if (head->next != NULL)
				{
					//node* a, *b , * c = head; // pointers that traverse the linked list using this sorting algorithm
					
					for (node *i=head; i->next->next!=NULL; i=i->next)
					{
						/*a = c;
						b = c->next;*/
						for (node *j = head->next; j!=NULL ; j=j->next)
						{
							if ( i->number > j->number)
							{
								swap(i->number, j->number);
							}

							/*a = a->next;
							b = b->next;*/
						}
					}
				//	c = c->next;
				}


				cout << "Element " << element << " added\n";
			}
		}
	}



	void remove(int element)
	{
		cur = head;
		prev=NULL;
		bool isInserted = false;
		while ((cur != NULL) && (isInserted == false))
		{
			if (cur->number == element)
			{
				isInserted = true;
			}
			
			else
			{
			//	prev->previous = cur; // hases feeh haga ghalat hena fel updating bta3 previous 3shan the pointer prev is not moving sah??? it's just updating the previous not the prev position
				prev = cur; // i added this
				cur = cur->next;
			}
		}


		// if element not found
		if (isInserted == false)
		{
			cout << "Element "<< element<<" couldn't be removed since it's not in the list" << endl;
			return;
		}
		else //starting from here the element IS found but we're gonna be considering all possible positions that this element could be found inside our linked list (at first/last node or in the middle)
		{


		if ( cur==NULL) //pointing to head node, if we are deleting the first node
		{
		cout << "Cannot remove element " << element << " since list is still empty" << endl;
		return;
		}

		//if list only consists of first node only (cur at head)
		else if ((cur->next==NULL) && (cur->previous==NULL))      /*cur->previous == NULL */ //pointing to head node, if we are deleting the first node)
		{
			delete cur;
		//	--size;
			head = NULL;
			cur = NULL;
			prev = NULL;

			cout << "Element " << element << " removed\n";
		}
		
		//at first node but there are other nodes after it
		else if ((cur->next != NULL) && (prev == NULL))
		{
			head= cur->next;

			head->previous = NULL; // not sure about that, first time trying this syntax
			delete cur;
			prev = NULL;
		//	--size;

			cout << "Element " << element << " removed\n";
		}

		else if ((cur->next == NULL) && (prev!=NULL)) // deleting last node
			{
				prev->next = NULL;
				delete cur;
			//	--size;

				cout << "Element " << element << " removed\n";
			}

		// deleting a node in the middle
			else if ((prev!=NULL) && (cur!=NULL))
			{
				prev->next = cur->next;
				node* x;
				x = cur->next;
				x->previous = prev;
				delete cur;
			//	--size;

				cout << "Element " << element << " removed\n";
			}
		}
	}



	void print()
	{
		if (head == NULL)
		{
			cout << "No numbers inserted yet. List is empty" << endl;
		}
		else
		{
			node* p = head;
			while (p != NULL)
			{
				cout << p->number << "  ";
				p = p->next;
			}
			cout << endl;
		}
	}

	//void reverse()
	//{

	//}

};


	int main()
	{
		LinkedList l;
		

		l.insert(2);
		l.insert(3);
		l.insert(-12);
		l.insert(17);
		l.insert(16);
		l.insert(13);
		l.print();
		l.remove(13);
		l.print();


		return 0;
	}