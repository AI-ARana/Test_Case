/* C++ Program to implement the classic game of Hangman using only loops, 
variablesand if/else statements. The game should adhere to the following specifications:
1. The program should chose a random word from predefined list as the secret word 
that the player needs to guess. You can manually define the list of words within 
the program.

2. The player should be allowed a certain number of incorrect guesses before 
the game ends.


3. Display the current state of the word after each guess, showing correctly 
guessed letters and placeholders for unknown letters.

4. Inform the player about the number of remaining attempts and the letters 
guessed so far.

5. If the player correctly guesses the entire word, display a winning message.
if the player runs out of attempts, display a losing message 
with the correct word.

Remember, the implementation should avoid the use of arrays. Use loops to 
iterate through the word and check if the guessed letter is present or not. 
Utilize variables for tracking game state and if/else statements for 
decision-making */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to check if the guessed letter is present in the secret word
bool isLetterInWord(char letter, const std::string& word) {
    for (char c : word) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

/* Function to display the current state of the word with placeholders 
for unknown letters */
std::string displayWord(const std::string& word, const std::string& guessedLetters) {
    std::string displayedWord;
    for (char c : word) {
        if (guessedLetters.find(c) != std::string::npos) {
            displayedWord += c;
        } else {
            displayedWord += '_';
        }
    }
    return displayedWord;
}

int main() {
    // Define the list of words
    const std::string words[] = {"hangman", "computer", "programming", "python", "algorithm"};
    const int numWords = sizeof(words) / sizeof(words[0]);

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Choose a random word from the list
    std::string secretWord = words[std::rand() % numWords];

    // Set the maximum number of attempts
    const int maxAttempts = 6;
    int remainingAttempts = maxAttempts;

    // Track guessed letters
    std::string guessedLetters;

    std::cout << "Welcome to Hangman!\n";

    while (remainingAttempts > 0) {
        std::cout << "\nSecret word: " << displayWord(secretWord, guessedLetters) << "\n";
        std::cout << "Guessed letters: " << guessedLetters << "\n";
        std::cout << "Attempts remaining: " << remainingAttempts << "\n";

        // Ask the player for a guess
        std::cout << "Enter a letter guess: ";
        char guess;
        std::cin >> guess;

        // Check if the letter has already been guessed
        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "You've already guessed that letter!\n";
            continue;
        }

        guessedLetters += guess;

        // Check if the guessed letter is in the word
        if (isLetterInWord(guess, secretWord)) {
            std::cout << "Correct guess!\n";
        } else {
            std::cout << "Incorrect guess.\n";
            remainingAttempts--;
        }

        // Check if the player has guessed the entire word
        if (displayWord(secretWord, guessedLetters) == secretWord) {
            std::cout << "Congratulations! You've guessed the word: " << secretWord << "\n";
            break;
        }
    }

    // If the player runs out of attempts
    if (remainingAttempts == 0) {
        std::cout << "You ran out of attempts! The correct word was: " << secretWord << "\n";
    }

    return 0;
}