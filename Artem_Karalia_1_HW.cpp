#include <cmath>
#include <iostream>

int main() {
  constexpr int kLowARange{-99};
  constexpr int kHighARange{99};

  constexpr int kLowBRange{-99};
  constexpr int kHighBRange{99};

  constexpr int kLowCRange{-99};
  constexpr int kHighCRange{99};

  int a{};

  while (true) {
    std::cout << "Please enter coef a [" << kLowARange << ".." << kHighARange
              << "]\n";
    std::cin >> a;

    if (a >= kLowARange and a <= kHighARange) {
      std::cout << "a = " << a << std::endl;
      break;
    }
    std::cout << "Invalid data, please enter coef a again\n";
  }

  int b{};

  while (true) {
    std::cout << "Please enter coef b [" << kLowBRange << ".." << kHighBRange
              << "]\n";
    std::cin >> b;

    if (b >= kLowBRange and b <= kHighBRange) {
      std::cout << "b = " << b << std::endl;
      break;
    }
    std::cout << "Invalid data, please enter coef b again\n";
  }

  int c{};

  while (true) {
    std::cout << "Please enter coef c [" << kLowCRange << ".." << kHighCRange
              << "]\n";
    std::cin >> c;

    if (c >= kLowCRange and c <= kHighCRange) {
      std::cout << "c = " << c << std::endl;
      break;
    }
    std::cout << "Invalid data, please enter coef c again\n";
  }

  // long long D{};
  constexpr int kDConst{4};
  constexpr int kXConst{2};

  long long D{(b * b) - (kDConst * a * c)};
  std::cout << "D = " << D << std::endl;

  if (D < 0) {
    std::cout << "no solution" << std::endl;
    return (0);
  }

  if (D == 0) {
    std::cout << "x = "
              << " " << -b / (kXConst * a) << std::endl;
    return (0);
  }

  if (D > 0) {

    std::cout << "x1 =" << (-b + sqrt(static_cast<double>(D)) / kXConst * a)
              << std::endl;
    std::cout << "x2 =" << (-b - sqrt(static_cast<double>(D)) / kXConst * a)
              << std::endl;
    return (0);
  }

  std::cout << "unexpected error" << std::endl;
  return (-1);
}
