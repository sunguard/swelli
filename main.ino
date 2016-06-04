#include "Arduino.h"
#include "CustomServo.h"
#include "CustomButton.h"

CustomServo motor;
CustomButton sensor(A0);

void setup()
{
	Serial.begin(9600);
	Serial.print("STARTING ARDUINO SERIAL");

	motor.attach(10);
	motor.adjust(0);
}

void loop()
{
	sensor.firstAction = firstAction;
	sensor.secondAction = secondAction;
	sensor.thirdAction = thirdAction;

	sensor.binder();
}

//void move(String ease, float dur, float delta)

void firstAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("First Action Called___ : ");
	Serial.println(count);

	motor.move("easeInOutCubic", 500, motor.current(), 200);

	for(int i = 0; i < 4; i++){
	}
	motor.move("easeInOutCubic", 500, 200, 50);
	motor.move("easeInOutCubic", 1000, 50, 200);
	motor.move("easeInOutCubic", 2000, 200, 100);
	motor.adjust(0);
}

void secondAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("Second Action Called : ");
	Serial.println(count);
}

void thirdAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("Third Action Called : ");
	Serial.println(count);
}
