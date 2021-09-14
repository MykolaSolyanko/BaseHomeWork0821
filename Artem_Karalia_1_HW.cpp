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

    if ((a > kLowARange && a < kHighARange) && (a != 0)) {
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

    if (b > kLowBRange && b < kHighBRange) {
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

    if (c > kLowCRange && c < kHighCRange) {
      std::cout << "c = " << c << std::endl;
      break;
    }
    std::cout << "Invalid data, please enter coef c again\n";
  }

  constexpr int kSuccessExit{0};
  constexpr int kErrorExit{-1};

  constexpr int kDConst{4};
  constexpr int kXConst{2};

  const long long D = {(b * b) - (kDConst * a * c)};

  if (D < 0) {
    std::cout << "D = " << D << std::endl;
    return kErrorExit;
  }

  if (D == 0) {
    std::cout << "x = "
              << " " << -b / (static_cast<double>(kXConst) * a) << std::endl;
    return kSuccessExit;
  }

  if (D > 0) {

    std::cout << "x1 =" << ((-b + sqrt(D)) / (kXConst * a)) << std::endl;
    std::cout << "x2 =" << ((-b - sqrt(D)) / (kXConst * a)) << std::endl;
    return kSuccessExit;
  }

  std::cout << "unexpected error" << std::endl;
  return kErrorExit;
}
