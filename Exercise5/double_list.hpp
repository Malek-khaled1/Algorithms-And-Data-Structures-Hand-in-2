#ifndef _LIST_H_
#define _LIST_H_

template <typename Object>
class List {
  private:
	struct Node {
	    Object  data;
	    Node   *next;
		Node   *prev;
	};
	int   theSize;
	Node *head;
	Node *tail;

  public:
	List() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = nullptr;
	}

	~List() { clear(); delete head; delete tail; }

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear();
	void push_front(const Object x);
	void push_back(const Object x);
	Object pop_front();
	Object pop_back();
	Object find_kth(int pos);
};
#include <cassert>

template <typename Object>
void List<Object>::clear() {
	Node *p = head->next;
	while (p != tail) {
		Node *t = p->next;
		delete p;
		p = t;
	}
	head->next = tail;
	tail->prev = head;
}

template <typename Object>
void List<Object>::push_front(const Object x) {
	Node *p = new Node;
	Node *t = head->next;
	p->data = x;
	p->prev = head;
	p->next = t;
	t->prev = p;
	head->next = p;
	theSize++;
}

template <typename Object>
void List<Object>::push_back(const Object x) {
	Node *p = new Node;
	Node *t = tail->prev;
	p->data = x;
	p->prev = t;
	p->next = tail;
	t->next = p;
	tail->prev = p;
	theSize++;
}

template <typename Object>
Object List<Object>::pop_front() {
	Node *p = head->next;
	Node *t = p->next;
	Object x = p->data;
	t->prev = head;
	head->next = t;
	theSize--;
	delete p;
	return x;
}

template <typename Object>
Object List<Object>::pop_back() {
	Node *p = tail->prev;
	Node *t = p->prev;
	Object x = p->data;
	t->next = tail;
	tail->prev = t;
	theSize--;
	delete p;
	return x;
}

template <typename Object>
Object List<Object>::find_kth(int pos) {
	assert(pos >= 0 && pos < theSize);
	Node *p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p->data;
}



#endif
