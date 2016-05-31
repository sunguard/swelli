#include "Arduino.h"
#include "CustomServo.h"
#include "CustomButton.h"

CustomServo motor;
CustomButton sensor(A0);

int degree = 0; // MINIMUM = 12, MAXIMUM = 180

void setup()
{
	Serial.begin(9600);

	motor.attach(9);
	motor.move(12);
	motor.init = 12;
}

void loop()
{
	sensor.firstAction = firstAction;
	sensor.secondAction = secondAction;
	sensor.thirdAction = thirdAction;

	sensor.binder();

}

void firstAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("First Action Called : ");
	Serial.println(count);

	motor.easeLinear(300, 100);
	motor.easeLinear(300, 1);
	motor.easeLinear(300, 100);
	motor.easeLinear(300, 1);
	motor.easeLinear(300, 100);

	motor.orig();

}

void secondAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("Second Action Called : ");
	Serial.println(count);

	motor.easeLinear(300, 70);
	motor.easeLinear(300, 30);
	motor.easeLinear(300, 70);
	motor.easeLinear(300, 30);
	motor.easeLinear(300, 70);
	motor.easeLinear(300, 30);
	motor.easeLinear(300, 70);

	motor.orig();
}

void thirdAction(){
	static unsigned int count = 0;

	count++;
	Serial.print("Third Action Called : ");
	Serial.println(count);

	motor.easeLinear(300, 100);
	motor.easeLinear(300, 60);
	motor.easeLinear(300, 100);
	motor.easeLinear(300, 60);
	motor.easeLinear(300, 100);
	motor.easeLinear(300, 60);
	motor.easeLinear(300, 100);
	motor.easeLinear(300, 60);
	motor.easeLinear(300, 100);

	motor.orig();
}
