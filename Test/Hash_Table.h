#pragma once
#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;
class Hash_Table
{
protected:
	int size;
	Pair* arr;
	int count = 0;
public:
	Hash_Table(int n = 1) : size(n) {
		Pair d(" ", 0);
		arr = new Pair[size];
	}
	Hash_Table(int n, int count1, Pair* arr1) {
		if (n > 0 && arr1 != nullptr) {
			size = n;
			count = count1;
			arr = new Pair[size];
			for (int i = 0; i < size; i++) {
				arr[i] = arr1[i];
			}
		}
	}
	Hash_Table(const Hash_Table& tmp) {
		if (tmp.size > 0 && tmp.arr != nullptr) {
			size = tmp.size;
			count = tmp.count;
			arr = new Pair[size];
			for (int i = 0; i < size; i++) {
				arr[i] = tmp.arr[i];
			}
		}
	}
	int size_max() {
		int tmp = count * 100 / size;
		if ((100 - tmp) < 20) {
			return 1;
		}
		else return 0;
	}
	int hash(const std::string& key) {
		int sum = 0;
		for (int i = 0; i < key.length(); i++) {
			sum += key[i] * (i + 1);
		}
		return sum % size;
	}
	void add(const std::string& key, const int& data = 1) {
		int hash1 = hash(key);
		//int data = 1;
		int step = 1;
		int hash2;
		int tmp = size_max();
		if (tmp == 1) {
			count = 0;
			Pair* old_arr = arr;
			size = size * 2;
			arr = new Pair[size];
			for (int i = 0; i < size / 2; i++) {
				if (old_arr[i].first != "") {
					string vr1 = old_arr[i].first;
					int data = old_arr[i].second;
					add(vr1, data);

				}
			}
			add(key);
		}
		else {
			if (arr[hash1].first != "" && arr[hash1].first != "*") {
				if (arr[hash1].first == key) {
					arr[hash1].second += 1;
				}
				else {
					hash2 = (hash1 + step) % size;
					if ((arr[hash2].first != "" && arr[hash2].first != "*")) {
						arr[hash2].first = key;
						arr[hash2].second = data;
						count++;
						return;
					}
					while (arr[hash2].first != "" && arr[hash2].first != "*") {
						hash2 = (hash2 + step) % size;
					}
					arr[hash2].first = key;
					arr[hash2].second = data;
					count++;
				}
			}
			else if (arr[hash1].first == "" || arr[hash1].first == "*") {
				arr[hash1].first = key;
				arr[hash1].second = data;
				count++;
			}
		}
	}
	int index(const std::string& key) {
		int hash1 = hash(key);
		int hash2;
		int step = 1;
		if (count != 0) {
			if (arr[hash1].first != key) {
				hash2 = (hash1 + step) % size;
				if (arr[hash2].first != key || arr[hash2].first != "") {
					while (arr[hash2].first != key && arr[hash2].first != "" && arr[hash2].first != "*") {
						hash2 = (hash2 + step) % size;
					}
					return hash2;
				}
			}
			else {
				return hash1;
			}
		}
	}
	void print() {
		for (int i = 0; i < size; i++) {
			if (arr[i].first != "" && arr[i].first != "*") {
				cout << i << "   " << arr[i].first << "   " << arr[i].second << "   " << hash(arr[i].first) << endl;
			}
		}
	}
	int find(const std::string& key) {
		int hash1 = hash(key);
		int hash2;
		int step = 1;
		if (count != 0) {
			if (arr[hash1].first != key) {
				hash2 = (hash1 + step) % size;
				if (arr[hash2].first != key || arr[hash2].first != "") {
					while (arr[hash2].first != key && arr[hash2].first != "" && arr[hash2].first != "*") {
						hash2 = (hash2 + step) % size;
					}
				}
				if (arr[hash2].first == key) {
					return hash2;
				}
				else return -1;
			}
			else return hash1;
		}
	}
	int effect(const std::string& key) {
		int hash1 = hash(key);
		int hash2;
		int step = 1;
		int effect = 0;
		if (count != 0) {
			if (arr[hash1].first != key) {
				effect++;
				if (arr[hash1].first == "") {
					return effect;
				}
				hash2 = (hash1 + step) % size;
				if (arr[hash2].first != key || arr[hash2].first != "") {
					effect++;
					while (arr[hash2].first != key && arr[hash2].first != "" && arr[hash2].first != "*") {
						hash2 = (hash2 + step) % size;
						effect++;
					}
				}
				if (arr[hash2].first == key) {
					//effect++;
					return effect;
				}
				else return effect++;
			}
			else {
				effect++;
				return effect;
			}
		}
	}
	void delete_pair(const std::string& key) {
		int hash1 = find(key);
		if (hash1 != -1) {
			arr[hash1].first = "*";
			count--;
		}
		else cout << "Нечего удалять" << endl;
		//	print();
	}

};

