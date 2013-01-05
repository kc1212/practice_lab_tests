#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "piglatin.h"

void translateStream(istream& input, ostream& output){
  char word[255];
  char translated_word[255];
  int i = 0;

  word[0] = input.get();
  if (input.bad() || input.eof()) return;

  if (!isalpha(word[0]) && !isdigit(word[0])){
    translated_word[0] = word[0];
    translated_word[1] = '\0';

  } else {
    for (i = 1; isalpha(word[i-1]) || isdigit(word[i-1]); i++){
      word[i] = input.get();
    }
    input.unget();
    word[i-1] = '\0';
    translateWord(word, translated_word);
  }

  output << translated_word;
  translateStream(input, output);
}

void translateWord(const char english[], char piglatin[]){

  int vowelPos = findFirstVowel(english);
  int len = strlen(english);

  // if is digit
  if (isdigit(english[0])){
    strcpy(piglatin, english);

  // if no vowel found
  } else if (vowelPos == -1){
    strcpy(piglatin, english);

  // if the vowel is the first letter
  } else if (vowelPos == 0){
    strcpy(piglatin, english);
    strcat(piglatin, "way");

  // otherwise
  } else {
    strcpy(piglatin, english+vowelPos);
    strncat(piglatin, english, vowelPos);

    if (initialCapital(english)){
      piglatin[0] = toupper(piglatin[0]);
      piglatin[len-vowelPos] = tolower(piglatin[len-vowelPos]);
    }

    strcat(piglatin, "ay");
  }

}

bool initialCapital(const char word[]){

  int len = strlen(word);

  if (islower(word[0])) return false;

  for (int i = 1; i < len; i++){
    if (isupper(word[i])) return false;
  }

  return true;
}

int findFirstVowel(const char word[]){

  int i = 0;
  int len = strlen(word);

  // check if first letter is 'y'
  if (tolower(word[0]) == 'y') {
    i = 1;
  } 

  for ( ; i < len-1; i++){
    if (isVowel(word[i])) return i;
  }

  // check last letter
  if ((tolower(word[i]) != 'y') && isVowel(word[i]) ){
    return i;
  }

  return -1;
}

bool isVowel(const char ch){

  int len = strlen(VOWELS);

  for (int i = 0; i < len; i++){
    if (VOWELS[i] == tolower(ch)) return true;
  }

  return false;
}