#pragma once
#include <cassert>

template<class T>
class Node;

template<class T>
class DoublyLinkedList
{
	friend class Node<T>;
public:

	Node<T>* peekFirst() {
		assert(!empty());
		return head;
	}


	Node<T>* addFirst(T t) {
		Node<T>* node = new Node<T>(this, t);

		if (empty()) {
			head = node;
			tail = node;
		} else {
			node->next = head;
			head->prev = node;
			head = node;
		}

		list_size++;
		return node;
	}

	Node<T>* removeLast() {
		assert(!empty(), "List is empty.");

		Node<T>* last = tail;
		last->remove();

		return last;
	}

	size_t size() const {
		return list_size;
	}

	bool empty() const {
		if (head == nullptr) {
			assert(tail == nullptr);
			return true;
		}
		return false;
	}


private:
	Node<T> *head = nullptr, *tail = nullptr;

	size_t list_size = 0;
};

template<class T>
class Node
{
	friend class DoublyLinkedList<T>;

public:
	Node(DoublyLinkedList<T>* father, T t) {
		this->list = father;
		this->value = t;
	}

	T getValue() const {
		return value;
	}

	void remove() {
		assert(!deleted, "This node is already deleted.");
		assert(!list->empty());

		deleted = true;
		list->list_size--;

		if (prev != nullptr) {
			prev->next = next;
		}

		if (next != nullptr) {
			next->prev = prev;
		}

		if (this == list->head) {
			list->head = list->head->next;
		}
		if (this == list->tail) {
			list->tail = list->tail->prev;
		}
	}
private:
	T value;
	bool deleted = false;
	Node<T>* prev = nullptr, * next = nullptr;
	DoublyLinkedList<T>* list;
};