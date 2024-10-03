#include <iostream>
#include <memory>
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

class MyClass {
 public:
  MyClass(int v) : value(v) {
    std::cout << "Constructor called with value " << value << std::endl;
  }

  MyClass(const MyClass& other) : value(other.value) {
    std::cout << "Copy constructor called with value " << value << std::endl;
  }

  ~MyClass() {
    std::cout << "Destructor called for value " << value << std::endl;
  }

  int getValue() const { return value; }

 private:
  int value;
};

void refCopy(const MyClass& original) {
  auto sharedPtr = std::make_shared<const MyClass>(original);
  std::cout << '\t' << sharedPtr.get()->getValue() << std::endl;
}

int main() {
  MyClass original(42);
  std::cout << "Address of original: " << &original << std::endl;

  auto sharedPtr = std::make_shared<const MyClass>(original);
  std::cout << "Address of shared object: " << sharedPtr.get() << std::endl;
  std::cout << "Value in shared object: " << sharedPtr->getValue() << std::endl
            << std::endl;

  refCopy(original);

  // std::string who = "world";
  // if (argc > 1) {
  //   who = argv[1];
  // }
  // std::cout << get_greet(who) << std::endl;
  // print_localtime();

  // guess_number_with_clues(generate_random_number());
  return 0;
}
