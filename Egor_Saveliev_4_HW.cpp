#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <typeinfo>

// bubble sort
template <typename T>
void bubble_sort(T *arr, int low_range, int const arr_length) {
  for (int i{}; i < arr_length; i++) {

    int start_iterator{low_range};

    for (start_iterator; start_iterator < arr_length - i - 1;
         start_iterator++) {

      if (*(arr + start_iterator) > *(arr + start_iterator + 1)) {

        T tmp{*(arr + start_iterator)};
        *(arr + start_iterator) = *(arr + start_iterator + 1);
        *(arr + start_iterator + 1) = tmp;
      }
    }
  }
}

constexpr short int ascii_zero{48};
constexpr short int ascii_nine{57};

void char_bubble_sort(char *arr, int low_range, int const arr_length) {
  int numbers_iterator{};

  for (int i{}; i < arr_length; i++) {

    int start_iterator{low_range};

    for (start_iterator; start_iterator < arr_length - i - 1;
         start_iterator++) {

      // if char is a number put it to the end of array
      if (*(arr + (start_iterator + 1)) >= ascii_zero and
          *(arr + (start_iterator + 1)) <= ascii_nine) {

        int number{*(arr + (start_iterator + 1))};
        int shift_iterator{start_iterator + 1};

        for (shift_iterator; shift_iterator < (arr_length - 1);
             shift_iterator++) {
          *(arr + shift_iterator) = *(arr + shift_iterator + 1);
        }

        *(arr + shift_iterator) = number;

        i++;
        numbers_iterator++;
      }

      if (*(arr + start_iterator) > *(arr + start_iterator + 1)) {

        char tmp{*(arr + start_iterator)};
        *(arr + start_iterator) = *(arr + start_iterator + 1);
        *(arr + start_iterator + 1) = tmp;
      }
    }
  }

  bubble_sort(arr, (arr_length - numbers_iterator), arr_length);
}

template <typename T> void bubble_sort_timer(T *arr, int const arr_length) {
  auto start = std::chrono::high_resolution_clock::now();

  bubble_sort(arr, 0, arr_length);

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<float, std::milli> duration = end - start;

  std::cout << "Bubble sort duration: " << duration.count() << " ms"
            << std::endl;
}

// quicksort
template <typename T> void quick_sort(T *arr, int low, int high) {
  int i{low};
  int j{high};
  T pivot{arr[(i + j) / 2]};

  while (i <= j) {
    while (*(arr + i) < pivot)
      i++;
    while (*(arr + j) > pivot)
      j--;
    if (i <= j) {
      T tmp{*(arr + i)};
      *(arr + i) = *(arr + j);
      *(arr + j) = tmp;
      i++;
      j--;
    }
  }

  if (j > low) {
    quick_sort(arr, low, j);
  }

  if (i < high) {
    quick_sort(arr, i, high);
  }
}

template <typename T> void quick_sort_timer(T *arr, int low, int high) {
  auto start = std::chrono::high_resolution_clock::now();

  quick_sort(arr, low, high);

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<float, std::milli> duration = end - start;

  std::cout << "Quick sort duration: " << duration.count() << " ms"
            << std::endl;
}

// array operations
template <typename T> void input_to_array(T *arr, short const arr_length) {
  for (T *ptr = arr; ptr < arr + arr_length; ++ptr) {
    std::cout << "Enter: ";
    T user_input{};
    std::cin >> user_input;

    *ptr = user_input;
  }
}

void int_random_array(int *arr, short const arr_length) {

  std::default_random_engine r_engine(std::random_device{}());
  std::uniform_int_distribution<int> random(std::numeric_limits<int>::min(),
                                            std::numeric_limits<int>::max());

  for (int *ptr = arr; ptr < arr + arr_length; ++ptr) {
    *ptr = random(r_engine);
  }
}

void uint_random_array(unsigned int *arr, short const arr_length) {

  std::default_random_engine r_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned int> random(
      std::numeric_limits<unsigned int>::min(),
      std::numeric_limits<unsigned int>::max());

  for (unsigned int *ptr = arr; ptr < arr + arr_length; ++ptr) {
    *ptr = random(r_engine);
  }
}

void double_random_array(double *arr, short const arr_length) {

  std::default_random_engine r_engine(std::random_device{}());
  std::uniform_real_distribution<double> random(
      std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

  for (double *ptr = arr; ptr < arr + arr_length; ++ptr) {
    *ptr = random(r_engine);
  }
}

template <typename T>
void copy_array(T *arr_copied, T *arr_copy, short const arr_length) {

  T *arr_stop{arr_copied + arr_length};

  while (arr_copied < arr_stop) {
    *arr_copy = *arr_copied;

    arr_copied++;
    arr_copy++;
  }
}

enum class Action { EXIT, FIRST_PROGRAM, SECOND_PROGRAM };

int main() {
  while (true) {
    std::cout << "\nHomework-4" << std::endl;
    std::cout << "1. Sorting with performance comparison" << std::endl;
    std::cout << "2. Sorting with different types" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose action: ";

    int array_for_sorting[10]{};
    int array_for_sorting_copy[10]{};
    constexpr short array_length{10};

    int userChoice{};
    std::cin >> userChoice;

    Action userAction = static_cast<Action>(userChoice);

    switch (userAction) {
    case Action::FIRST_PROGRAM: {
      std::cout << "\nSorting with performance comparison" << std::endl;

      short action;
      constexpr short enter_numbers_to_array{1};
      constexpr short generate_numbers_to_array{2};

      // checks user input
      while (true) {
        std::cout << "\n1. Enter numbers into array" << std::endl;
        std::cout << "2. Randomly generate numbers" << std::endl;

        std::cout << "Choose action: " << std::endl;
        std::cin >> action;

        if (action == enter_numbers_to_array or
            action == generate_numbers_to_array) {
          break;
        }

        std::cout << "Error. Wrong number of action" << std::endl;
      }

      // fills array
      switch (action) {
      case enter_numbers_to_array: {
        input_to_array(array_for_sorting, array_length);

        copy_array(array_for_sorting, array_for_sorting_copy, array_length);

        bubble_sort_timer(array_for_sorting, array_length);

        quick_sort_timer(array_for_sorting_copy, 0, array_length - 1);

        break;
      }
      case generate_numbers_to_array: {
        int_random_array(array_for_sorting, array_length);

        copy_array(array_for_sorting, array_for_sorting_copy, array_length);

        bubble_sort_timer(array_for_sorting, array_length);

        quick_sort_timer(array_for_sorting_copy, 0, array_length - 1);
        break;
      }
      default: {
        std::cout << __FUNCSIG__ << std::endl;
        break;
      }
      }

      break;
    }
    case Action::SECOND_PROGRAM: {
      std::cout << "\nSorting with different types" << std::endl;

      std::cout << "Which type of array you want to sort?" << std::endl;
      std::cout << "1. Unsigned int" << std::endl;
      std::cout << "2. Double" << std::endl;
      std::cout << "3. Char" << std::endl;

      short action;
      constexpr short sort_uint{1};
      constexpr short sort_double{2};
      constexpr short sort_char{3};

      // checks user input
      while (true) {
        std::cout << "Choose action: " << std::endl;
        std::cin >> action;

        if (action == sort_uint or action == sort_double or
            action == sort_char) {
          break;
        }

        std::cout << "Error. Wrong number of action" << std::endl;
      }

      switch (action) {
      case sort_uint: {
        unsigned int uint_array[array_length]{};

        uint_random_array(uint_array, array_length);

        std::cout << "\n";

        bubble_sort_timer(uint_array, array_length);

        for (auto a : uint_array) {
          std::cout << typeid(a).name() << " " << a << std::endl;
        }

        break;
      }
      case sort_double: {
        double double_array[array_length]{};

        double_random_array(double_array, array_length);

        std::cout << "\n";

        bubble_sort_timer(double_array, array_length);

        for (auto a : double_array) {
          std::cout << typeid(a).name() << " " << a << std::endl;
        }

        break;
      }
      case sort_char: {
        char char_array[array_length]{};

        input_to_array(char_array, array_length);

        std::cout << "\n";

        char_bubble_sort(char_array, 0, array_length);

        for (auto a : char_array) {
          std::cout << typeid(a).name() << " " << a << std::endl;
        }

        break;
      }
      default: {
        std::cout << __FUNCSIG__ << std::endl;
        break;
      }
      }

      break;
    }
    case Action::EXIT: {
      return false;
    }
    default: {
      std::cout << "Error. Wrong number of action" << std::endl;
    }
    }
  }
}
