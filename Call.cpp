#include "Call.h"



Call::Call()
{
	head = NULL;
	tail = NULL;
	length = 0;
}


Call::~Call()
{
}

bool Call::enqueue(string relation, int priority)
{
	bool enque = false;
	Node* location = new Node(relation, priority);
Node* newNode = new Node;
	location->relation = relation;
	location->priority = priority;
	if (head == NULL)
	{
		head = location;
		tail = location;
		location->next = NULL;
		length++;
		enque = true;
	}
	else  if (priority <= head->priority)
	{
		location->next = head;
		head->prev = location;
		head = location;
		length++;
		enque = true;
	}

	else if (priority >= tail->priority)
	{
		location->next = NULL;
		tail->next = location;
		location->prev = tail;
tail = location;
		enque = true;
	}

	else
	{
		newNode = head;
		while (newNode->next != NULL && (newNode->next)->priority <= priority)
		{
			newNode = newNode->next;
			location->next = newNode->next;

		}
		location->next = newNode->next;
		newNode->next = location;

	}
	return enque;
}
bool Call::dequeue(int& noderelation, int& nodePriority)
{
	bool deleted;
	Node *tmp;
	if (head == NULL)
	{
		cout << "nothing to delete" << endl;
		deleted = false;
	}

	else
	{
		tmp = head;
		head = head->next;
		(head->next)->prev = NULL;
		delete tmp;
		length--;
		deleted = true;
	}
	return deleted;
}
void Call::printQueueContent()
{
	Node *temp;
	temp = head;

	if (head == NULL)
		cout << "queue is empty" << endl;
	else
	{
		while (temp != NULL)
		{
			cout << temp->relation <<"\n ";
			temp = temp->next;
		}
		cout << endl;
	}
}
