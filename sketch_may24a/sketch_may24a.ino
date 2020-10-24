#include <Wire.h>
#include<I2Cdev.h>
#include<MPU6050.h>
#include<Servo.h>

 Servo ss;
MPU6050 mpu;
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 


void setup(){
 Serial.begin(9600);
 Serial.println("Initialize MPU");
 mpu.initialize();
ss.attach(6);
 
}
 
void loop(){
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 
 ax = map(ax, -17000, 17000, -1500, 1500);
 int val =map(ax,-1500,1500,0,180);
ss.write(val);
Serial.println(val);
delay(100);
}

 
