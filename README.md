# Wordl

This repository is an engaging and interactive word guessing game developed using the C programming language. Inspired by the popular game Wordle, Wordl challenges players to guess a secret code word within a limited number of attempts. The objective is to use logical reasoning and deduction to uncover the hidden word based on feedback provided after each guess.

## Features

Word Guessing Mechanics: Players attempt to guess the target word within six tries.

Colored Feedback: The program utilizes ANSI escape codes to display hints in color:
* Green (🟩): Letter is in the correct position.
* Yellow (🟨): Letter is in the word but in the wrong position.
* White (⬜): Letter is not in the word.
  
Dynamic Input Handling: The program ensures that only words of the correct length are accepted.

Efficient Scoring Algorithm: The game properly handles repeated letters to prevent incorrect hints.

## How To Run

1. Compile the program using a C compiler such as gcc:

    gcc -o wordle wordle.c
   
3. Execute the compiled program with a target word as a command-line argument:

    ./wordle <target_word>
    
5. Playing the game:

    The user will be prompted to enter guesses, which must be the same length as the target word. The program provides feedback based on     the accuracy of the guess. If the user fails to guess the word within six attempts, the correct word is revealed.


## Core Functions

* assessGuess(char *guess, char *target, int *scores):
Compares the guessed word to the target word and assigns scores based on correctness.

* adjustScore(char *target, int *scores, char *guess, char c):
Ensures correct handling of repeated letters in scoring.

* changeColor(const char *color):
Updates the terminal text color dynamically based on letter accuracy.

* printGuess(char *guess, int *score):
Displays the guessed word with colored feedback.

## Data Structures and Constraints

* The maximum supported word length is 12 characters (modifiable in the source code).
  
* The program uses ANSI escape sequences for color output, making it compatible with most Unix-based terminals.

## Customization and Future Enhancements

1. Modifying Word Length
   * To support longer words, update the userStr and scoreArray arrays in main().

2. Planned Features
   * Improved input handling to prevent invalid inputs.
   * A mode where the target word is randomly selected from a predefined word list.
   * Cross-platform compatibility improvements for Windows terminals.
   * Additional user interface enhancements, such as displaying previous guesses.

