#define rf 5
#define rb 3
#define lf 10
#define lb 11
void setup() {
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  //pinMode(3, OUTPUT);  
  Serial.begin(9600);
}
void forward(){
  analogWrite(rf,255);
  analogWrite(rb,0);
  analogWrite(lf,255);
  analogWrite(lb,0);
}
void sright(){
  analogWrite(rf,128);
  analogWrite(rb,0);
  analogWrite(lf,255);
  analogWrite(lb,0);
  }
void sleft(){
  analogWrite(rf,255);
  analogWrite(rb,0);
  analogWrite(lf,128);
  analogWrite(lb,0);
  }
void hright(){
  analogWrite(rf,0);
  analogWrite(rb,0);
  analogWrite(lf,255);
  analogWrite(lb,0);
}
void hleft(){
  analogWrite(rf,0);
  analogWrite(rb,0);
  analogWrite(lf,0);
  analogWrite(lb,255);
}
void stop(){
  analogWrite(rf,0);
  analogWrite(rb,0);
  analogWrite(lf,0);
  analogWrite(lb,0);
}
void loop() {
  digitalWrite(2, HIGH);
  int rms0 = analogRead(A0); //Right most sensor
  int rs0 = analogRead(A1); //right sensor
  int fs0 = analogRead(A2); //forward sensor
  int ls0 = analogRead(A3); //left sensor
  int lms0 = analogRead(A4);//left most sensor
  int rms = rms0<400 ? 1:0;
  int rs = rs0<400 ? 1:0;
  int fs = fs0<400 ? 1:0;
  int ls = ls0<400 ? 1:0;
  int lms = lms0<400 ? 1:0;
  
  if(rms == 1 && rs == 1 && fs == 1 && ls == 1 && lms == 1)
  {
    stop();
  }
  else if((rms == 1 && rs == 1 && fs == 1 && ls == 0 && lms == 0) || (rms == 1 && rs == 1 && fs == 0 && ls == 0 && lms == 0) || (rms == 1 && rs == 0 && fs == 0 && ls == 0 && lms == 0))
  {
     hright();
  }
  else if((rms == 0 && rs == 0 && fs == 1 && ls == 1 && lms == 1) || (rms == 0 && rs == 0 && fs == 0 && ls == 1 && lms == 1) || (rms == 0 && rs == 0 && fs == 0 && ls == 0 && lms == 1))
  {
    hleft();  
  }
  else if((rms == 0 && rs == 1 && fs == 1 && ls == 0 && lms == 0) || (rms == 0 && rs == 1 && fs == 0 && ls == 0 && lms == 0))
  {
    sright();  
  }
  else if((rms == 0 && rs == 0 && fs == 1 && ls == 1 && lms == 0) || (rms == 0 && rs == 0 && fs == 0 && ls == 1 && lms == 0))
  {
    sleft();
  }
  else if((rms == 0 && rs == 1 && fs == 1 && ls == 1 && lms == 0) || (rms == 0 && rs == 0 && fs == 1 && ls == 0 && lms == 0))
  {
    forward();
  }
}
