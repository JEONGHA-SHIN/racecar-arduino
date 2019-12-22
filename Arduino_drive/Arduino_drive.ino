/* Arduino DC Control for 2019 UNIST STEM CAMP
 * @Copyright: Jeongha Shin
 */



#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <racecar_ws/drive_msg.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_A(1);
AF_DCMotor motor_F(2);              
AF_DCMotor motor_B(3); 

ros::NodeHandle  nh;

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

void drive_cb(const racecar_ws::drive_msg &cmd_drive){
  
  float Angle = cmd_drive.drive_angle;
  float Velocity = cmd_drive.velocity;
    
    if(Angle == 0) //forward
    {
      motor_A.run(RELEASE); 
    }
    else if(Angle > 0)
    {
      motor_A.setSpeed(Angle);
      motor_A.run(FORWARD);                  
    }
    else
    {
      motor_A.setSpeed(-Angle);
      motor_A.run(BACKWARD);                  
    }
    forward_or_back(Velocity); 
    delay(0.1);  
}


ros::Subscriber<racecar_ws::drive_msg> sub("/mux_out", drive_cb);

void setup(){
  
  nh.initNode();
  nh.subscribe(sub);

  motor_A.run(RELEASE);
  motor_F.run(RELEASE);
  motor_B.run(RELEASE);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
