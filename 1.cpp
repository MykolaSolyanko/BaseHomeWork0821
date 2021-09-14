#include <iostream>

int DigitCount(int num) {
  int counter{0};
  do {
    num = num / 10;
    counter++;
  } while (num != 0);
  return counter;
}

void NumberToArray(int *const arr, int num) {
  int arr_size{DigitCount(num)};

  int counter{0};
  do {
    arr[arr_size - 1] = num % 10;
    num = num / 10;
    counter++;
    arr_size--;
  } while (num != 0);
}

int main() {
  constexpr int kData{12345};
  const int kArraySize = DigitCount(kData);

  int *arr = new int[kArraySize];
  NumberToArray(arr, kData);

  int array_sum{0};
  for (int i = 0; i < kArraySize; i++) {
    std::cout << arr[i];
    array_sum += arr[i];
    if ((i + 1) != kArraySize) {
      std::cout << " + ";
    }
    if ((i + 1) == kArraySize) {
      std::cout << " = " << array_sum << std::endl;
    }
  }
  std::cout << array_sum << " / " << kArraySize << " = "
            << array_sum / kArraySize << std::endl;

  delete[] arr;
}
