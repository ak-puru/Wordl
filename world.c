#include <stdio.h>
#include <string.h>

const char * const GREEN_COLOR = "\x1b[32m";
const char * const YELLOW_COLOR = "\x1b[33m";
const char * const WHITE_COLOR = "\x1b[0m";
const char * currentColor = WHITE_COLOR;

void changeColor(const char *color) {
  if (currentColor == color) return;
  printf("%s", color);
  currentColor = color;
}

int countOccurrences(char *sourceStr, char targetChar) {
  int count = 0;
  for (size_t i = 0; i <= strlen(sourceStr); ++i) {
    if (sourceStr[i] == targetChar) ++count;
  }
  return count;
}

void assessGuess(char *guess, char *target, int *scores) {
  int size = strlen(target) + 1;
  for (size_t i = 0; i < size; ++i) {
    if (guess[i] == target[i]) scores[i] = 2;
    else {
      scores[i] = 0;
      for (size_t j = 0; j < size; ++j) {
        if (guess[i] == target[j]) {
          scores[i] = 1;
          break;
        }
      }
    }
  }
}

void adjustScore(char *target, int *scores, char *guess, char c){
  int size = strlen(target) + 1;
  int cCount = countOccurrences(target, c);
  for (size_t j = 0; j < size - 1; ++j) {
    char check = target[j];
    if (scores[j] == 2 && check == c && cCount > 0) --cCount;
  }
  for (size_t k = 0; k < size - 1; ++k) {
    char check = guess[k];
    if (scores[k] == 1 && check == c && cCount > 0) --cCount;
    else {
      if (scores[k] == 1 && check == c && cCount == 0) scores[k] = 0;
    }
  }
}

void printArray(int *arr, size_t len) {
  for (int i = 0; i < len; ++i) printf("%d ", arr[i]);
}

void printGuess(char *guess, int *score) {
  for (size_t i = 0; i < strlen(guess); ++i){
    switch (score[i]) {
      case 0:
        changeColor(WHITE_COLOR);
        printf("%c",guess[i]);
        break;
      case 1:
        changeColor(YELLOW_COLOR);
        printf("%c",guess[i]);
        break;
      case 2:
        changeColor(GREEN_COLOR);
        printf("%c",guess[i]);
        break;
      default:
        printf("This should not be happening");
        break;
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Invalid number of arguments\n");
    return 1;
  }
  char userStr[13];
  int count = 6;
  while (!feof(stdin) && count > 0) {
    printf("Enter guess: ");
    scanf("%s", userStr);
    if (strlen(userStr) != strlen(argv[1])) {
      printf("Invalid string, not the same length as argument\n");
      return 2;
    }
    else {
      int scoreArray[13];
      assessGuess(userStr, argv[1], scoreArray);
      for (size_t i = 0; i < strlen(argv[1]) + 1; ++i) adjustScore(argv[1], scoreArray, userStr, userStr[i]);
      printGuess(userStr, scoreArray);
      printf("\n");
      changeColor(WHITE_COLOR);
      int cumulativeScore = 0;
      for (size_t i = 0; i < strlen(argv[1]); ++i) cumulativeScore = cumulativeScore + scoreArray[i];
      --count;
      if (cumulativeScore == strlen(argv[1]) * 2) {
        printf("Finished in %d guesses\n", (6 - count));
        return 0;
      }
    }
  }
  
  printf("Failed to guess the word: %s\n", argv[1]);
  return 0;
}
