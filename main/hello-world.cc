#include <iostream>
#include <string>

#include "lib/hello-time.h"
#include "main/guess-number.h"
#include "main/hello-greet.h"

int main(int argc, char** argv) {
  std::string who = "world";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();

  guess_number_with_clues(42);
  return 0;
}
