#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "soundex.h"

int count(const char word[], const char sentence[]){

  char* myword;
  char mysentence[255];
  int i = 0;
  int j = 0;
  char soundex1[5];
  char soundex2[5];

  strcpy(mysentence, sentence);
  encode(word, soundex1);

  // while there is still a word in the sentence
  // put the word in a new variable and delete it from the sentence

  myword = strtok(mysentence, " .,-");

  while (myword != NULL){

    encode(myword, soundex2);

    if (compare(soundex1, soundex2)){
      j++;
    }

    myword = strtok(NULL, " .,-");
    i++;
  }

  return j;
}

bool compare(char one[], char two[]){

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

  *soundex = name[0]; // start of soundex code is always the first letter

  // for every letter except the first one
  for (i = 1; i < len; i++){

    // if we got 3 characters in the soudex code, retun the function
    if (j>=3){
      soundex[4] = '\0';
      return;
    }

    tmp_code = get_soundex_code(name[i]);

    if ((tmp_code != -1) && (tmp_code != prev_code)){
      soundex[++j] = tmp_code+'0';
      prev_code = tmp_code;
    }
  }

  // fill the rest with zeros
  if (j <= 3){
    for (int k = j+1; k < 4; k++){
      soundex[k] = '0';
    }
    soundex[4] = '\0';
  }

}

int get_soundex_code(const char c){

  char list1[] = {'b', 'f', 'p', 'v'};
  char list2[] = {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'};
  char list3[] = {'d', 't'};
  char list4[] = {'l'};
  char list5[] = {'m', 'n'};
  char list6[] = {'r'};

  if (is_from_group(list1, c)) return 1;
  if (is_from_group(list2, c)) return 2;
  if (is_from_group(list3, c)) return 3;
  if (is_from_group(list4, c)) return 4;
  if (is_from_group(list5, c)) return 5;
  if (is_from_group(list6, c)) return 6;

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
