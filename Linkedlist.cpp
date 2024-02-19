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
	void deletelastnode() {
		if (count == 0)
			return;
		Node* temp1 = head;
		Node* temp2 = head;
		while (temp1->next) {
			temp2 = temp1;
			temp1 = temp1->next;
			
		}
		tail = temp2;
		tail->next = NULL;
		count--;
		if (count == 0) {
			head = NULL;
			tail = NULL;

		}
		delete temp1;
	}
	void firstnode(int deger) {
		
};
int main() {
	cout << "------------------------------" << endl;
	linkedlist* linkedlist1 = new linkedlist(1);
	linkedlist1->appentlist(2);
	linkedlist1->appentlist(3);
	linkedlist1->appentlist(4);
	linkedlist1->appentlist(5);
	linkedlist1->getcount();//5
	linkedlist1->printhead();//1
	linkedlist1->printtail();//5
	linkedlist1->printlist();// 1-2-3-4-5 
	cout << "------------------------------" << endl;
	linkedlist1->deletelastnode();
	linkedlist1->deletelastnode(); //2 kere silme yapýldý
	linkedlist1->getcount();//3
	linkedlist1->printhead();//1
	linkedlist1->printtail();//3
	linkedlist1->printlist();// 1-2-3
	cout << "------------------------------" << endl;
	}
	