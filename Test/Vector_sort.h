#pragma once
#include "Pair.h"
#include "Vector.h"
#include <string>
#include <iostream>
class Vector_sort
{
protected:
	size_t size;
	Pair* memory;
	int count;
public:
	Vector_sort(size_t n = 1) :size(n) {
		Pair A;
		memory = new Pair[size];
	}
	Vector_sort(size_t size, Pair* memory1, int count)
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
	~Vector_sort()
	{
		delete[] memory;
		count = 0;
	}
	Vector_sort(const Vector& other)
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


	void quick_sort(int left, int right) {
		if (left >= right) {
			return;
		}

		int i = left, j = right;
		Pair pivot = this->memory[(left + right) / 2];

		while (i <= j) {
			while (this->memory[i].first.compare(pivot.first) < 0) {
				i++;
			}
			while (this->memory[j].first.compare(pivot.first) > 0) {
				j--;
			}
			if (i <= j) {
				Pair temp = this->memory[i];
				this->memory[i] = this->memory[j];
				this->memory[j] = temp;
				i++;
				j--;
			}
		}
		if (left < j) {
			quick_sort(left, j);
		}
		if (i < right) {
			quick_sort(i, right);
		}
	}
	void quick_sort() {
		quick_sort(0, this->count - 1);
	}

	int Find_Element(const std::string& key) {
		int size = this->count;
		Pair* memory = this->memory;
		int left = 0;
		int right = size - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (memory[mid].first == key) {
				return 1;
			}
			else if (memory[mid].first < key) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return 0;
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
					quick_sort();
					return;
				}
				else tmp++;
			}
			memory[count].first = key;
			memory[count].second = 1;
			count++;
		}
		quick_sort();
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
					quick_sort();
					return;
				}
				else {
					tmp++;
				}
			}
			cout << "Элемент не найден" << endl;
		}
		quick_sort();
	}
	int efect(const std::string& key) {
		int size = this->count;
		Pair* memory = this->memory;
		int effect = 0;
		int left = 0;
		int right = size - 1;

		while (left <= right) {
			effect++;
			int mid = left + (right - left) / 2;

			if (memory[mid].first == key) {
				return effect;
			}
			else if (memory[mid].first < key) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return effect;
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

};


