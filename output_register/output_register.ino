#define SHIFT_DATA 2
#define SHIFT_CLOCK 3
#define SHIFT_LATCH 4

void setAddress(int address, bool output_enable)
{
  shiftOut(SHIFT_DATA, SHIFT_CLOCK, MSBFIRST, (address >> 8) | (output_enable ? 0x00 : 0x80));
  shiftOut(SHIFT_DATA, SHIFT_CLOCK, MSBFIRST, address);
  
  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void setup()
{
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLOCK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);

  setAddress(1234, false);
}

void loop()
{

}
