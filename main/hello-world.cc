#include "lib/hello-time.h"
#include "main/hello-greet.h"
#include "main/guess-number.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string who = "world";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();

  guess_number_with_clues(42, guess_number);  
  return 0;
}
