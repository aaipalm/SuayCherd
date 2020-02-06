const int Sensor=D2;
int inputVal = 0;
void setup() 
{                
  pinMode(Sensor,INPUT);    
  Serial.begin(9600);
}

void loop() 
{  
   if(digitalRead(Sensor)==HIGH)
{

Serial.println("sensor not detected object"" ");
delay(200);    // wait for a second
}
else 
{
Serial.println("sensor detected object");

}
}
//จากการทดลองวัตถุต่างๆ 5 ชนิดได้ผลการทดลองดังต่อไปนี้
// 1.หนังสือสีส้ม จับได้ในระยะ 12 ซม.
// 2.เครื่องคิดเลขสีดำ จับได้ในระยะ 4.5 ซม.
// 3.กล่องสีเหลือง จับได้ในระยะ 13 ซม.
// 4.สมุดสีน้ำเงิน จับได้ในระยะ 14 ซม.
// 5.โพสอิทสีชมพูอ่อน จับได้ในระยะ 15 ซม.
// สรุปได้ว่า จากการทดลองพบว่าวัตถุอื่นๆจะจับได้ในระยะใกล้กว่า 15 ซม.เพราะกระดาษสีขาวสะท้อนแสงได้ดีกว่า 
