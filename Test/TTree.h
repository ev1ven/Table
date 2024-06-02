#pragma once
#include <iostream>
#include "Pair.h"
#include <stack>
using namespace std;
class TTree
{
	class TNode_Tree {
	protected:
		Pair data;
		TNode_Tree* left;
		TNode_Tree* right;
		TNode_Tree* prev;
	public:
		TNode_Tree() : data("", 0) {
			left = nullptr;
			right = nullptr;
			prev = nullptr;
		}
		TNode_Tree(Pair data_, TNode_Tree* left_, TNode_Tree* right_) {
			data.first = data_.first;
			data.second = data.second;
			left = left_;
			right = right_;
		}
		TNode_Tree(const TNode_Tree& first) {
			data.first = first.data.first;
			data.second = first.data.second;
			left = first.left;
			right = first.right;
			prev = first.prev;
		}
		friend class TTree;
	};
	TNode_Tree* pFirst;
	size_t count;
public:
	TTree() {
		count = 0;
		pFirst = nullptr;
	}
	void push_back_tree(const std::string& tmp) {
		TNode_Tree* cur = pFirst;
		int data = 1;
		int vr = 1;
		if (pFirst == nullptr) {
			pFirst = new TNode_Tree();
			pFirst->data.first = tmp;
			pFirst->data.second = data;
			count++;
		}
		else {
			while (vr != 0) {
				if (cur->data.first.compare(tmp) < 0) {
					if (cur->right != nullptr) {
						cur = cur->right;
					}
					else {
						cur->right = new TNode_Tree();
						cur->right->data.first = tmp;
						cur->right->data.second = data;
						cur->right->prev = cur;
						cur = cur->right;
						count++;
						vr = 0;
					}
				}
				else if (cur->data.first.compare(tmp) == 0) {
					cur->data.second++;
					vr = 0;
				}
				else {
					if (cur->left != nullptr) {
						cur = cur->left;
					}
					else {
						cur->left = new TNode_Tree();
						cur->left->data.first = tmp;
						cur->left->data.second = data;
						cur->left->prev = cur;
						cur = cur->left;
						count++;
						vr = 0;
					}
				}
			}
		}
	}
	TNode_Tree* find_node_tree(const std::string& tmp) {
		TNode_Tree* cur = pFirst;
		if (pFirst == nullptr) {
			return nullptr;
		}
		else {
			while (cur != nullptr) {
				if (cur->data.first.compare(tmp) == 0) {
					return cur;
				}
				else if (cur->data.first.compare(tmp) < 0) {
					if (cur->right != nullptr) {
						cur = cur->right;
					}
					else return nullptr;
				}
				else if (cur->data.first.compare(tmp) > 0) {
					if (cur->left != nullptr) {
						cur = cur->left;
					}
					else return nullptr;
				}
			}
		}
	}
	int effect(const std::string& tmp) {
		TNode_Tree* cur = pFirst;
		int effect = 0;
		if (pFirst == nullptr) {
			return effect;
		}
		else {
			while (cur != nullptr) {
				effect++;
				if (cur->data.first.compare(tmp) == 0) {
					return effect;
				}
				else if (cur->data.first.compare(tmp) < 0) {
					if (cur->right != nullptr) {
						cur = cur->right;
					}
					else return effect;
				}
				else if (cur->data.first.compare(tmp) > 0) {
					if (cur->left != nullptr) {
						cur = cur->left;
					}
					else return effect;
				}
			}
		}
	}
	TNode_Tree* find_leaf_right(const std::string& tmp) {
		TNode_Tree* cur;
		cur = find_node_tree(tmp);
		if (cur->left != nullptr) {
			cur = cur->left;
			if (cur->right == nullptr)
				return cur;
			while (cur->right != nullptr) {
				cur = cur->right;
			}
			return cur;
		}
		return nullptr;
	}
	TNode_Tree* find_leaf_left(const std::string& tmp) {
		TNode_Tree* cur = find_node_tree(tmp);
		if (cur->right != nullptr) {
			cur = cur->right;
			if (cur->left == nullptr)
				return cur;
			while (cur->left != nullptr) {
				cur = cur->left;
			}
			return cur;
		}
		return nullptr;
	}

	void delete_node_tree(const std::string& tmp) {
		TNode_Tree* cur;

		TNode_Tree* vr_left;
		TNode_Tree* vr_right;
		cur = find_node_tree(tmp);
		if (cur == nullptr) {
			cout << "нечего удалять" << endl;
			return;
		}
		vr_left = find_leaf_left(tmp);
		vr_right = find_leaf_right(tmp);
		if (cur == nullptr) {
			std::cout << "нечего удалять";

		}
		else if (cur == pFirst) {
			if (cur->left == nullptr && cur->right == nullptr) {
				cur = nullptr;
				delete cur;
			}
			else if (cur->left != nullptr && cur->right == nullptr) {
				pFirst = cur->left;
				cur = nullptr;
				delete cur;
			}
			else if (cur->left == nullptr && cur->right != nullptr) {
				pFirst = cur->right;
				cur = nullptr;
				delete cur;
			}
			else if (cur->left != nullptr && cur->right != nullptr) {
				if (vr_right->left == nullptr) {
					cur->data.first = vr_right->data.first;
					cur->data.second = vr_right->data.second;
					if (vr_right == cur->left) {
						vr_right->prev->left = nullptr;
					}
					else {
						vr_right->prev->right = nullptr;
					}
					delete vr_right;
					vr_right = nullptr;
				}
				else {
					cur->data.first = vr_right->data.first;
					cur->data.second = vr_right->data.second;
					vr_right->prev->right = vr_right->left;
					delete vr_right;
					vr_right = nullptr;
				}
			}
		}
		else if (cur != nullptr) {
			if ((cur->left == nullptr) && (cur->right == nullptr)) {
				if (cur->prev->left == cur) {
					cur->prev->left = nullptr;
					delete cur;
				}
				else {
					cur->prev->right = nullptr;
					delete cur;
				}
			}
			else if (cur == cur->prev->left) {
				if ((cur->left != nullptr) && (cur->right == nullptr)) {
					cur->prev->left = cur->left;
					delete cur;
				}
				else if ((cur->left == nullptr) && (cur->right != nullptr)) {
					cur->prev->left = cur->right;
					delete cur;
				}
				else if ((cur->left != nullptr) && (cur->right != nullptr)) {
					if (vr_right->left == nullptr) {
						cur->data.first = vr_right->data.first;
						cur->data.second = vr_right->data.second;
						if (vr_right == cur->left) {
							vr_right->prev->left = nullptr;
						}
						else {
							vr_right->prev->right = nullptr;
						}
						delete vr_right;
						vr_right = nullptr;
					}
					else {
						cur->data.first = vr_right->data.first;
						cur->data.second = vr_right->data.second;
						vr_right->prev->right = vr_right->left;
						delete vr_right;
						vr_right = nullptr;
					}
				}
			}
			else if (cur == cur->prev->right) {
				if ((cur->left != nullptr) && (cur->right == nullptr)) {
					cur->prev->right = cur->left;
					delete cur;
				}
				else if ((cur->left == nullptr) && (cur->right != nullptr)) {
					cur->prev->right = cur->right;
					delete cur;
				}
				else if ((cur->left != nullptr) && (cur->right != nullptr)) {
					if (vr_left->right == nullptr) {
						cur->data.first = vr_left->data.first;
						cur->data.second = vr_left->data.second;
						if (vr_left == cur->right) {
							vr_left->prev->right = nullptr;
						}
						else {
							vr_left->prev->left = nullptr;
						}

						delete vr_left;
						vr_left = nullptr;
					}
					else {
						cur->data.first = vr_left->data.first;
						cur->data.second = vr_left->data.second;
						vr_left->prev->left = vr_left->right;
						delete vr_left;
						vr_left = nullptr;
					}
				}
			}

		}
	}
	bool is_Empty() {
		if (pFirst == nullptr) {
			return 1;
		}
		else return 0;
	}
	void print(const TNode_Tree* cur = nullptr) {
		if (cur == nullptr) {
			cur = pFirst;
		}
		if (cur->left != nullptr) {
			print(cur->left);
		}
		if (cur->right != nullptr) {
			print(cur->right);
		}
		cout << cur->data.first << "   " << cur->data.second << endl;
	}
};

