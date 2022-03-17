#pragma once
#include "DoublyLinkedList.h"
#include <map>

template<class K, class V>
class lru_cache
{
public:

	lru_cache(size_t capacity) {
		this->capacity = capacity;
	}

	V get(K key) {
		if (!keyToNode.contains(key)) {
			return V();
		}

		Node<std::pair<K, V>>* node = keyToNode[key];

		//put(key, node->getValue()->second);

		assert(keyToNode.contains(key));
		assert(keyToNode[key]->getValue() == node->getValue());
		assert(keyToNode[key] == list.peekFirst());
		return node->getValue().first;
	}

	/*void put(K key, V value) {
		if (keyToNode.contains(key)) {
			keyToNode[key]->remove();
		}

		auto node = list.addFirst(std::make_pair(key, value));

		keyToNode[key] = node;

		if (list.size() > capacity) {
			auto deletedNode = list.removeLast();
			keyToNode.erase(deletedNode->getValue().first)
		}

		assert(list.size() <= capacity);
		assert(keyToNode.contains(key));
		assert(keyToNode[key]->getValue() == value);
		assert(keyToNode[key] == list.peekFirst());
	}*/

private:
	DoublyLinkedList<std::pair<K, V>> list;

	std::map<K, Node<std::pair<K, V>>*> keyToNode;

	size_t capacity;
};	