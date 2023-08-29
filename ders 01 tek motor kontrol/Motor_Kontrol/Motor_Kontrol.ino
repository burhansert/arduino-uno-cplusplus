const int in3Pin=6;
const int in4Pin=7;

const int enableB=3;

//hızı buradan değiştirebilirsiniz
//hız 0 ile 255 arası değer alabilir
const int hiz=255;

void setup() {
  pinMode(in3Pin,OUTPUT);
  pinMode(in4Pin,OUTPUT);

  pinMode(enableB,OUTPUT);
}

void loop() {
analogWrite(enableB , hiz);

digitalWrite(in3Pin,LOW);
digitalWrite(in4Pin,HIGH);
}
