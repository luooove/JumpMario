int sensorPin = A0;
int ledOut = 13;
int sensorValue;
unsigned long startflag, endflag, time;
volatile int state = LOW;
int jumpflag = 0;
void setup() {
  // put youri
  pinMode(ledOut, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
  attachInterrupt(1, jump, RISING); //当int.下降沿触发 改变时,触发中断函数blink //IO is 2     low
}

void loop() {
  // put your main code here, to run repeatedly:
  //Keyboard.press('d');


  if (jumpflag == 0)
  {
    if ((digitalRead(9) == 0))
    {
      Keyboard.releaseAll();
    }
    else
    {
      Keyboard.press('a');
      delay(100);
    }
    if ((digitalRead(8) == 0))
    {
      Keyboard.releaseAll();
    }
    else
    {
      Keyboard.press('d');
      delay(100);
    }
  }


  delay(10);
}

void jump()
{
  Keyboard.press('k');
  startflag =  millis();
  attachInterrupt(1, jump2, FALLING); //当int.下降沿触发 改变时,触发中断函数blink //IO is 2     lowkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
  Serial.print("up");
  jumpflag = 1;
}
void jump2()
{
  endflag =  millis();
  time = endflag - startflag;
  delay(time * 3);
  Serial.println(time);
  Keyboard.releaseAll();
  attachInterrupt(1, jump, RISING); //当int.下降沿触发 改变时,触发中断函数blink //IO is 2     lows
  Serial.print("down");
  jumpflag = 0;
}

void stateChange()
{
  state = !state;
  digitalWrite(ledOut, state);
  // Serial.println("a");
}
