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
	~linkedlist() {
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
	void addfirstnode(int deger) {
		Node* newNode = new Node(deger);
		if (count == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		count++;
	}
	void deletefirstnode() {
		if (count == 0)
			return;
		else
			head = head->next;
		count--;

	}
	Node* getnode(int index) {
		if (index < 0 || index >= count)
			return NULL;
		Node* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
	bool setvalue(int index, int yenideger) {
		Node* temp = this->getnode(index);
		if (temp != NULL) {
			temp->deger = yenideger;
			return true;
		}
		return false;
	}
	bool insertNode(int index, int deger) {
		if (index < 0 || index > count)
			return false;
		if (index == 0) {
			addfirstnode(deger);
			return true;
		}
		if (index == count) {
			appentlist(deger);
			return true;
		}
		Node* yeninode = new Node(deger);
		Node* temp = getnode(index - 1);
		yeninode->next = temp->next;
		temp->next = yeninode;
		count++;
		return true;
	}
	void deletenode(int index) {
		if (index >= 0 && index < count) {
			if (index == 0)
				deletefirstnode();
			else if (index == count - 1)
				deletelastnode();
			else {
				Node* del = getnode(index);
				Node* temp = getnode(index - 1);
				temp->next = del->next;
				delete del;
				count--;
			}

		}
	}

	

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
	linkedlist1->deletelastnode(); //2 kere silme yapıldı
	linkedlist1->getcount();//3
	linkedlist1->printhead();//1
	linkedlist1->printtail();//3
	linkedlist1->printlist();// 1-2-3
	cout << "------------------------------" << endl;
	linkedlist1->addfirstnode(24);
	linkedlist1->getcount();//4
	linkedlist1->printhead();//24
	linkedlist1->printtail();//3
	linkedlist1->printlist();// 24-1-2-3
	cout << "------------------------------" << endl;
	linkedlist1->deletefirstnode();
	linkedlist1->getcount();//3
	linkedlist1->printhead();//1
	linkedlist1->printtail();//3
	linkedlist1->printlist();//1-2-3
	cout << "------------------------------" << endl;
	linkedlist1->setvalue(2,50);
	linkedlist1->getcount();//3
	linkedlist1->printhead();//1
	linkedlist1->printtail();//50
	linkedlist1->printlist();//1-2-50
	cout << "------------------------------" << endl;
	linkedlist1->insertNode(2,41);
	linkedlist1->insertNode(1,3);
	linkedlist1->getcount();//4
	linkedlist1->printhead();//1
	linkedlist1->printtail();//50
	linkedlist1->printlist();//1-2-50
	cout << "------------------------------" << endl;
	linkedlist1->deletenode(1);
	linkedlist1->getcount();//4
	linkedlist1->printhead();//1
	linkedlist1->printtail();//50
	linkedlist1->printlist();//1-2-41-50
	cout << "------------------------------" << endl;
	linkedlist1->appentlist(51);
	linkedlist1->appentlist(52);
	linkedlist1->appentlist(53);
	linkedlist1->deletelastnode();
	linkedlist1->addfirstnode(17);
	linkedlist1->setvalue(4, 99);
	linkedlist1->insertNode(1, 44);
	linkedlist1->insertNode(2, 9);
    linkedlist1->getcount();//9
	linkedlist1->printhead();//17
	linkedlist1->printtail();//52
	linkedlist1->printlist();//17 , 44 , 9 , 1 , 2 , 41 , 99 , 51 , 52
	delete linkedlist1;
	}