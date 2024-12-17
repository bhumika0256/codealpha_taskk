#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // Generate random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess it?" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (std::abs(guess - randomNumber) <= 5 && guess != randomNumber) {
                std::cout << "Very close! Keep trying!" << std::endl;
            } else if (guess < randomNumber) {
                std::cout << "Too low! Keep trying!." << std::endl;
            } else if (guess > randomNumber) {
                std::cout << "Too high! Keep trying!." << std::endl;
            } else {
                std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
                
            }
    } while (guess != randomNumber);

    return 0;
}