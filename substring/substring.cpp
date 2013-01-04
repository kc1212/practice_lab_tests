#include <iostream>
#include "substring.h"
using namespace std;

int substring_position(const char haystack[], const char needle[]){
  int i = 0;
  char a[255], b[255];

  if (needle[0] == '\0' && haystack[0] == '\0') return 0;

  strcpy(a, haystack);

  while (needle[i] != '\0'){
    strcpy(b, &needle[i]);
    if (is_prefix(a,b)){
      return i;
    }
    i++;
  }

  return -1;
}

bool is_prefix(char haystack[], char needle[]){
  if (haystack[0] == '\0') return true;
  if (needle[0] == '\0') return false;
  if (haystack[0] != needle[0]) return false;

  return is_prefix(haystack+1, needle+1);
}

void strcpy(char target[], const char source[]){
  int i = 0;
  while (source[i] != '\0'){
    target[i] = source[i];
    i++;
  }
  target[i] = '\0';
}
