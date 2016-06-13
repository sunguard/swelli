#include "Arduino.h"
#include "CustomServo.h"
#include "CustomButton.h"

CustomServo motor;
CustomButton sensor(A0);

void setup()
{
	Serial.begin(9600);
	Serial.print("STARTING ARDUINO SERIAL");

	motor.attach(9);
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

	int time = 1750;
	int top = 200;
	int bottom = 10;

	motor.move("easeInOutCubic", time, motor.current(), top);
	motor.move("easeInOutCubic", time, top, bottom);

	motor.adjust(0);
}

void secondAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("Second Action Called : ");
	Serial.println(count);

	int time = 200;
	int top = 180;
	int bottom = 120;

	motor.move("easeInOutCubic", time, motor.current(), top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", time, bottom, top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", time, bottom, top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", time, bottom, top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", 800, bottom, 0);

	motor.adjust(0);
}

void thirdAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("Third Action Called : ");
	Serial.println(count);

	int time = 600;
	int top = 120;
	int bottom = 40;

	motor.move("easeInOutCubic", time, motor.current(), top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", time, bottom, top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", time, bottom, top);
	motor.move("easeInOutCubic", time, top, bottom);
	motor.move("easeInOutCubic", 800, bottom, 0);

	motor.adjust(0);
}
