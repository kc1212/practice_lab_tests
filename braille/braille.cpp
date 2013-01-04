#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "braille.h"

int encode_character(const char ch, char braille[]){

  if (isalpha(ch)){
    if (isupper(ch)){
      strcpy(braille, UPPER);
      strcat(braille, ALPHA[ch-'A']);
    } else {
      strcpy(braille, ALPHA[ch-'a']);
    }

  } else if (isdigit(ch)) {
    strcpy(braille, NUM_SIGN);
    strcat(braille, NUM[ch-'0']);

  } else if (ispunct(ch)) {
    switch (ch){
      case '.':
        strcpy(braille, PERIOD);
        break;
      case ',':
        strcpy(braille, COMMA);
        break;
      case ';':
        strcpy(braille, SEMICOLON);
        break;
      case '-':
        strcpy(braille, HYPHEN);
        break;
      case '!':
        strcpy(braille, EXCLAMATION);
        break;
      case '?':
        strcpy(braille, QUESTION);
        break;
      case ')':
      case '(':
        strcpy(braille, PARAN);
        break;
      default:
        return -1;
    }

  } else {
    return -1;
  }

  return strlen(braille);
}


void encode(const char text[], char braille[]){
  char tmp[512];

  // if character reached the end, stop
  if (text[0] == '\0') return;

  encode_character(text[0], tmp);

  if (braille[0] == '\0')
    strcpy(braille, tmp);
  else {
    strcat(braille, tmp);
  }

  encode(text+1, braille);
}


void print_braille(const char text[], ostream& output){
  int pos1;
  int pos2;
  char braille[512];
  char b_len = 0; // braille length
  char t_len = 0; // text length

  braille[0] = '\0';
  encode(text, braille);
  b_len = strlen(braille);
  t_len = strlen(text);


  for (pos1=0, pos2=3; pos2 < b_len; pos1+=6, pos2+=6){
    output << braille[pos1] << braille[pos2] << ' ';
  }
  output << endl;

  for (pos1=1, pos2=4; pos2 < b_len; pos1+=6, pos2+=6){
    output << braille[pos1] << braille[pos2] << ' ';
  }
  output << endl;

  for (pos1=2, pos2=5; pos2 < b_len; pos1+=6, pos2+=6){
    output << braille[pos1] << braille[pos2] << ' ';
  }
  output << endl;

  for (int i = 0; i < t_len; i++){

    if (isalpha(text[i])){
      if (isupper(text[i])){
        output << "   ";
      }
      output << text[i];

    } else if (isdigit(text[i])) {
      output << "   " << text[i];

    } else {
      output << text[i];
    }

  output << "  ";
  }

  output << endl;
}
