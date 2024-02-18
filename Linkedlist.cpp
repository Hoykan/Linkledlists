#include <iostream>
using namespace std;
class Node {
public:
	int deger;
	Node* next;
	Node(int deger) {
		this->deger = deger;
		next = NULL;
	}
};
class linkedlist {
private:
	Node* head;
	Node* tail;
	int count;
public:
	linkedlist(int deger) {
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}
	linkedlist() {
		cout << "destructor is called";
		// Destructor(memory leak icin)
		Node* tmp = head;
		while (head) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
	void printhead() {
		if(head != NULL)
		cout << "Head: " << head->deger << endl;
	}
	void printtail() {
		if (tail != NULL)
			cout << "Tail: " << tail->deger << endl;
	}
	void getcount() {
			cout << "count: " << count << endl;
	}
	void appentlist(int deger) {
		Node* node = new Node(deger);
		if (count == 0) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		count++;
	}
	void printlist() {
		Node* tmp = head;
		while (tmp != NULL) {
			cout << tmp->deger << " , ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};
int main() {
	linkedlist* linkedlist1 = new linkedlist(1);
	linkedlist1->appentlist(2);
	linkedlist1->appentlist(3);
	linkedlist1->appentlist(4);
	linkedlist1->appentlist(5);
	linkedlist1->getcount();//5
	linkedlist1->printhead();//1
	linkedlist1->printtail();//5
	linkedlist1->printlist();// 1-2-3-4-5 
	}
	