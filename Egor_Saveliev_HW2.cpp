#include <iostream>
#include <vector>

// return how many digits in number
int numberLength(long long number) {
  int counter{0};
  while (number != 0) {
    number /= 10;

    counter++;
  }

  return counter;
}

int main() {
  // Infinity cicle. User choose programm to run.
  while (true) {
    std::cout << "\nHomework-2" << std::endl;
    std::cout
        << "1. Calculate the sum and arithmetic mean of digits in a number"
        << std::endl;
    std::cout << "2. Lucky ticket" << std::endl;
    std::cout << "3. Reverse numbers" << std::endl;
    std::cout << "4. Sum of odd elements" << std::endl;
    std::cout << "5. Best divisor" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose task: ";

    int kTask{};
    std::cin >> kTask;

    // First task.
    if (kTask == 1) {
      std::cout
          << "\n1. Calculate the sum and arithmetic mean of digits in a number"
          << std::endl;
      std::cout << "Enter number: ";

      long long userNumber{};
      std::cin >> userNumber;

      int userNumberLength{numberLength(userNumber)};

      std::vector<int> arrayOfDigits(userNumberLength);

      // Separate last digit and save it in vector. Count sum of digits
      int sumOfDigits{};
      for (int i{userNumberLength - 1}; i >= 0; --i) {
        int lastDigit = userNumber % 10;
        userNumber /= 10;
        arrayOfDigits[i] = lastDigit;
        sumOfDigits += lastDigit;
      }

      // Display digits of number and arithmetic mean of digits
      for (int i{0}; i < userNumberLength; ++i) {
        if (i < (userNumberLength - 1)) {
          std::cout << arrayOfDigits[i] << " + ";
        } else {
          std::cout << arrayOfDigits[i] << " = ";
          std::cout << sumOfDigits << std::endl;
          std::cout << sumOfDigits << " / " << userNumberLength << " = "
                    << sumOfDigits / userNumberLength << std::endl;
        }
      }
    }

    // Second task
    if (kTask == 2) {
      std::cout << "\n2. Lucky ticket" << std::endl;

      int sixDigitNumber{};
      constexpr int requiredLength{6};

      // Check if user input == 6
      while (true) {
        std::cout << "Enter six digit number: ";
        std::cin >> sixDigitNumber;

        if (numberLength(sixDigitNumber) == requiredLength) {
          break;
        } else {
          std::cout << "Error. Incrorrect number of digits." << std::endl;
        }
      }

      int sumOf_FirstThreeDigits{};
      int sumOf_SecondThreeDigits{};
      // Calculate sum of first and second three digits
      for (int i = requiredLength; i != 0; --i) {
        int lastDigit = sixDigitNumber % 10;
        sixDigitNumber /= 10;

        if (i > 3) {
          sumOf_FirstThreeDigits += lastDigit;
        } else {
          sumOf_SecondThreeDigits += lastDigit;
        }
      }
      // Check if it's lucky ticket
      if (sumOf_FirstThreeDigits == sumOf_SecondThreeDigits) {
        std::cout << "Lucky ticket!" << std::endl;
      } else {
        std::cout << "Unlucky ticket..." << std::endl;
      }
    }

    // Third task
    if (kTask == 3) {
      std::cout << "\n3. Reverse numbers" << std::endl;
      std::cout << "Enter number: ";

      long long numberToReverse{};
      long long reversedNumber{0};

      std::cin >> numberToReverse;

      while (numberToReverse != 0) {
        reversedNumber = reversedNumber * 10 + numberToReverse % 10;
        numberToReverse /= 10;
      }

      std::cout << reversedNumber << std::endl;
    }

    // Fourth task
    if (kTask == 4) {
      std::cout << "\n4. Sum of odd elements" << std::endl;

      constexpr int minNumberOfElements{1};
      constexpr int maxNumberOfElements{50};
      int numberOfElements{};
      // Takes number of elements. Cheks if it in range [1 - 50]
      while (true) {
        std::cout << "\nEnter number of elements [" << minNumberOfElements
                  << " - " << maxNumberOfElements << "]: ";
        std::cin >> numberOfElements;

        if (numberOfElements >= 1 && numberOfElements <= 50) {
          break;
        } else {
          std::cout << "Error. Entered number of elements out of range"
                    << std::endl;
        }
      }

      constexpr int minRangeElement{-60};
      constexpr int maxRangeElement{90};

      std::cout << "Enter elements in range [" << minRangeElement << " - "
                << maxRangeElement << "]" << std::endl;

      std::vector<int> Elements(numberOfElements);

      // Puts odd elements to a vector
      for (int i{0}; i < numberOfElements; ++i) {
        int enteredNumber{};

        // Checks if entered elements in range [-60 ... 90]
        while (true) {
          std::cin >> enteredNumber;

          if (enteredNumber >= minRangeElement &&
              enteredNumber <= maxRangeElement) {
            break;
          } else {
            std::cout << "Error. Entered element out of range. Try again"
                      << std::endl;
          }
        }

        // Check if number odd
        if (enteredNumber % 2 != 0) {
          Elements[i] = enteredNumber;
        }
      }
      int sumOfOddElements{};

      for (int element : Elements) {
        sumOfOddElements += element;
      }

      std::cout << "Sum of odd elements: " << sumOfOddElements << std::endl;
    }

    // Fifth task
    if (kTask == 5) {
      std::cout << "\n5. Best divisor" << std::endl;
      std::cout << "Enter number: ";
      long long number{};
      std::cin >> number;

      int divisor{};

      for (divisor = 2; divisor < number; divisor++) {
        if (number % divisor == 0) {
          std::cout << "Best divisor: " << number / divisor << std::endl;
          break;
        }
      }
    }

    // End of programm
    if (kTask == 0) {
      break;
    }

    // Check user input
    if (kTask < 0 || kTask > 9) {
      std::cout << "\nError. Incorrect number." << std::endl;
    }
  }

  return 0;
}
