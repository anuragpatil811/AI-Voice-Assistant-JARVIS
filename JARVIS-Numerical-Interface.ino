const int a = D3;
const int b = D8;
const int c = D4;
const int d = D7;
const int e = D2;
const int f = D1;
const int g = D6;

void setup() {
  Serial.begin(9600);
  int segments[] = {a, b, c, d, e, f, g};
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], HIGH); // Off by default for common anode
  }
}

void displayDigit(int digit) {
  // Common anode: LOW turns on segment
  byte numbers[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 1, 0, 0}  // 9
  };

  digitalWrite(a, numbers[digit][0]);
  digitalWrite(b, numbers[digit][1]);
  digitalWrite(c, numbers[digit][2]);
  digitalWrite(d, numbers[digit][3]);
  digitalWrite(e, numbers[digit][4]);
  digitalWrite(f, numbers[digit][5]);
  digitalWrite(g, numbers[digit][6]);
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '9') {
      displayDigit(ch - '0');
    }
  }
}
