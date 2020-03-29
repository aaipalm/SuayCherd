#define ia1 D12 //moter a เดินหน้า
#define ia2 D3 //moter a ถอยหลัง
#define ib1 D10 //moter b เดินหน้า
#define ib2 D9 //moter b ถอยหลัง

#define ls D4 //sensorซ้าย
#define rs D6 //sensorขวา

#define maxSpd 255    // motor max speed

#include <HCSR04.h>
HCSR04 hc(D7,D8); //initialisation class HCSR04 (trig,echo);

int analogPin = A5; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5

int led1 = D11 ; 
int buttonPin = D2;
int val=0;
int old_val=0;
int state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ls, INPUT);
  pinMode(rs, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT); 
  pinMode(ia1, OUTPUT);
  pinMode(ia2, OUTPUT);
  pinMode(ib1, OUTPUT);
  pinMode(ib2, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
 val = digitalRead(buttonPin);
 if( (val==HIGH) && (old_val==LOW)) 
 {
  state=!state;
 }
 old_val=val;
 if (state==1) //เมื่อกดสวิทซ์ 1 ครั้ง ใช้กลยุทธ์รุก
 {
  digitalWrite(led1, HIGH);
  if((hc.dist()>10)&&((digitalRead(ls)==HIGH)||(digitalRead(rs)==HIGH))&&((analogRead(analogPin)<2600)||(analogRead(analogPin)>3000)))  // เดินหน้าเมื่อ sensor ด้านหน้า ด้านข้าง และล่างไม่ทำงาน
  {
  aForward(maxSpd);
  bForward(maxSpd);
  }
  
  if((hc.dist()<10)&&((digitalRead(ls)==HIGH)||(digitalRead(rs)==HIGH))&&((analogRead(analogPin)<2600)||(analogRead(analogPin)>3000)))  // break เมื่อ sensor ด้านหน้าทำงาน แต่ด้านข้างและล่างไม่ทำงาน
  {
  aBreak();
  bBreak();
  }

  if((hc.dist()<10)&&((digitalRead(ls)==LOW)||(digitalRead(rs)==LOW))&&((analogRead(analogPin)<2600)||(analogRead(analogPin)>3000)))  // เดินถอยหลัง 3วิ เมื่อ sensor ด้านหน้าและข้างซ้ายขวาทำงาน แต่ด้านล่างไม่ทำงาน
  {
  aRewardTime(3000);
  bRewardTime(3000);
  }
  
  if((analogRead(analogPin)>2800)&&(analogRead(analogPin)<3000))  // เดินกลับรถ เมื่อ sensor ด้านล่างตรวจจับเส้นสีแดงได้
  {
  aForwardTime(5000);
  bRewardTime(5000);
  }

  if((analogRead(analogPin)>2600)&&(analogRead(analogPin)<2800))  // รถหยุด เมื่อ sensor ด้านล่างตรวจจับเส้นสีเหลืองได้
  {
  aStop();
  bStop();
  }
 }
 else
 {
  digitalWrite (led1,LOW);
  if((hc.dist()>5)&&(digitalRead(ls)==HIGH)||(digitalRead(rs)==HIGH))  // เดินหน้าเมื่อ sensor ด้านหน้าและด้านข้าง ไม่ทำงาน
  {
  aReward(maxSpd);
  bReward(maxSpd);
  }

   if((hc.dist()<5)&&(digitalRead(ls)==HIGH)||(digitalRead(rs)==HIGH)) // ถอยหลังเมื่อ sensor ด้านหลังทำงาน แต่ด้านข้างไม่ทำงาน
  {
  aForward(maxSpd);
  bForward(maxSpd);
  }
  
  if((digitalRead(ls)==LOW)||(digitalRead(rs)==LOW))  // เบรค เมื่อ sensor ด้านข้างซ้ายหรือขวาทำงาน
  {
  aBreak();
  bBreak();
  } 
    
  if((analogRead(analogPin)>3500)&&(analogRead(analogPin)<3800))  // เดินกลับรถ เมื่อ sensor ด้านล่างตรวจจับเส้นสีดำได้
  {
  aForwardTime(5000);
  bRewardTime(5000);
  }
  
  }
  delay(20);
       
}

void aStop()
{
  digitalWrite(ia1, LOW);   // motor stop
  digitalWrite(ia2, LOW);    
}

void aBreak()
{
  digitalWrite(ia1, HIGH);   // motor break
  digitalWrite(ia2, HIGH);    
}

void bStop()
{
  digitalWrite(ib1, LOW);   // motor stop
  digitalWrite(ib2, LOW);    
}

void bBreak()
{
  digitalWrite(ib1, HIGH);   // motor break
  digitalWrite(ib2, HIGH);    
}

void aForward(int speed)
{
  digitalWrite(ia2, LOW);   
  analogWrite(ia1, speed);   
}

void bForward(int speed)
{
  digitalWrite(ib2, LOW);   
  analogWrite(ib1, speed);   
}

void aReward(int speed)
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, speed);   
}

void bReward(int speed)
{
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, speed);   
}

void aRewardTime(int time)
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, maxSpd);
  delay (time);   
}

void bRewardTime(int time)
{
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, maxSpd);
  delay (time);    
}

void aForwardTime(int time)
{
  digitalWrite(ia2, LOW);   
  analogWrite(ia1, maxSpd);
  delay (time);    
}

void bForwardTime(int time)
{
  digitalWrite(ib2, LOW);   
  analogWrite(ib1, maxSpd);
  delay (time);    
}
