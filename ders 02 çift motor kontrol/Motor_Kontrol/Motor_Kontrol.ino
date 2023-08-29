const int in1Pin=8;
const int in2Pin=9;
const int enableA=11;

const int in3Pin=6;
const int in4Pin=7;
const int enableB=3;

//hızı buradan değiştirebilirsiniz
//hız 0 ile 255 arası değer alabilir
const int hiz=50;

void setup() {
  pinMode(in1Pin,OUTPUT);
  pinMode(in2Pin,OUTPUT);
  pinMode(enableA,OUTPUT);
  
  pinMode(in3Pin,OUTPUT);
  pinMode(in4Pin,OUTPUT);
  pinMode(enableB,OUTPUT);
}

void loop() {
analogWrite(enableA , hiz);
digitalWrite(in1Pin,LOW);
digitalWrite(in2Pin,HIGH);

analogWrite(enableB , hiz);
digitalWrite(in3Pin,LOW);
digitalWrite(in4Pin,HIGH);
}
