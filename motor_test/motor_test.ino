


#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_A(1);
AF_DCMotor motor_F(2);              
AF_DCMotor motor_B(3); 
AF_DCMotor motor_C(4); 



void forward_or_back(float vel){
  if(vel == 0){
    motor_F.setSpeed(vel);              
    motor_F.run(RELEASE);
    motor_B.setSpeed(vel);                 
    motor_B.run(RELEASE);
  }
  else if (vel > 0){
    motor_F.setSpeed(vel);              
    motor_F.run(FORWARD);
    motor_B.setSpeed(vel);                 
    motor_B.run(FORWARD);
  }

  else if (vel < 0){
    motor_F.setSpeed(-vel);              
    motor_F.run(BACKWARD);
    motor_B.setSpeed(-vel);                 
    motor_B.run(BACKWARD);
  }
  
}




void setup(){

  motor_A.run(RELEASE);
  motor_F.run(RELEASE);
  motor_B.run(RELEASE);
}

void loop(){
  int vel=255;

  motor_A.setSpeed(vel);
  motor_F.setSpeed(vel);
  motor_B.setSpeed(vel);
  motor_C.setSpeed(vel);


  motor_A.run(FORWARD);
  delay(1000);   
  motor_A.run(BACKWARD);
  delay(1000);
  motor_A.run(RELEASE);
  delay(1000);

  motor_F.run(FORWARD);
  delay(1000);   
  motor_F.run(BACKWARD);
  delay(1000);
  motor_F.run(RELEASE);
  delay(1000);


  motor_B.run(FORWARD);
  delay(1000);   
  motor_B.run(BACKWARD);
  delay(1000);
  motor_B.run(RELEASE);
  delay(1000);

  motor_C.run(FORWARD);
  delay(1000);   
  motor_C.run(BACKWARD);
  delay(1000);
  motor_C.run(RELEASE);
  delay(1000);
  
  
}
