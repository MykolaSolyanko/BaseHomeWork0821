#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

// counts the sum of the digits of a number
int getDigitsSum(int _number) {
	int sum{};
	int constexpr cDecimalDevisor{ 10 };
	while (_number != 0) {
		sum += _number % cDecimalDevisor;
		_number /= cDecimalDevisor;
	}
	std::cout << "Digitals sum is ";
	return sum;
}

bool luckyTicket(int _number) {
	int constexpr cSixDigit{ 6 };
	int constexpr halfOfNumber{ 3 };
	int sumFirst3digit{};
	int sumLast3digit{};
	int digit{};
	for (size_t i = 0; i < cSixDigit; i++)
	{
		digit = _number % 10;
		_number = _number / 10;
		if (i < halfOfNumber) {
			sumFirst3digit += digit;
		}
		else {
			sumLast3digit += digit;
		}
	}
	if (sumFirst3digit == sumLast3digit) {
		return true;
	}
	return false;
}

int SumOfOddElements(std::vector<int> v) {
	int sum{};
	for (size_t i = 0; i < v.size(); i++){
		if (v[i] % 2 != 0){
			sum += v[i];
		}
	}
	return sum;
}

int bestDivisor(int _number) {
	int constexpr cDecimalDevisor{ 10 };
	std::vector<int> divisors{ 1, _number};
	for (size_t i = _number / 2; i > 1; --i){
		if (_number % i == 0) {
			divisors.push_back(i);
		}
	}
	std::vector<int> new_divisors(divisors);

	std::vector<int> sumDigitDivisorsElement(divisors.size());
	for (size_t i = 0; i < divisors.size(); i++){
		while (divisors[i] != 0) {
			sumDigitDivisorsElement[i] += divisors[i] % cDecimalDevisor;
			divisors[i] /= cDecimalDevisor;
		}
	}

	const int res{*std::max_element(sumDigitDivisorsElement.begin(), sumDigitDivisorsElement.end())};
	size_t bestDivisorPosition{};
	for (int i = 0; i < sumDigitDivisorsElement.size(); i++){
		if (sumDigitDivisorsElement[i] == res) {
			bestDivisorPosition = i;
		}
	}

	return new_divisors[bestDivisorPosition];
}

int reversNumber(int _number) {
	int constexpr cDecimalDevisor{ 10 };
	int constexpr cDecimalFactor{ 10 };
	int newNumber{ _number };
	if (newNumber < 0) newNumber *= -1;
	int reversNumber{};
	while (newNumber > 0) {
		reversNumber = reversNumber * cDecimalFactor + newNumber % cDecimalDevisor;
		newNumber /= cDecimalDevisor;
	}
	if (_number >= 0) {
		return reversNumber;
	}
	else {
		return -reversNumber;
	}
}


int main()
{
	constexpr int cSuccessExit{ 0 };
	int choice{};
	while (true)
	{
		std::cout << "Choose needed task : \n" <<
			"1 - Digit Sum \n" <<
			"2 - Lucky ticket \n" <<
			"3 - Sum of odd elements\n" <<
			"4 - Best divisor \n" <<
			"5 - Revers number \n" <<
			"0 - Close the programm \n";

		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::cout << "Digit Sum task! \n";
			std::cout << "Enter an integer number: ";
			int number{};
			std::cin >> number;
			std::cout << "Sum of digits is " << getDigitsSum(number) << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "Lucky ticket task! \n";
			std::cout << "Enter à six-digit integer number: ";
			int number{};
			std::cin >> number;
			//checking if number is six-digit
			if (number < 99999 || number > 999999) {
				std::cout << "Incorrect input! \n";
				break;
			}
			if (luckyTicket(number)) {
				std::cout << "The ticket is lucky! \n";
			}
			else {
				std::cout << "The ticket is unlucky! \n";
			}
			break;
		}
		case 3:
		{
			std::cout << "Sum of odd elements task! \n";
			std::cout << "Enter elements. Enter '0' or incorrect number for stop \n";
			int number{ 1 };
			std::vector<int> arrayOfelements;
			while (number != 0 || arrayOfelements.size() > 50) {
				std::cin >> number;
				if (number < -60 || number > 90 || number == 0) {
					break;
				}
				arrayOfelements.push_back(number);
			}
			if (arrayOfelements.empty()) {
				std::cout << "Incorrect input! \n";
				break;
			}
			std::cout << "Sum of odd elements is " << SumOfOddElements(arrayOfelements) << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "Best divisor task! \n";
			std::cout << "Enter an integer number: ";
			int number{};
			std::cin >> number;
			std::cout << "Best divisor is: " << bestDivisor(number) << std::endl;
			break;
		}
		case 5:
		{
			std::cout << "Revers number task \n";
			std::cout << "Enter an integer number: ";
			int number{};
			std::cin >> number;
			std::cout << "Revers number is: " << reversNumber(number) << std::endl;
			break;
		}
		case 0:
			return cSuccessExit;
		}

	}
}