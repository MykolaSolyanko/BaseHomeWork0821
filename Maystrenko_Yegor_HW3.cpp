#include <array>
#include <ctime>
#include <iostream>
#include <string>

constexpr int kErrorExit{-1};
constexpr int kSuccessExit{0};

void reverse() {
  std::cout << "Please input a word to reverse" << std::endl;
  std::string line;
  std::cin >> line;
  for (int i = line.length() - 1; i >= 0; --i) {
    std::cout << line[i];
  }
}

void question() {
  std::cout << "Write yes to continue or something else to exit" << std::endl;
  std::string question{};
  std::cin >> question;
  if (question != "yes") {
    std::cout << "Program has ended" << std::endl;
    exit(0);
  }
}

int deleting() {
  srand(time(NULL));

  constexpr int karrsize{5};
  std::array<int, karrsize> array{};

  for (int i = 0; i < karrsize; ++i) {
    array[i] = rand() % 5 + 1;
  }

  int Sum{0};
  for (int i = 0; i < karrsize; ++i) {
    Sum += array[i];
  }

  int number{};
  constexpr int kmax{5};
  constexpr int kmin{1};
  while (Sum != 0) {
    std::cout << "Please input a number to delete it in array [" << kmin
              << "..." << kmax << "]" << std::endl;
    std::cin >> number;
    if ((number > kmax) || (number < kmin)) {
      std::cout << "Input correct number of range" << std::endl;
      return kErrorExit;
    }
    int space{0};
    for (int i = 0; i < karrsize; ++i) {
      if (number == array[i]) {
        Sum -= array[i];
        array[i] = 0;
        space++;
      }
    }
    if (space == 0) {
      std::cout << "There is no " << number << " in array" << std::endl;
    } else {
      std::cout << "You successfully delete " << number << " from array"
                << std::endl;
      space--;
    }
    question();
  }

  std::cout << "You win!!! You delete all numbers from array" << std::endl;
  return kSuccessExit;
}

void upper() {
  std::cout << "Please input letters to make them big" << std::endl;
  std::string line;
  std::cin >> line;
  for (char &i : line) {
    if ((i >= 'a') && (i <= 'z')) {
      i = i - 32;
    }
  }
  for (char i : line) {
    std::cout << i;
  }
}

void down() {
  std::cout << "Please input letters to make them small" << std::endl;
  std::string line;
  std::cin >> line;
  for (char &i : line) {
    if ((i >= 'A') && (i <= 'Z')) {
      i = i + 32;
    }
  }
  for (char i : line) {
    std::cout << i;
  }
}

void digit() {
  std::cout << "Please input something to find there numbers" << std::endl;
  std::string line;
  std::cin >> line;
  for (char i : line) {
    if ((i >= '0') && (i <= '9')) {
      std::cout << i << " ";
    }
  }
  std::cout << "are digets" << std::endl;
}

void arradd() {
  constexpr int karrsize{5};
  std::array<int, karrsize> array{};

  int number;
  for (int i = 0; i < karrsize; ++i) {
    std::cout << "\nPlease input new positive array number" << std::endl;
    std::cin >> number;
    if (number < 0) {
      std::cout << "Pleses use correct type" << std::endl;
      kErrorExit;
    }
    for (int j = 0; j < karrsize; ++j) {
      if (number >= array[j]) {
        for (int k = karrsize; k > j; --k) {
          array[k] = array[k - 1];
        }
        array[j] = number;
        break;
      }
    }
    for (int v = 0; v < karrsize; ++v) {
      std::cout << array[v] << " ";
    }
    std::cout << "\n";
    question();
  }
}

int main() {

  // reverse(); // вивід рядка навпаки
  // deleting(); // видалення елементів масиву
  // upper(); // верхній регістр
  // down(); // нижній регістр
  // digit(); // пошук цифр серед рядка
  // arradd(); // сортування масиву

  return kSuccessExit;
}
