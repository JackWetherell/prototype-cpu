#define SHIFT_DATA 2
#define SHIFT_CLOCK 3
#define SHIFT_LATCH 4
#define PROGRAM 5
#define INDICATOR 6

void setAddress(byte address)
{
  shiftOut(SHIFT_DATA, SHIFT_CLOCK, LSBFIRST, address << 4);
}

void setData(byte data)
{
  shiftOut(SHIFT_DATA, SHIFT_CLOCK, LSBFIRST, data);
}

void latch(int delay_time = 10)
{
  digitalWrite(SHIFT_LATCH, LOW);
  delay(delay_time);
  digitalWrite(SHIFT_LATCH, HIGH);
  delay(delay_time);
  digitalWrite(SHIFT_LATCH, LOW);
  delay(delay_time);
}

void program(int delay_time = 200)
{
  digitalWrite(PROGRAM, HIGH);
  delay(delay_time);
  digitalWrite(PROGRAM, LOW);
  delay(10);
  digitalWrite(PROGRAM, HIGH);
  delay(delay_time);
}

void setup()
{
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLOCK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  pinMode(PROGRAM, OUTPUT);
  pinMode(INDICATOR, OUTPUT);
  
  digitalWrite(PROGRAM, HIGH);
  digitalWrite(INDICATOR, LOW);
 
  byte data[] = {0x51, 0x4e, 0x50, 0xe0, 0x2e, 0x4f, 0x1e, 0x4d, 0x1f, 0x4e, 0x1d, 0x70, 0x63, 0x00, 0x00, 0x00};

  setAddress(0); 
  setData(0); 
  latch();
  delay(5000);
  digitalWrite(INDICATOR, HIGH);

  for (byte address = 0; address < 16; address++)
  {
    setAddress(address); 
    setData(data[address]);
    latch();
    program();
  }

  setAddress(0); 
  setData(0); 
  latch();

  digitalWrite(INDICATOR, LOW);
}

void loop()
{ 
}
