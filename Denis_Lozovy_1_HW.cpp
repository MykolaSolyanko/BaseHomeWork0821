#include <cmath>
#include <iostream>

int main() {

  int a{};
  int b{};
  int c{};
  constexpr int min{2};
  constexpr int max{255};

  std::cout << "Please enter a in range [" << min << ".." << max << "]\n";
  std::cin >> a;
  if (a < min or a > max) {
    std::cout << "Incorrect a\n";
    return -1;
  }

  std::cout << "\nPlease enter b in range [" << min << ".." << max << "]"
            << std::endl;
  std::cin >> b;
  if (b < min or b > max) {
    std::cout << "Incorrect b\n";
    return -1;
  }

  std::cout << "\nPlease enter c in range [" << min << ".." << max << "]"
            << std::endl;
  std::cin >> c;
  if (c < min or c > max) {
    std::cout << "Incorrect c\n";
    return -1;
  }

  // std::cout << a << " " << b << " " <<  c << "\n";
  std::cout << "The equation is " << a << "x2 + " << b << "x + " << c
            << " = 0\n";

  long long D{(b * b) - (4 * a * c)};
 const auto discriminant  { std::sqrt(D) };

  auto x1();
  auto x2();

  if (D >= 0) {
    auto x1{-b + (D / 2 * a)};
    auto x2{-b - (D / (2 * a))};


    if (x1 == x2) {
      std::cout << "x1 = " << x1;
    } else {
      std::cout << "x1 = " << x1 << " x2 = " << x2 << std::endl;
    }
  }

  else {
    std::cout << "D < 0" << std::endl;
  }
  std::cout << D;
  return 0;
}