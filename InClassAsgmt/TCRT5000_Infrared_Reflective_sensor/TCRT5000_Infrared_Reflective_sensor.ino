
int analogPin = A5; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int val = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);  //อ่านค่าสัญญาณ analog ขา5 ที่ต่อกับ TCRT5000 
  if ((val>2600)&&(val<2800))
 { Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println("Yellow");} // พิมพ์ค่าของตัวแปร val
  else if ((val>2900)&&(val<3000))
  { Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println("Green");} // พิมพ์ค่าของตัวแปร val
  else if ((val>3000)&&(val<3300))
  { Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println("Blue");} // พิมพ์ค่าของตัวแปร val
  else
  { Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println("object not found");} // พิมพ์ค่าของตัวแปร val
  delay(1);
 
}
  
