int light=A0;
int lightsensor=0;

int LED_1 = 10;
int LED_2 = 11;// Use the onboard Uno LED
int LED_3 = 8;
int LED_4 = 9;
const int isObstaclePin_1 = 5; 
const int isObstaclePin_2 = 6;
const int isObstaclePin_3 = 7;// This is our input pin
int isObstacle_1 = LOW;
int isObstacle_2 = LOW;
int isObstacle_3 = LOW;
int flag =HIGH;

// HIGH MEANS NO OBSTACLE

void setup() {
  //pinMode(LED_1, HIGH);
  //pinMode(LED_2, HIGH);
    pinMode(LED_1,OUTPUT);
      pinMode(LED_2,OUTPUT);
      
  pinMode(isObstaclePin_1, INPUT);
   pinMode(isObstaclePin_2, INPUT);
    pinMode(isObstaclePin_3, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  lightsensor=analogRead(light);
 if(lightsensor<30){
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, HIGH);
  isObstacle_1 = digitalRead(isObstaclePin_1);
  isObstacle_2 = digitalRead(isObstaclePin_2);
  isObstacle_3 = digitalRead(isObstaclePin_3);
  Serial.println(digitalRead(isObstaclePin_1));
   Serial.println(digitalRead(isObstaclePin_2));
    Serial.println(digitalRead(isObstaclePin_3));
    Serial.println(digitalRead(flag));
     if (isObstacle_1 == HIGH&& isObstacle_2 == HIGH||isObstacle_1 == HIGH&& isObstacle_3 == HIGH||isObstacle_2 == HIGH&& isObstacle_3 == HIGH)//FRONT MOVEMENT
  { //Serial.println("0");
    Serial.println("OBSTACLE_1!!, OBSTACLE!!");
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
  }
  else
  {
    
 // if (isObstacle_1 == LOW&& isObstacle_2 == LOW &&isObstacle_3 == LOW)//FRONT MOVEMENT
  //{ //Serial.println("0");
    //Serial.println(" NO OBSTACLE_1!!, OBSTACLE!!");
    //digitalWrite(LED_1, LOW);
    //digitalWrite(LED_2, LOW);
  //}
   if (isObstacle_1 == HIGH&&isObstacle_3 == LOW&&isObstacle_2 == LOW)
  {
   
    Serial.println("OBSTACLE_2!!, OBSTACLE!!");
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, HIGH);
  }
   if(isObstacle_1 == LOW&&isObstacle_3 == LOW&&isObstacle_2 == HIGH)
  {
    
     
    Serial.println("OBSTACLE_3!!, OBSTACLE!!");
     digitalWrite(LED_2, HIGH);
     digitalWrite(LED_1, LOW);
     
     
     
  }
   if (isObstacle_3 == HIGH&& isObstacle_2 == LOW&&isObstacle_2 == LOW)
  { //Serial.println("0");
    
    Serial.println("ra");
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, LOW);
  }
  
     
  }
  delay(500);
 }
   Serial.println(lightsensor);
  delay(100);
}

