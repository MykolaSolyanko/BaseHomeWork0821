

#include <cmath>
#include <iostream>

int main() {

  constexpr int errorExitCode{-1};
  constexpr int successExitCode{0};

  int lowRangeA{2};
  int highRangeA{255};
  int a{};

  constexpr auto incorrectInputErrorText{
      "You entered an incorrect number, try entering the number again"};

  std::cout << "Please enter number in range [" << lowRangeA << ".."
            << highRangeA << "] for a\n";
  std::cin >> a;

  if (a < lowRangeA or a > highRangeA) {
    std::cout << incorrectInputErrorText;
    return errorExitCode;
  }

  int lowRangeB{2};
  int highRangeB{255};
  int b{};

  std::cout << "Please enter number in range [" << lowRangeB << ".."
            << highRangeB << "] for b\n";
  std::cin >> b;

  if (b < lowRangeB or b > highRangeB) {
    std::cout << incorrectInputErrorText;
    return errorExitCode;
  }

  int lowRangeC{2};
  int highRangeC{255};
  int c{};

  std::cout << "Please enter number in range [" << lowRangeB << ".."
            << highRangeB << "] for c\n";
  std::cin >> c;

  if (c < lowRangeC or c > highRangeC) {
    std::cout << incorrectInputErrorText;
    return errorExitCode;
  }

  long long D{static_cast<long long>(b * b) -
              (static_cast<long long>(4) * a * c)};

  constexpr auto noRootErrorText{"The equation has no real roots.\n"};

  if (D < 0) {
    std::cout << noRootErrorText;
    return errorExitCode;
  }

  auto divider{2 * a};

  if (divider == 0) {
    std::cout << noRootErrorText;
    return errorExitCode;
  }

  double x1{(-b + std::sqrt(D)) / divider};
  double x2{(-b - std::sqrt(D)) / divider};

  std::cout << "x1=" << x1 << " "
            << "x2 =" << x2;

  return successExitCode;
}
