#include <iostream>
#include <cmath>

bool checkRange(int _coef, int _lowRange, int _highRange) {
	if (_coef < _lowRange || _coef > _highRange) {
		std::cout << "You have entered incorrect number";
		return false;
	}
	return true;
}

int main()
{

	constexpr int programmError{ -1 };

	std::cout << "Please enter firts number: ";

	constexpr int  kLowCoefRange{ 2 };
	constexpr int  kHighCoefRange{ 255 };

	int a{};
	std::cin >> a;
	if (checkRange(a, kLowCoefRange, kHighCoefRange) == false){
		return programmError;
	}

	std::cout << "Enter the second number: ";
	int b{};
	std::cin >> b;
	if (checkRange(b, kLowCoefRange, kHighCoefRange) == false){
		return programmError;
	}

	std::cout << "Enter third number: ";
	int c{};
	std::cin >> c;
	if (checkRange(c, kLowCoefRange, kHighCoefRange) == false) {
		return programmError;
	}

	long long D{};
	constexpr int discriminantConst{ 4 };
	D = b * b - static_cast <long long> (discriminantConst) * a * c;
	
	double x1, x2;
	constexpr int numerator{ 2 };
	constexpr int denominator{ 4 };
	if (D > 0) {
		x1 = (-b + sqrt(D)) / (static_cast<double>(numerator) * a);
		x2 = (-b - sqrt(D)) / (static_cast<double>(numerator)* a);
		std::cout << "Answers: x1 = " << x1 << " x2 = " << x2;
	}

	else if (D == 0) {
		x1 = (-b) / (numerator * a);
		std::cout << "Answer: x = " << x1;
	}
	else {
		std::cout << "There is no answers\n";
	}

	return 0;
}