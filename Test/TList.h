#pragma once
#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;
class TList
{
	//template <typename T>
	class TNode {
	public:
		TNode* pNext;
		TNode* pPrev;
		Pair data1;
	public:
		TNode() : data1("", 0) {
			pNext = nullptr;
			pPrev = nullptr;

		}
		TNode(const Pair& data_, TNode* pNext_ = nullptr, TNode* pPrev_ = nullptr) :data1(data_) {
			pNext = pNext_;
			pPrev = pPrev_;
		}
		TNode(const TNode& tmp) : data1(tmp.data1) {
			//data1 = tmp.data1;
			pNext = tmp.pNext;
			pPrev = tmp.pPrev;
		}

		friend class TList;
	};
private:
	TNode* pFirst;
	TNode* pLast;
	size_t count;
	int efficiency;
public:
	TList() {
		count = 0;
		pFirst = nullptr;
		pLast = nullptr;
	}
	TList(const TList& tmp) {
	}
	~TList() {
		TNode* current = pFirst;
		while (current != nullptr) {
			TNode* next = current->pNext;
			delete current;
			current = next;
		}
		pFirst = nullptr;
		pLast = nullptr;
	}
	void push_back(const std::string& key) {
		int data = 1;
		int vr = 1;
		TNode* cur = pFirst;

		if ((pLast == nullptr) && (pFirst == nullptr)) {
			pLast = new TNode(Pair(key, data));
			pFirst = pLast;
			count++;
		}
		else {
			while (cur != nullptr) {
				if (cur->data1.first == key) {
					cur->data1.second++;
					vr = 0;
					return;
				}
				else {
					cur = cur->pNext;
				}
			}
			if (vr == 1) {
				pLast->pNext = new TNode(Pair(key, data));
				pLast->pNext->pPrev = pLast;
				pLast = pLast->pNext;
				count++;
			}
		}
	}
	TNode* find_node(const std::string& tmp) {
		TNode* cur = pFirst;
		if ((cur == nullptr)) {
			return nullptr;
		}
		else if ((pLast->data1.first == tmp)) {
			return pLast;
		}
		else {
			while (cur != nullptr) {
				if (cur->data1.first == tmp) {
					return cur;
				}
				else {
					cur = cur->pNext;
				}
			}
			return nullptr;
		}
	}
	int efect(const std::string& tmp) {
		int effect = 0;
		TNode* cur = pFirst;
		if ((cur == nullptr)) {
			std::cout << effect;
		}
		else if ((pLast->data1.first == tmp)) {
			effect++;
			std::cout << effect;
			//break;
		}
		else {
			while (cur != nullptr) {
				effect++;
				if (cur->data1.first == tmp) {
					return effect;
				}
				else {
					cur = cur->pNext;
					//	effect++;
				}
			}
			return effect;
		}
		//return;
	}
	bool isEmptry() //? 
	{
		if ((pFirst == nullptr)) {
			return 1;
		}
		else return 0;
	}
	bool isFull() {
		TNode* tmp;
		tmp = new TNode();
		if (tmp == nullptr) {
			return 1;
		}
		else return 0;
	}

	void delete_node(const std::string& key) {
		TNode* cur = find_node(key);
		if (cur != nullptr) {
			if (cur == pFirst) {
				pFirst = pFirst->pNext;
				delete pFirst->pPrev;
				pFirst->pPrev = nullptr;
			}
			else if (cur == pLast) {
				pLast = pLast->pPrev;
				delete pLast->pNext;
				pLast->pNext = nullptr;
			}
			else {
				cur->pPrev->pNext = cur->pNext;
				cur->pNext->pPrev = cur->pPrev;
				delete cur;
				cur = nullptr;
			}
		}
		else {
			cout << "Нечего удалять" << endl;
		}
		return;
	}
	void print() {
		TNode* cur = pFirst;
		if (cur == nullptr) {
			std::cout << "Элементов нет";
			std::cout << "\n";
		}
		else {
			while (cur != nullptr) {
				std::string key = cur->data1.first;
				int data = cur->data1.second;
				std::cout << key << "   " << data;
				std::cout << "\n";
				cur = cur->pNext;
			}
		}
	}
};

#pragma once
