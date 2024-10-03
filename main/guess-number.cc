#include "main/guess-number.h"

#include <functional>
#include <iostream>
#include <optional>
#include <string>

std::function<std::string(int, int)> guess_number =
    [](int number, int guess) -> std::string {
  return "Your guess was too " +
         std::string((guess > number) ? "high" : "low") + "\n";
};

std::optional<int> read_number(std::istream &in) {
  int result{};
  if (in >> result) {
    std::cout << "Read number: " << result << "\n";
    return result;
  }

  in.clear();
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return {};
}

void guess_number_with_clues(int number) {
  std::cout << "Guess the number: \n>";
  std::optional<int> guess{1};
  while ((guess = read_number(std::cin)).has_value()) {
    std::cout << "Your guess was " << guess.value() << "\n";
    if (guess.value() == number) {
      std::cout << "Well done! You guessed the number.\n";
      return;
    }
    std::cout << guess_number(number, guess.value());
    std::cout << ">";
  }
  std::cout << "The number was " << number << "\n";
}
