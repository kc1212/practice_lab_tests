#include <iostream>
#include <cstring>

using namespace std;

#include "correct.h"

int decode(const char rec[], char decoded[]){
  int i, j, len, err_count;

  err_count = 0;
  len = strlen(rec);

  for (j = 0, i = 0; i < len-6; i+=7, j+=4){
    if (decode_four_bits(rec+i, decoded+j)){
      err_count++;
    }
  }

  return err_count;

}

bool decode_four_bits(const char rec[], char decoded[]){

  int error_bit;
  int error_pos;
  char p[3];

  p[0] = parity(rec[3], rec[4], rec[5], rec[6]);
  p[1] = parity(rec[1], rec[2], rec[5], rec[6]);
  p[2] = parity(rec[0], rec[2], rec[4], rec[6]);
  p[3] = '\0';

  decoded[0] = rec[2];
  decoded[1] = rec[4];
  decoded[2] = rec[5];
  decoded[3] = rec[6];
  decoded[4]  = '\0';


  if (strcmp(p, "000")){
    error_pos = binary_to_int(p) - 1;
    error_bit = rec[error_pos];

    switch (error_pos){
      case 2: 
        decoded[0] = (error_bit == '0') ? '1' : '0';
        break;
      case 4:
      case 5:
      case 6:
        decoded[error_pos - 3] = (error_bit == '0') ? '1' : '0';
        break;
      default:
        cerr << "decoding error at error_pos: " << error_pos << endl;
    }
    return true;
  }
  return false;
}

int binary_to_int(const char* binary){
  int sum = 0;
  if (binary[2] == '1') sum+=1;
  if (binary[1] == '1') sum+=2;
  if (binary[0] == '1') sum+=4;
  return sum;
}

void add_error_correction(const char data[], char correct[]){
  int i, j;
  int len = strlen(data);

  if ((strlen(data) < 4) || (strlen(data) % 4)) {
    cerr << "bad input in binary_to_text!" << endl;
    return;
  } 

  for (j = 0, i = 0; i < len; i+=4){
    encode_four_bit(data+i, correct+j);
    j+=7;
  }
}

void encode_four_bit(const char data[], char correct[]){
  correct[0] = parity(data[0], data[1], data[3]);
  correct[1] = parity(data[0], data[2], data[3]);
  correct[2] = data[0];
  correct[3] = parity(data[1], data[2], data[3]);
  correct[4] = data[1];
  correct[5] = data[2];
  correct[6] = data[3];
  correct[7] = '\0';
}

char parity(const char d1, const char d2, const char d3){
  if ( ((d1-'0')+(d2-'0')+(d3-'0')) % 2 )
    return '1';
  return '0';
}

char parity(const char b1, const char b2, const char b3, const char b4){
  if ( ((b1-'0')+(b2-'0')+(b3-'0')+(b4-'0')) % 2 )
    return '1';
  return '0';

}

void text_to_binary(const char text[], char* binary){

  if (!text[0]) return;
  ascii_to_binary(text[0], binary);
  text_to_binary(text+1, binary+8);
}

void binary_to_text(const char binary[], char text[]){

  // check for sentinel character
  if (!binary[0]) {
    text[0] = '\0';
    return;
  }

  // check for bad input
  if ((strlen(binary) < 8) || (strlen(binary) % 8)) {
    cerr << "bad input in binary_to_text!" << endl;
    return;
  }

  // do the work
  text[0] = binary_to_ascii(binary);
  binary_to_text(binary+8, text+1);
}

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(const char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1) 
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(const char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */
