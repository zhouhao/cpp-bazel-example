#include <iostream>
#include <string>
#include <functional>
#include <optional>

std::function<std::string(int, int)> guess_number = [](int number, int guess) -> std::string
{
    return "Your guess was too " + std::string((guess > number) ? "high" : "low") + "\n";
};

std::optional<unsigned int> read_number(std::istream &in)
{
    int result{};
    if (in >> result)
    {
        return result;
    }

    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return {};
}

void guess_number_with_clues(unsigned int number, std::function<std::string(int, int)> message_function)
{
    std::cout << "Guess the number: \n>";
    std::optional<unsigned int> guess = std::nullopt;
    while (guess != read_number(std::cin))
    {
        if (guess.value() == number)
        {
            std::cout << "Well done! You guessed the number.\n";
            return;
        }
        std::cout << message_function(number, guess.value());
        std::cout << ">";
    }
    std::cout << "The number was " << number << "\n";
}
