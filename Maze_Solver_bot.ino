void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(9600);   //begins communication between HC-05 and Arduino uno
  Serial.begin(9600);      //begins serial communication with baud rate 9600
  pinMode(10, OUTPUT);     //sets the Pins 10, 11, 12, 13 as OUTPUT Pins
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(2, INPUT);     //sets the Pins 2, 3, 4 as INPUT Pins
  pinMode(3, INPUT);
  pinMode(4, INPUT);

}

void moveRobot(String motion) 
{
  if(motion == "Forward")      // Right wheel - Fwd(10 - Positive, 11 - Negative); Left Wheel - Fwd(12 - Positive, 13 - Negative)
  {  
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.println("Forward");
  }
  
   if(motion == "Backward")    // RW - Bck(10 - Neg, 11 - Pos); LW - Bck(12 - Neg, 13 - Pos)
   {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.println("Backward");
  } 
  
  if(motion == "Left")     // RW - Fwd(10 - Pos, 11 - Neg); LW - Bck(12 - Neg, 13 - Pos)
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.println("Left");
  }
     
  if(motion == "Right")   // RW - Bck(10 - Neg, 11 - Pos); LW - Fwd(12 - Pos, 13 - Neg)
  {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.println("Right");
  }
     
  if(motion == "Stop")    // RW - Stop(10 - Neg, 11 - Neg); LW - Stop(12 - Neg, 13 - Neg)
  {
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    Serial.println("Stop");
  }
}

void turnleft(){
  Serial.println("turnleft");
  int M_temp = 1; //Temporary Middle Sensor Variable assigned to 1

while(M_temp !=0){
  moveRobot("Left");
  delay(100);
  moveRobot("Stop");
  delay(100);

  M_temp = digitalRead(3);   //Assign the Middle Sensor Value to M_temp
}
  
} 
void turnright(){
  Serial.println("turnleft");
  int L_temp = 1; //Temporary Left Sensor Variable assigned to 1

while(L_temp !=0){
  moveRobot("Right");
  delay(100);
  moveRobot("Stop");
  delay(100);

  M_temp = digitalRead(2);   //Assign the Left Sensor Value to M_temp
}
  
} 

void loop() {
  int L = digitalRead(2);
  int M = digitalRead(3);
  int R = digitalRead(4);

  if ((L==0) && (M==0) && (R==1)){ //Left T Segment identified - Turn Left
    turnleft();
  }
   if ((L==0) && (M==1) && (R==0)){ //Vertical T Segment identified - Turn Left
    turnleft();
  }
   if ((L==0) && (M==1) && (R==1)){ //Left T Turn identified - Turn Left
    turnleft();
  }
   if ((L==1) && (M==0) && (R==0)){ //Right T Segment identified - Move Forward
    moveRobot("Forward");
     delay(100);
     moveRobot("Stop");
     delay(100);
  }
   if ((L==1) && (M==0) && (R==1)){ //Straight Line identified - Move Forward
    moveRobot("Forward");
     delay(100);
     moveRobot("Stop");
     delay(100);
  }
  if ((L==1) && (M==1) && (R==0)){ //Right Turn identified - Turn Right
    moveRobot("Forward");
     delay(100);
     moveRobot("Stop");
     delay(100);
    turnright();
  }
  if ((L==1) && (M==1) && (R==1)){ //Dead End - Turn Back
    moveRobot("Forward");
    delay(100);
    moveRobot("Stop");
    delay(200);

    int L_temp = digitalRead(2);
    int M_temp = digitalRead(3);
    int R_temp = digitalRead(4);

    if ((L_temp == 1) && (M_temp == 1) && (R_temp == 1){
      turnleft();
    }
  }
  if ((L==0) && (M==0) && (R==0)){ //4 way intersection
    moveRobot("Forward");
    delay(100);
    moveRobot("Stop");
    delay(200);

    int L_temp = digitalRead(2);
    int M_temp = digitalRead(3);
    int R_temp = digitalRead(4);

    if ((L_temp == 0) && (M_temp == 0) && (R_temp == 0){
      moveRobot("Stop");
      exit(0);
    }
    else{
      turnleft();
    }
  }

}
