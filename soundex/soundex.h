void encode(const char name[], char* soundex);
bool is_from_group(const char list[], const char c);
int get_soundex_code(const char c);
bool compare(const char one[], const char two[]);
int count(const char name[], const char sentence[]);
int get_first_word(char word[], char sentence[]);

const char LIST1[] = "bfpv";
const char LIST2[] = "cgjkqsxz";
const char LIST3[] = "dt";
const char LIST4[] = "l";
const char LIST5[] = "mn";
const char LIST6[] = "r";

