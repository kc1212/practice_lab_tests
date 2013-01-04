#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "words.h"

void reverse(const char in[], char out[]){

  int len = strlen(in);
  int i = len-1;
  int j = 0;

  for (j = 0; j < len; j++){
    out[j] = in[i--];
  }

  out[j] = '\0';

}

bool compare(const char one[], const char two[]){

  int i1=0, i2=0;

  while (true){
    if ( (isalpha(one[i1])) || (one[i1] == '\0') ) break;
    i1++;
  }

  while (true){
    if ( (isalpha(two[i2])) || (two[i2] == '\0') ) break;
    i2++;
  }

  // if both reached the end, return true
  if ( (one[i1] == '\0') && (two[i2] == '\0')) return true;

  // if one reache EOF and the other didnt, return false
  if ( (one[i1] == '\0') || (two[i2] == '\0')) return false;

  // if there is a difference, return false
  if (toupper(one[i1]) != toupper(two[i2])) return false;

  return compare(one+i1+1, two+i2+1);
}


bool palindrome(const char sentence[]){
  char s_rev[255];
  char s[255];

  clean_string(sentence, s);
  reverse(s, s_rev);

  // if they are the same
  if (strcmp(s, s_rev) == 0){
    return true;
  }
  return false;

}

void clean_string(const char in[], char out[]){
  // if not alpha, we shift it forward
  int j = 0;
  int len = strlen(in);

  for (int i = 0; i < len; i++){
    if (isalpha(in[i])){
      out[j] = toupper(in[i]);
      j++;
    }
  }
  out[j] = '\0';
}


bool anagram(const char str1[], const char str2[]){
  char sorted1[255];
  char sorted2[255];

  strsort(str1, sorted1);
  strsort(str2, sorted2);

  if (strcmp(sorted1, sorted2) == 0){
    return true;
  }
  return false;

}

void strsort(const char in[], char out[]){
  int len;
  char tmp[255];
  clean_string(in, tmp);
  len = strlen(tmp);

  // now sort the string
  for (int i = 0; i < len; i++){
    for (int j = 1; j < len - i; j++){
      if (tmp[j-1] > tmp[j]) swap(tmp[j-1], tmp[j]);
    }
  }

  strcpy(out, tmp);
}

void swap(char &a, char &b){
  char tmp = a;
  a = b;
  b = tmp;
}
