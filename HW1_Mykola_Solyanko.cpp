#include <iomanip>
#include <iostream>

int main() {

  constexpr int kErrorExit{-1};

  constexpr int kSuccessExit{0};
  constexpr int kLowARange{10};
  constexpr int kHighARange{125};

  constexpr int kLowBRange{10};
  constexpr int kHighBRange{125};

  constexpr int kLowCRange{10};
  constexpr int kHighCRange{125};

  int a{};

  std::cout << "Please enter coef a [" << kLowARange << ".." << kHighARange
            << "]\n";
  std::cin >> a;
  if (a < kLowARange || a > kHighARange) {
    std::cout << "incorrect input coef a\n";
    return kErrorExit; // error
  }

  int b{};
  std::cout << "Please enter coef b [" << kLowBRange << ".." << kHighBRange
            << "]\n";
  std::cin >> b;
  if (b < kLowBRange || b > kHighBRange) {
    std::cout << "incorrect input coef b\n";
    return kErrorExit; // error
  }

  int c{};
  std::cout << "Please enter coef c [" << kLowCRange << ".." << kHighCRange
            << "]\n";
  std::cin >> c;
  if (c < kLowCRange || c > kHighCRange) {
    std::cout << "incorrect input coef c\n";
    return kErrorExit; // error
  }

  long long D{(b * b) - (4 * a * c)};

  if (D >= 0) {
    auto x1{D / (2. * a)};
  } else if (D == 0) {
  }

  return kSuccessExit;
}
