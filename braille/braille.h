int encode_character(const char ch, char braille[]);
void encode(const char text[], char braille[]);
void print_braille(const char text[], ostream& out);

const char ALPHA[][26] = {
  "0.....", "00....", "0..0..", "0..00.", "0...0.", "00.0..", "00.00.",
  "00..0.", ".0.0..", ".0.00.", "0.0...", "000...", "0.00..", "0.000.",
  "0.0.0.", "0000..", "00000.", "000.0.", ".000..", ".0000.", "0.0..0",
  "000..0", ".0.000", "0.00.0", "0.0000", "0.0.00"
};

const char NUM[][10] = {
  ".0.00.", "0.....", "00....", "0..0..", "0..00.", "0...0.", "00.0..",
  "00.00.", "00..0.", ".0.0.."
};

const char UPPER[] = ".....0";
const char NUM_SIGN[] = "..0000";
const char PERIOD[] = ".0..00";
const char COMMA[] = ".0....";
const char SEMICOLON[] = ".00...";
const char HYPHEN[] = "..0..0";
const char EXCLAMATION[] = ".00.0.";
const char QUESTION[] = ".00..0";
const char PARAN[] = ".00.00";
const char NOTFOUND[] = "......";

