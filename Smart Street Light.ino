int ldr =A0;
int ir1 = 2;int ir2 = 3; int ir3=4;
int led1=9;
int led2 = 10;
int led3 = 11;
void setup() 
{ 
Serial.print(9600);
pinMode(ldr,INPUT);
pinMode(ir1, INPUT);
pinMode(ir2, INPUT);
pinMode(ir3, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
}
void loop(){
int ldr_val = analogRead(ldr);
Serial.print(ldr_val);
int ir1val=digitalRead(ir1);
int ir2val=digitalRead(ir2);
int ir3val=digitalRead(ir3);
if(ldr_val<=450) {
  if( ir1val==LOW&&ir2val==LOW && ir3val==LOW){
    analogWrite(led2,255);
    analogWrite(led1,255);
    analogWrite(led3,255);
    }
 else if(ir1val==HIGH&&ir2val==LOW&&ir3val==LOW){
    analogWrite(led1,70);
    analogWrite(led2,255);
    analogWrite(led3,255);
    }
  else if(ir1val==LOW&&ir2val==HIGH&&ir3val==LOW){
    analogWrite(led1,255);
    analogWrite(led2,70);
    analogWrite(led3,255);
     }
  else if(ir1val==LOW&&ir2val==LOW&&ir3val==HIGH){
    analogWrite(led1,255);
    analogWrite(led2,255);
    analogWrite(led3,70);
    }
    else if(ir1val==HIGH&&ir2val==HIGH&&ir3val==LOW){
    analogWrite(led1,70);
    analogWrite(led2,70);
    analogWrite(led3,255);
    }
  else if(ir1val==LOW&&ir2val==HIGH&&ir3val==HIGH){
    analogWrite(led1,255);
    analogWrite(led2,70);
    analogWrite(led3,70);
     }
  else if(ir1val==HIGH&&ir2val==LOW&&ir3val==HIGH){
    analogWrite(led1,70);
    analogWrite(led2,255);
    analogWrite(led3,70);
    }
     else if(ir1val==HIGH&&ir2val==HIGH&&ir3val==HIGH){
    analogWrite(led1,70);
    analogWrite(led2,70);
    analogWrite(led3,70);
    }

else {
    analogWrite(led1,0);
    analogWrite(led2,0);
    analogWrite(led3,0);
}
}
}
