#ifndef CustumButton_h
#define CustumButton_h

#include "Arduino.h"

class CustomButton{
public:
	void (*firstAction)(){};
	void (*secondAction)(){};
	void (*thirdAction)(){};

	CustomButton(int _pin){
		pin = _pin;
	}

	int checker(){
		static unsigned long s_timestamp = 0;
		static short count = 0;
		static short test = 0;

		short output = 0;
		unsigned long c_timestamp = millis();

		if(s_timestamp == 0){
			if(counter()){
				count++;
				s_timestamp = c_timestamp;
			}
		}else{
			if(c_timestamp - s_timestamp < 300){
				if(counter() && count < 3){
					count++;
					s_timestamp = c_timestamp;
				}
			}else{
				output = count;
				count = 0;
				s_timestamp = 0;

				return output;
			}
		}

		return -1;
	}

	void binder(){
		int mode = checker();

		if(mode > 0){
			if(mode == 1){
				firstAction();
			}else if(mode == 2){
				secondAction();
			}else if(mode == 3){
				thirdAction();
			}
		}
	}

private:
	int val = 0;
	int pin = 0;

	boolean counter(){
		static boolean trigger = false;
		static boolean pressed = false;

		val = analogRead(pin);
		//Serial.println(val);

		// sensing motions
		if(!pressed){
			if(!trigger){
				if(val/10 <= 5){
					trigger = true;
				}
			}else{
				if(val/10 > 6){
					pressed = true;
				}
			}
		}

		// firing actions
		if(pressed){
			trigger = false;
			pressed = false;


			return true;
		}else{
			return false;
		}
	}
};

#endif
