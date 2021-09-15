#include <iostream>

constexpr short kSuccessExit{0};
constexpr short kErrorExit{-1};

int main() {
  long long ticket{0};
  constexpr int kTicketLowRange{100000};
  constexpr int kTicketHighRange{999999};

  do {
    ticket = 0;
    std::cout << "Please enter your ticket number:" << std::endl;
    std::cin >> ticket;
    if (ticket >= kTicketLowRange && ticket <= kTicketHighRange) {
      break;
    } else {
      std::cout << "Wrong ticket number" << std::endl;
    }

  } while (true);

  int first_sum{0};
  int second_sum{0};
  int buffer{0};
  constexpr short kDivider{10};
  constexpr short kSecondTicketPart{999};
  constexpr short kFirstTicketPart{0};
  
  do {
    buffer = ticket % kDivider;
    second_sum = second_sum + buffer;
    ticket = ticket / kDivider;
  } while (ticket > kSecondTicketPart);
  do {
    buffer = ticket % kDivider;
    first_sum = first_sum + buffer;
    ticket = ticket / kDivider;
  } while (ticket != kFirstTicketPart);
  if (first_sum == second_sum) {
    std::cout << "Your ticket is lucky";
    return kSuccessExit;
  } else {
    std::cout << "Your ticket is not lucky";
    return kErrorExit;
  }
}
