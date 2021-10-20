#include <iostream>

const int koefMultiplyAC = 4;
const int koefA = 2;

template <class T> double descriminant(T a, T b, T c) {
	int descriminant{ (b * b) - (koefMultiplyAC * a * c) };
	return descriminant;
}

int main() {

	constexpr int kErrorExit{ -1 };
	constexpr int kSuccessExit{ 0 };
	constexpr int klowARange{ 2 };
	constexpr int kHighARange{ 255 };

	constexpr int klowBRange{ 2 };
	constexpr int kHighBRange{ 255 };

	constexpr int klowCRange{ 2 };
	constexpr int kHighCRange{ 255 };

	int a{};

	std::cout << "Please enter coef a [" << klowARange << ".." << kHighARange
		<< "]\n";
	std::cin >> a;
	if (a < klowARange || a > kHighARange) {
		std::cout << "Incorrect input coef a\n ";
		return kErrorExit;
	}

	int b{};
	std::cout << "Please enter coef b [" << klowBRange << ".." << kHighBRange
		<< "]\n";
	std::cin >> b;
	if (b < klowBRange || b > kHighBRange) {
		std::cout << "Incorrect input coef b\n ";
		return kErrorExit;
	}
	int c{};
	std::cout << "Please enter coef c [" << klowCRange << ".." << kHighCRange
		<< "]\n";
	std::cin >> c;
	if (c < klowCRange || c > kHighCRange) {
		std::cout << "Incorrect input coef c\n ";
		return kErrorExit;
	}

	auto descr{ descriminant(a, b, c) };

	int x1 = 0;
	int x2 = 0;
	int znamen = koefA * a;
	if ((int)descr >= 0 && znamen != 0) {
		x1 = b + std::sqrt(descr) / znamen;
		x2 = b - std::sqrt(descr) / znamen;
	}
	else if (znamen == 0) {
		std::cout << "Error deviding by 0" << std::endl;
	}
	else if ((int)descr == 0) {
		x1 = x2 = -b / 2 * a;
	}
	else {
		std::cout << "There is no x" << std::endl;
	}

	return kSuccessExit;
}
