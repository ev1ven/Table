#pragma once
#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;
class Vector
{
protected:
	size_t size;
	Pair* memory;
	int count;
public:
	Vector(size_t n = 1) :size(n) {
		//Pair A;
		memory = new Pair[size];
	}
	Vector(size_t size, Pair* memory1, int count)
	{
		if (size != 0 && memory != nullptr)
		{
			this->size = size;
			this->count = count;
			this->memory = new Pair[size];
			for (int i = 0; i < count; i++) {
				memory[i] = memory1[i];
			}

		}

		else if (size == 0) cout << "Размер массива равен 0" << endl;
		else cout << "Указатель - nullptr" << endl;
	}
	~Vector()
	{
		delete[] memory;
		count = 0;
	}
	Vector(const Vector& other)
	{
		if (other.size > 0 && other.memory != nullptr)
		{
			size = other.size;
			count = other.count;
			memory = new Pair[size];
			for (int i = 0; i < count; i++) {
				memory[i] = other.memory[i];
			}
		}

		else if (size <= 0) cout << "Размер массива равен 0" << endl;
		else cout << "Указатель - nullptr" << endl;
	}

	void Add_Element(const std::string& key) {
		int tmp = 0;
		if (memory == nullptr) {
			cout << "Нет памяти" << endl;
		}
		else if (count == size) cout << "Нет места в таблице" << endl;
		else if (count == 0) {
			memory[count].first = key;
			memory[count].second = 1;
			count++;
		}
		else {
			while (tmp != count) {

				if (memory[tmp].first == key) {
					memory[tmp].second++;
					return;
				}
				else tmp++;
			}
			memory[count].first = key;
			memory[count].second = 1;
			count++;
		}
	}
	int Find_Element(const std::string& key) {
		int tmp = 0;
		if (memory == nullptr) {
		}
		else if (count == 0) { return 0; }
		else {
			while (tmp != count - 1) {
				if (memory[tmp].first == key) {
					return 1;
				}
				else {
					tmp++;
				}
			}
		}
		return 0;
	}
	int efect(const std::string& key) {
		int tmp = 0;
		int effect = 0;
		if (memory == nullptr) {
			return effect;
		}
		else if (count == 0) { return effect; }
		else {
			effect++;
			while (tmp != count - 1) {
				effect++;
				if (memory[tmp].first == key) {
					effect--;
					break;
				}
				else {
					tmp++;
				}
			}
			return effect;
		}
		return effect;
	}
	void Delete_Element(const std::string key) {
		int tmp = 0;
		if (memory == nullptr) {
			cout << "Нечего удалять" << endl;
		}
		else if (count == 0) cout << "Нечего удалять" << endl;
		else {
			while (tmp != count) {
				if (memory[tmp].first == key) {
					memory[tmp].first = memory[count - 1].first;
					memory[tmp].second = memory[count - 1].second;
					count--;
					return;
				}
				else {
					tmp++;
				}
			}
			cout << "Элемент не найден" << endl;
		}
	}
	void Print_Arr() {
		int tmp = 0;
		if (memory == nullptr) {
			cout << "Элементов нет" << endl;
		}
		else if (count == 0) cout << "Элементов нет" << endl;
		else {
			while (tmp != count) {
				cout << memory[tmp].first << "   " << memory[tmp].second << endl;
				tmp++;
			}

		}
	}

	/*void quick_sort(Pair* memory, size_t size) {
		int i = 0;
		int j = size - 1;
		int mid = size / 2;
		do {
			while (memory[i].first.compare(memory[mid].first) < 0) {
				i++;
			}
			while (memory[j].first.compare(memory[mid].first) > 0) {
				j--;
			}
			if (i <= j) {
				Pair tmp = memory[i];
				memory[i] = memory[j];
				memory[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);
	}*/
	friend class Vector_sort;

};

