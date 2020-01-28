int ledPin[9]={4,5,6,7,8,9,10,11,12};
int sensorValue;
int size=sizeof(ledPin)/2;
void setup()
{
  Serial.begin(9600);
  for (int i=0;i<9;i++){
    pinMode(ledPin[i], OUTPUT);
  }
   pinMode(A0,OUTPUT);    //PIN A0 set as output
    pinMode(A1,OUTPUT);   // PIN A1 set as output
    pinMode(A2,OUTPUT);   // PIN A2 set as output
  Serial.println(size);
  digitalWrite(A0,1);
  digitalWrite(A1,1);
  digitalWrite(A2,1);
}
// turns on the led on and off for the given delay`

void ledOn(int analog, int ledNum, int dNum){
  
  
  if (analog==2){
    analogWrite(A2,0);
    digitalWrite(ledPin[ledNum], 1);
    delay(dNum);
    //digitalWrite(A2,1);
    
  }
  else if (analog==1){
    analogWrite(A1,0);
    digitalWrite(ledPin[ledNum], 1);
    delay(dNum);
    //digitalWrite(A1,1);
    
  }
  
  else if (analog==0){
    analogWrite(A0,0);
    digitalWrite(ledPin[ledNum], 1);
    delay(dNum);
    //digitalWrite(A0,1);
    
  }
  delay(dNum);
  
  
}

void ledOff(int analog, int ledNum, int dNum){
  
  
  if (analog==2){
    analogWrite(A2,0);
    digitalWrite(ledPin[ledNum], 0);
    delay(dNum);
    //digitalWrite(A2,1);
    
  }
  else if (analog==1){
    analogWrite(A1,0);
    digitalWrite(ledPin[ledNum], 0);
    delay(dNum);
    //digitalWrite(A1,1);
    
  }
  
  else if (analog==0){
    analogWrite(A0,0);
    digitalWrite(ledPin[ledNum], 0);
    delay(dNum);
    //digitalWrite(A0,1);
    
  }
  
  
}



void ledOnOff(int analog, int ledNum, int dNum){
  
  
  if (analog==2){
    analogWrite(A2,0);
    digitalWrite(ledPin[ledNum], 1);
    delay(dNum);
    digitalWrite(ledPin[ledNum], 0);
    analogWrite(A2,1);
  }
  else if (analog==1){
    analogWrite(A1,0);
    digitalWrite(ledPin[ledNum], 1);
    delay(dNum);
    digitalWrite(ledPin[ledNum], 0);
    analogWrite(A1,1);
  }
  
  else if (analog==0){
    analogWrite(A0,0);
    digitalWrite(ledPin[ledNum], 1);
    delay(dNum);
    digitalWrite(ledPin[ledNum], 0);
    analogWrite(A0,1);
  }
  delay(dNum);
  
  
}

void turnLayerOff(int layer){
  Serial.println("turning layer off: "+layer);
  if (layer==0){
  digitalWrite(A0,LOW);    //layer 1 of cube is grounded
          for (int i=0;i<9;i++)
          {
              digitalWrite(ledPin[i],LOW);    //turn ON each LED one after another in layer1
              delay(100);
            //digitalWrite(i,LOW);
          }
        digitalWrite(A0,HIGH);    //layer1 is pulled up
  }
  
  if (layer==1){
  digitalWrite(A1,LOW);    //layer 1 of cube is grounded
          for (int i=0;i<9;i++)
          {
              digitalWrite(ledPin[i],LOW);    //turn ON each LED one after another in layer1
              delay(100);
           //digitalWrite(i,LOW);
          }
        digitalWrite(A1,HIGH);    //layer1 is pulled up
  }
  if (layer==2){
  digitalWrite(A2,LOW);    //layer 1 of cube is grounded
          for (int i=0;i<9;i++)
          {
              digitalWrite(ledPin[i],LOW);    //turn ON each LED one after another in layer1
              delay(100);
            //digitalWrite(i,LOW);
          }
        digitalWrite(A2,HIGH);    //layer1 is pulled up
  }
  
  }
  
void turnLayerOn(int layer){
  Serial.println("turning layer on: "+layer);
  if (layer==0){
  digitalWrite(A0,LOW);    //layer 1 of cube is grounded
          for (int i=0;i<9;i++)
          {
              digitalWrite(ledPin[i],HIGH);    //turn ON each LED one after another in layer1
              delay(100);
            //digitalWrite(i,LOW);
          }
        //digitalWrite(A0,HIGH);    //layer1 is pulled up
  }
  
  if (layer==1){
  digitalWrite(A1,LOW);    //layer 1 of cube is grounded
          for (int i=0;i<9;i++)
          {
              digitalWrite(ledPin[i],HIGH);    //turn ON each LED one after another in layer1
              delay(100);
            //digitalWrite(i,LOW);
          }
        //digitalWrite(A1,HIGH);    //layer1 is pulled up
  }
  if (layer==2){
  digitalWrite(A2,LOW);    //layer 1 of cube is grounded
          for (int i=0;i<9;i++)
          {
              digitalWrite(ledPin[i],HIGH);    //turn ON each LED one after another in layer1
              delay(100);
            //digitalWrite(i,LOW);
          }
        //digitalWrite(A2,HIGH);    //layer1 is pulled up
  }
  
  }
  
void turnAllLayersOn(){
  turnLayerOn(0);
    turnLayerOn(1);
    turnLayerOn(2);
}

void turnAllLayersOff(){
  turnLayerOff(0);
    turnLayerOff(1);
    turnLayerOff(2);
}

void groundIt(int i){
  if (i==0){
    digitalWrite(A0,0);
  }
  if (i==1){
    digitalWrite(A1,0);
  }
  if (i==2){
    digitalWrite(A2,0);
  }
}

void pullUp(int i){
  if (i==0){
    digitalWrite(A0,1);
  }
  if (i==1){
    digitalWrite(A1,1);
  }
  if (i==2){
    digitalWrite(A2,1);
  }
}

void groundEverything(){
    groundIt(0);
    groundIt(1);
    groundIt(2);
}

void pullEverything(){
    pullUp(0);
    pullUp(1);
    pullUp(2);
}

void pattern1(){ // making 2 diagnol x's
  
  for (int i=0;i<3;i++){
    ledOnOff(i,i*4,50);
    pullUp(i);
  }
  delay(500);
  for (int i=0;i<3;i++){
    ledOnOff(i,(i*2)+2,50);
    pullUp(i);
  }
  delay(500);
  /*
  for (int i=2;i>=0;i--){
    ledOff(i,i*4,1000);
  }
  */
}

void pattern2(){ //fix this
  
  for (int i=0;i<3;i++){
    ledOn(i,i*4,1000);
    pullUp(i);
  }
  delay(5000);
  for (int i=0;i<3;i++){
    ledOn(i,(i*2)+2,1000);
    pullUp(i);
  }
  delay(5000);
  /*
  for (int i=2;i>=0;i--){
    ledOff(i,i*4,1000);
  }
  */
}

void pattern3(){ //rotate
  for (int i=0;i<2;i++){
  groundEverything();
  ledOnOff(0,0,50);
    ledOnOff(0,1,50);
    ledOnOff(0,2,50);
    ledOnOff(0,5,50);
    ledOnOff(0,8,50);
    ledOnOff(0,7,50);
    ledOnOff(0,6,50);
    ledOnOff(0,3,50);
    ledOnOff(0,0,50);
    pullEverything();
  }
}

void pattern4(){ // move verrtical layers forward
  groundEverything();
    
    for(int i=0; i<=6;i=i+3){
      for(int j=0;j<=2;j++){
        ledOn(0,i+j,10);
      }
      delay(50);
      for(int k=0;k<=2;k++){
        ledOff(0,i+k,10);
      }
      delay(50);
      
    }
    pullEverything();
}

void pattern5(){ //light up everything, turn off lights to make a cross
    groundEverything();
    turnAllLayersOn();
    /*
    for(int i=1;i<=7;i=i+2){
      ledOff(1,i,100);
    }
    */
    ledOff(0,1,100);
    ledOff(0,3,100);
    ledOff(0,5,100);
    ledOff(0,7,100);
    Serial.println("all are off");
    delay(1000);
    turnAllLayersOff();
    
}

void pattern6(){
    groundEverything();
    ledOn(0,4,10);
    
    ledOn(0,1,10); //top
    ledOn(0,6,10); //corner
    ledOn(0,8,10); //corner
    delay(1000);
    ledOff(0,1,100);
    ledOff(0,8,100);
    ledOn(0,5,10);
    ledOn(0,0,10);
    ledOn(0,6,10);
    delay(1000);
    ledOff(0,5,100);
    ledOff(0,6,100);
    ledOn(0,7,10);
    ledOn(0,2,10);
    ledOn(0,0,10);
    delay(1000);
    ledOff(0,7,10);
    ledOff(0,0,10);
    ledOn(0,3,10);
    ledOn(0,8,10);
    ledOn(0,2,10);
    delay(1000);
    turnAllLayersOff();
    pullEverything();
}

void pattern8(){ //spin 2 vertical cycles
}

void pattern7(){ // make a 3d spiral
  for (int i=0;i<=2;i++){
  groundIt(i);
  ledOnOff(i,0,50);
    ledOnOff(i,1,50);
    ledOnOff(i,2,50);
    ledOnOff(i,5,50);
    ledOnOff(i,8,50);
    ledOnOff(i,7,50);
    ledOnOff(i,6,50);
    ledOnOff(i,3,50);
    pullUp(i);
  }
}

void pattern9(){ //collide vertical layers from 2 different directions

}

void loop(){
 
  digitalWrite(A0,1);
  digitalWrite(A1,1);
  digitalWrite(A2,1);
  
  
  sensorValue = analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) 
  
  int a=map(sensorValue, 0, 1023, 1, 7);
  Serial.println(a);

  switch (a) {
  case 1:
    pattern1();
    break;
  case 2:
    pattern2();
    break;
  case 3:
    pattern3();
    break;
  case 4:
    pattern4();
    break;
  case 5:
    pattern5();
    break;
  case 6:
    pattern6();
    break;
  case 7:
    pattern7();
    break;
    
  default:
    // statements
    break;
}

  
  
}
  
