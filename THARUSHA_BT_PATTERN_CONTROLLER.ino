 /*
---------------------------------------------------------                 
*LED Pin Connectiona ----LED1----ARDUINO D2                                   
*                    ----LED2----ARDUINO D3                                   
*                    ----LED3----ARDUINO D4                                   
*                    ----LED4----ARDUINO D5                                      
*                    ----LED5----ARDUINO D6
*                    ----LED6----ARDUINO D7
*                    ----LED7----ARDUINO D8
*                    ----LED8----ARDUINO D9
*                    ----LED9----ARDUINO D10
*                    ----LED10---ARDUINO D11
*                    ----LED11---ARDUINO D12
*                    ----LED12---ARDUINO D13
*                    ----LED10---ARDUINO D11
*                    ----LED11---ARDUINO D12
*                    ----LED12---ARDUINO D13
*---------------------------------------------------------                   
*HC-05/HC-06 Pin Connection ----- 5V PIN-----ARDUINO 5V PIN
*                           ----- GND PIN----ARDUINO GND PIN
*                           ----- RX PIN-----ARDUINO D1(TX)
*                           ----- TX PIN-----ARDUINO D0(RX)
*---------------------------------------------------------
*/
int led[15] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int SoundSensor = A3;

char THARUSHA= 0;
const int threshold = 200;
const int threshold1 = 0;
int data;
int callValue=0;

void setup(){
  Serial.begin(9600);
  for (byte i = 0; i <15; i++) 
  {
    pinMode(led[i], OUTPUT);
  }
  pinMode(SoundSensor, INPUT); 
}
void loop(){
  if(Serial.available()){
    data = (int)Serial.read();
    Serial.println(data);
    if(data==10){
      //pattern 1
      callValue=1;
    }
    else if(data==11){
      //pattern 2
      callValue=2;
    }
    else if(data==12){
      //pattern 3
      callValue=3;
    }
    else if(data==13){
      //pattern 4
      callValue=4;
    }
    else if(data==14){
      //pattern 5
      callValue=5;
    }
    else if(data==15){
      //beats
      callValue=6;
    }
  }
  else{
    if(callValue==1){
      showTharushaPattern(1);
    }
    else if(callValue==2){
      showTharushaPattern(2);
    }
    else if(callValue==3){
      showTharushaPattern(3);
    }
    else if(callValue==4){
      showTharushaPattern(4);
    }
    else if(callValue==5){
      showTharushaPattern(5);
    }
    else if(callValue==6){
      showTharushaPattern(6);
    }
  }
}
void showTharushaPattern(int tha){
  if(tha == 1){
    Tharusha01(HIGH);
    Tharusha01(LOW);
  } else if(tha == 2){
    Tharusha02();
  } else if(tha == 3){
    Tharusha03(HIGH);
    Tharusha03(LOW);
  } else if(tha == 4){
    Tharusha04();
  } else if(tha == 5){
    Tharusha05();
  } else if(tha == 6){
    all_on_beats();
  }
}
/*-------------------------------------------------------------------------PATTERN NO.01--------------------------------------------------------------------*/
void Tharusha01(bool ledStatus){
  for(int i=0;i<15;i++){
    digitalWrite(led[i], ledStatus);
    Serial.println(led[i]);
    delay(100);
  }
}
/*-------------------------------------------------------------------------PATTERN NO.02--------------------------------------------------------------------*/
void Tharusha02() {
  for(int i=0;i<15;i++){
    if(i%2==0){
      digitalWrite(led[i], HIGH);
      Serial.println(led[i]);
      delay(100); 
    }
  }
  for(int i=0;i<15;i++){
    if(i%2!=0){
      digitalWrite(led[i], HIGH);
      Serial.println(led[i]);
      delay(100); 
    }
  }
  for(int i=0;i<15;i++){
    if(i%2==0){
      digitalWrite(led[i],LOW);
      Serial.println(led[i]);
      delay(100); 
    }
  }
  for(int i=0;i<15;i++){
    if(i%2!=0){
      digitalWrite(led[i], LOW);
      Serial.println(led[i]);
      delay(100); 
    }
  }
}
///*-------------------------------------------------------------------------PATTERN NO.03--------------------------------------------------------------------*/
void Tharusha03(bool ledStatus) {
  for(int i=0;i<15;i++){
    digitalWrite(led[i], ledStatus);
    Serial.println(led[i]);
    digitalWrite(16-i, ledStatus);
    Serial.println(16-i);
    delay(100); 
  }
}
///*-------------------------------------------------------------------------PATTERN NO.04--------------------------------------------------------------------*/
void Tharusha04() {
  for(int i=0;i<15;i++){
    digitalWrite(led[i], HIGH);
    Serial.println(led[i]);
    delay(50); 
  }
  for(int i=0;i<15;i++){
    digitalWrite(led[i], LOW);
    Serial.println(led[i]);
    delay(50); 
  }
  for(int i=14;i>=0;i--){
    digitalWrite(led[i], HIGH);
    Serial.println(led[i]);
    delay(50); 
  }
  for(int i=14;i>=0;i--){
    digitalWrite(led[i], LOW);
    Serial.println(led[i]);
    delay(50); 
  }
}
///*-------------------------------------------------------------------------PATTERN NO.05--------------------------------------------------------------------*/
void Tharusha05() {
  for(int i=0;i<6;i++){
    digitalWrite(led[i], HIGH);
    Serial.println(led[i]);
    delay(50);
  }
  for(int i=0;i<6;i++){
    digitalWrite(led[i], LOW);
    Serial.println(led[i]);
    delay(50);
  }
  for(int i=6;i<12;i++){
    digitalWrite(led[i], HIGH);
    Serial.println(led[i]);
    delay(50);
  }
  for(int i=6;i<12;i++){
    digitalWrite(led[i], LOW);
    Serial.println(led[i]);
    delay(50);
  }
  for(int i=12;i<15;i++){
    digitalWrite(led[i], HIGH);
    Serial.println(led[i]);
    delay(50);
  }
  for(int i=12;i<15;i++){
    digitalWrite(led[i], LOW);
    Serial.println(led[i]);
    delay(50);
  }
}
void all_on_beats(){
  int statusSensor = analogRead(SoundSensor);
  bool led_Status;
  if (statusSensor>=threshold)
  {
    led_Status=HIGH;
  }
  else
  {
    led_Status=LOW;
  }
  Serial.println(led_Status);
  for(int i=12;i<15;i++){
    digitalWrite(led[i], led_Status);
    Serial.println(led[i]);
  }
}
void one_by_one_all(){
  showTharushaPattern(1);
  delay(100);
  showTharushaPattern(2);
  delay(100);
  showTharushaPattern(3);
  delay(100);
  showTharushaPattern(4);
  delay(100);
  showTharushaPattern(5);
  delay(100);
}
