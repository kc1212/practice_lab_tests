#include <iostream>
// #include <cstring>

using namespace std;

#include "substring.h"

int substring_position2(const char haystack[], const char needle[]){

  // TODO
  return -1;
}

int substring_position(const char haystack[], const char needle[]){
  int pos = 0;

  if (is_prefix(haystack,needle)) return pos;
  pos++;

  for (int i = 1; needle[i]; i++){
    if (is_prefix(haystack,needle+i)) return pos;
    pos++;
  }

  return -1;
}

bool is_prefix(const char haystack[], const char needle[]){
  if (haystack[0] == '\0') return true;
  if (needle[0] == '\0') return false;
  if (haystack[0] != needle[0]) return false;

  return is_prefix(haystack+1, needle+1);
}

// void mystrcpy(char target[], const char source[]){
//   int i = 0;
//   while (source[i] != '\0'){
//     target[i] = source[i];
//     i++;
//   }
//   target[i] = '\0';
// }

// int mystrlen(const char ch[]){
//   int i;
//   for (i = 0; ch[i]; i++){};
//   return i;

// }