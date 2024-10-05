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

void reference_test() {
      // Creating a vector
    std::vector<int> original = {1, 2, 3, 4, 5};
    auto copy = original;

    // Assigning the vector to a reference variable
    std::vector<int>& ref = original;

    // Modifying the vector through the reference
    ref.push_back(6);

    // Both 'original' and 'ref' now contain {1, 2, 3, 4, 5, 6}
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Reference size: " << ref.size() << std::endl;
}

int main() {

  reference_test();
  // MyClass original(42);
  // std::cout << "Address of original: " << &original << std::endl;

  // auto sharedPtr = std::make_shared<const MyClass>(original);
  // std::cout << "Address of shared object: " << sharedPtr.get() << std::endl;
  // std::cout << "Value in shared object: " << sharedPtr->getValue() << std::endl
  //           << std::endl;

  // refCopy(original);

  // std::string who = "world";
  // if (argc > 1) {
  //   who = argv[1];
  // }
  // std::cout << get_greet(who) << std::endl;
  // print_localtime();

  // guess_number_with_clues(generate_random_number());
  return 0;
}
