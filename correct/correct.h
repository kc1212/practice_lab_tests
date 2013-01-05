#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(char *binary);

void text_to_binary(const char text[], char* binary);
void binary_to_text(char binary[], char text[]);
void add_error_correction(const char data[], char correct[]);
void encode_four_bit(const char data[], char correct[]);
char parity(const char d1, const char d2, const char d3);
char parity(const char b1, const char b2, const char b3, const char b4);
int decode(const char received[], char decoded[]);
bool decode_four_bits(const char in[], char decoded[]);
int binary_to_int(const char* binary);

#endif
