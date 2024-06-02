#pragma once
#include <string>
//#include "TList.h"
//template <typename T1, typename T2>
class Pair
{
public:
	std::string first;
	int second;
public:
	Pair() {
		first = "";
		second = NULL;
	}
	Pair(std::string first_, int second_) : first(first_), second(second_) {
	}
	Pair(const Pair& tmp) {
		first = tmp.first;
		second = tmp.second;
	}
	std::string get_first() {
		return first;
	}
	int get_second() {
		return second;
	}
	void set_first(std::string first_) {
		first = first_;
	}
	void set_second(int second_) {
		second = second_;
	}
	friend class TList;
	friend class Vector;
	friend class Vector_cort;
	friend class TTree;
	friend class Hash_Table;
};

