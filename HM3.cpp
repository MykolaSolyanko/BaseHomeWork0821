#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>

enum Tasks
{
	SUCCESS_EXIT,
	REVERS_STRING_TASK,
	SORT_ARRAY_TASK,
	REMOVE_ARRAY_ELEMENT_TASK,
	TO_UPPER,
	TO_LOWER,
	IS_DIGIT
}; 

// эта функци€ именно дл€ того, что бы изменить строку на обратную ей. ≈сли нужно просто вывести обратную строку, то 
// можно было бы просто завести цикл, который обходит массив строки в обратном пор€дке и выводит еЄ.
std::string revers(std::string& str) {
	for (size_t i = 0; i < str.size() / 2; i++) {
		std::swap(str[i], str[str.size() - i - 1]);
	}
	return str;
}

constexpr int array_size{ 4 };// нужна дл€ ициализации std::array.
std::array<int, array_size - 1> removeArrayElement(std::array<int, array_size> arr, int number) {
	int index{};
	int count{};
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == number) {
			index = i;
			break;
		}
		else {
			count++;
		}
	}
	std::array<int, array_size - 1> array{};
	for (int i = 0, j = 0; i < arr.size(); i++, j++) {
		if (i != index) {
			array[j] = arr[i];
		}
		else j--;
	}
	return array;
}

std::string to_upper(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
	}
	return str;
}

void is_digit(std::string str) {
	std::cout << "is digit ";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			std::cout << str[i] << " ";
		}
    }
	std::cout << std::endl;
}

std::string to_lower(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
	return str;
}


int main() {
	while (true)
	{
		std::cout << "Choose task: \n"                        <<
		             "1 - Revers String \n"                   <<
			         "2 - Inserting an item into an array \n" <<
			         "3 - Remove element from array \n"       <<
			         "4 - To upper \n"                        <<
			         "5 - To lower \n"                        <<
			         "6 - Is digit \n"                        <<
			         "0 - Close programm \n";

		int choice{};
		std::cin >> choice;
		switch (choice)
		{
		case REVERS_STRING_TASK:
		{
			std::cout << "Enter your string: ";
			std::string str{};
			std::cin >> str;
			std::cout << "Revers string is " << revers(str) << std::endl;
			break;
		}
		case SORT_ARRAY_TASK:
		{
			std::cout << "Enter length of massive: ";
			int arrLength{};
			std::cin >> arrLength;

			int* arr = new int[arrLength] {};

			int number{};
			std::cout << "Vvedite 1-e chislo: \n";
			std::cin >> number;
			arr[0] = number;

			int temp{};
			for (int i = 1; i < arrLength; i++) {
				std::cout << "Vvedite " << i + 1 << "-e chislo: \n";
				std::cin >> number;

				if (number > arr[i - 1]) {
					arr[i] = number;
				}
				else {
					temp = arr[i - 1];
					arr[i - 1] = number;
					arr[i] = temp;
				}
			}
			std::cout << "Massive is: \n";
			for (int i = 0; i < arrLength; i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
			delete[] arr;
			break;
		}
		case REMOVE_ARRAY_ELEMENT_TASK:
		{
			std::array<int, array_size> array;

			std::cout << "Enter values of array (4 elemenst) ";
			for (int i = 0; i < array.size(); i++) {
				std::cin >> array[i];
			}

			std::cout << "Enter the number to remove from array ";
			int number;
			std::cin >> number;

			std::array<int, array_size - 1> new_arr;
			new_arr = removeArrayElement(array, number);

			for (int i = 0; i < new_arr.size(); i++) {
				std::cout << new_arr[i] << " ";
			}
			break;
		} 
		case TO_UPPER:
		{
			std::cout << "Enter string: ";
			std::string str{};
			std::cin >> str;

			std::cout << "Upper string is: " << to_upper(str) << std::endl;
			break;
		}
		case TO_LOWER:
		{
			std::cout << "Enter string: ";
			std::string str{};
			std::cin >> str;

			std::cout << "Lower string is: " << to_lower(str) << std::endl;
			break;
		}
		case IS_DIGIT:
		{
			std::cout << "Enter string with numbers: ";

			std::string str{};
			std::cin >> str;
			
			is_digit(str);
			break;
		}
		default:
			return SUCCESS_EXIT;
		}
	}	

	return SUCCESS_EXIT;
}