#include <iostream>
#include <random>
#include <string>

#include "lib/hello-time.h"
#include "main/guess-number.h"
#include "main/hello-greet.h"

int generate_random_number() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);
  return dis(gen);
}

int main(int argc, char** argv) {
  std::string who = "world";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();

  guess_number_with_clues(generate_random_number());
  return 0;
}
