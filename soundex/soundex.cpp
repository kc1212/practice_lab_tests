#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "soundex.h"

int count(const char word[], const char sentence[]){

  char mysentence[255];
  char soundex1[5];
  char soundex2[5];
  int counter = 0;
  int len = 0;

  strcpy(mysentence, sentence);
  encode(word, soundex1);
  len = strlen(mysentence);

  // replace all non alphabet with \0
  for (int i = 0; i < len; i++){
    if (!isalpha(mysentence[i]))
      mysentence[i] = '\0';
  }

  // encode and compare every word of the sentence 
  // that starts with the first character of word
  for (int i = 0; i < len; i++){
    if ( mysentence[i] == word[0] ) {
      encode(mysentence+i, soundex2);
      if (compare(soundex1, soundex2)){
        counter++;
      }
    }
  }

  return counter;
}

bool compare(const char one[], const char two[]){

  if (one[0] != two[0]) return false;
  if ((one[0] == '\0') && (two[0] == '\0')) return true;

  return compare(one+1, two+1);
}

void encode(const char name[], char* soundex){

  // check which soundex code the letter belongs to
  // store the previous result and count the number of soundex

  int prev_code; // soundex code of previous letter
  int tmp_code; // temporary soundex code
  int i = 0; // counter for name
  int j = 0; // counter for soundex
  int len = strlen(name); // length of surname

  // start of soundex code is always the first letter
  soundex[0] = toupper(name[0]);

  // for every letter except the first one
  for (i = 1; i < len; i++){

    // if we got 3 characters in the soudex code, retun the function
    if (j>=3){
      soundex[4] = '\0';
      return;
    }

    // get the soudex and assign to tmp_code
    tmp_code = get_soundex_code(name[i]);

    // if the soudex exists, and its not the same as previous soudex
    if ((tmp_code != -1) && (tmp_code != prev_code)){
      soundex[++j] = tmp_code+'0';
      prev_code = tmp_code;
    }
  }

  // fill the rest with zeros if not enough digits to make a 4 char soudex
  if (j <= 3){
    for (int k = j+1; k < 4; k++){
      soundex[k] = '0';
    }
    soundex[4] = '\0';
  }

}

int get_soundex_code(const char c){

  if (is_from_group(LIST1, c)) return 1;
  if (is_from_group(LIST2, c)) return 2;
  if (is_from_group(LIST3, c)) return 3;
  if (is_from_group(LIST4, c)) return 4;
  if (is_from_group(LIST5, c)) return 5;
  if (is_from_group(LIST6, c)) return 6;

  return -1;
}

bool is_from_group(const char list[], const char c){

  int len = strlen(list);

  for (int i = 0; i < len; i++){
    if (list[i] == c){
      return true;
    }
  }

  return false;
}
