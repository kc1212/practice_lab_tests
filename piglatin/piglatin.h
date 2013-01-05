int findFirstVowel(const char word[]);
bool isVowel(const char ch);
void translateWord(const char english[], char piglatin[]);
bool initialCapital(const char word[]);
void translateStream(std::istream& input, std::ostream& output);

const char VOWELS[] = "aeiouy";