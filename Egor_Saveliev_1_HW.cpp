#include <cmath>
#include <iostream>

int main() {

  bool RunProgramm{true};

  // Infinitive cycle.
  // At the end of the cycle user can choose to calculate another equation or to exit.
  while (RunProgramm) {

    std::cout << "\n-- Solving a quadratic equation ax^2 + bx + c = 0 --\n"
              << std::endl;

    int a{};

    // Get [a] koef from user. Check [a] koef to be in range.
    // If it's out of range circle repeat.
    do {

      std::cout << "Enter number [a] in range (-255...1; 1...255): ";

      std::cin >> a;

      if ((a < -255) || (a == 0) || (a > 255)) {
        std::cout << "Incorrect number. Enter number again\n" << std::endl;
      }

    } while ((a < -255) || (a == 0) || (a > 255));

    int b{};

    // Get [b] koef from user. Check [b] koef to be in range.
    // If it's out of range circle repeat.
    do {

      std::cout << "Enter number [b] in range (-255...255): ";

      std::cin >> b;

      if ((b < -255) || (b > 255)) {
        std::cout << "Incorrect number. Enter number again\n" << std::endl;
      }

    } while ((b < -255) || (b > 255));

    int c{};

    // Get [c] koef from user. Check [c] koef to be in range.
    // If it's out of range circle repeat.
    do {

      std::cout << "Enter number [c] in range (-255...255): ";

      std::cin >> c;

      if ((c < -255) || (c > 255)) {
        std::cout << "Incorrect number. Enter number again\n" << std::endl;
      }

    } while ((c < -255) || (c > 255));

    constexpr int kDiscCoef{4};

    // Calculate discriminant.
    long long D = (b * b) - (kDiscCoef * a * c);

    constexpr int kRootCalcCoef{2};

    // Calculate roots of function.
    if (D > 0) {
      auto x1{(-b + std::sqrt(D)) / (static_cast<double>(kRootCalcCoef) * a)};
      auto x2{(-b - std::sqrt(D)) / (static_cast<double>(kRootCalcCoef) * a)};

      std::cout << "\nDiscriminant = " << D << std::endl;
      std::cout << "x1 = " << x1 << std::endl;
      std::cout << "x2 = " << x2 << std::endl;
    } else if (D == 0) {
      auto x{-b / (static_cast<double>(kRootCalcCoef) * a)};

      std::cout << "\nDiscriminant = " << D << std::endl;
      std::cout << "x = " << x << std::endl;
    } else {
      std::cout << "\nDiscriminant = " << D << std::endl;
      std::cout << "D is less than 0. Function has no real roots" << std::endl;
    }

    std::cout << "\nWant to solve another quadratic equation?" << std::endl;

    long long int CheckNumber{};

    // Check if user enter correct input. Is must be 1 or 0.
    // If it's another number circle repeat.
    do {

      std::cout << "1 - Continue; 0 - Exit" << std::endl;
      std::cout << "Choose option: ";

      std::cin >> CheckNumber;

      if (!(CheckNumber == 1) && !(CheckNumber == 0)) {
        std::cout << "Incorrect option. Choose option again\n" << std::endl;
      }

    } while (!(CheckNumber == 1) && !(CheckNumber == 0));

    // Check user choice. If it's 0 circle stops. If it's 1 circle repeat.
    if (CheckNumber == 0) {
      RunProgramm = false;
    }
  }

  return 0;
};
