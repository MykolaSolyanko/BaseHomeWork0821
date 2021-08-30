#include <array>
#include <iostream>
#include <string>

enum class Action { EXIT, FIRST_PROGRAM, SECOND_PROGRAM };

int main() {
  while (true) {
    std::cout << "\nHomework-3" << std::endl;
    std::cout << "1. Reverse string" << std::endl;
    std::cout << "2. Inserting an element into an array" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose action: ";

    int userChoice{};
    std::cin >> userChoice;

    Action userAction = static_cast<Action>(userChoice);

    switch (userAction) {
    case Action::FIRST_PROGRAM: {
      std::cout << "\n1. Reverse string" << std::endl;
      std::cout << "Enter string: ";
      std::string userString;
      std::cin >> userString;

      for (int i = (userString.length() - 1); i >= 0; i--) {
        std::cout << userString[i];
      }

      break;
    }
    case Action::SECOND_PROGRAM: {
      std::cout << "\n2. Inserting an number into an array" << std::endl;

      std::array<int, 5> arr{};

      for (int arrIndex{0}; arrIndex < arr.size(); arrIndex++) {
        // Read user input and insert number into an array on arrIndex position;
        std::cout << "Enter number to insert into an array: ";

        int userNumber{};
        std::cin >> userNumber;
        arr[arrIndex] = userNumber;

        int endRange{arrIndex};

        // Sorts numbers in array using bubble sort alghoritm
        for (int beginRange{0}; beginRange < endRange; beginRange++) {
          for (int sortIndex = endRange; sortIndex > beginRange; sortIndex--) {
            int rightNumber{arr[sortIndex]};
            int leftNumber{arr[sortIndex - 1]};

            if (leftNumber > rightNumber) {
              arr[sortIndex] = leftNumber;
              arr[sortIndex - 1] = rightNumber;
            }
          }
        }

        // Display array
        for (int number : arr) {
          std::cout << number << " ";
        }
      }

      break;
    }
    case Action::EXIT:
      return false;
    default:
      std::cout << "Error. Wrong number of action" << std::endl;
    }
  }
}
