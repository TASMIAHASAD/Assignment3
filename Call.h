#ifndef CALL_H_INCLUDED
#define CALL_H_INCLUDED

#include<iostream>
#include<string>
#include"Person.h"
#include"Customer.h"

using namespace std;


class Call : Person
{


public:
	struct Node {
		Node* next;
		Node* prev;
		string relation;
		int priority;
		Node(string relation, int priority)
		{
			this->relation = relation;
			this->priority = priority;
			next = NULL;
			prev = NULL;
		}
Node()
		{
			this->relation = "";
			this->priority = INT_MAX;
			next = NULL;
			prev = NULL;
		}
		~Node()
		{
			cout << "Deleting node(relation,priority): (" << relation << "," << priority << ")" << endl;
		}
	};
		Call();
		~Call();
		bool enqueue(string relation, int priority);
		bool dequeue(int& noderelation, int& nodePriority);
		void printQueueContent();

private:
	Node * head;
	Node * tail;
	int length;

};
#endif //CALL_H_INCLUDED
