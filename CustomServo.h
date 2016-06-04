#ifndef CustumServo_h
#define CustumServo_h

#include "Servo.h"

class CustomServo : public Servo{
public:
	int degree(){
		return read();
	}

	int current(){
		return map(read(), 10, 180, 0, 200);
	}

	void adjust(float pos){
		int degree = map(pos, 0, 200, 10, 180);

		_pos = pos;

		if(degree >= 5){
			write(degree - 5);
		}

		delay(300);
		write(degree);
	}

	void move(String ease, float dur, float s_pos, float e_pos){
		unsigned long s_time = millis();
		unsigned long e_time = s_time + dur;

		while(1){
			unsigned long c_time = millis();

			if(c_time <= e_time){
				int t = c_time - s_time;
				int degree = 0;
				float c = 0;

				if(ease == "easeLinear"){
					c = easeLinear(t, dur, s_pos, e_pos);
				}else if(ease == "easeInOutCubic"){
					c = easeInOutCubic(t, dur, s_pos, e_pos);
				}else{
					c = 0;
				}

				degree = map(c, 0, 200, 10, 180);

				write(degree);
			}else{
				break;
			}
		}

		active = false;
	}

private:
	float _pos = 0; // position: 0 to 200
	boolean active = false;

	float easeInOutCubic(float time, float dur, float s_pos, float e_pos){
		float delta = e_pos - s_pos;

		time = time / (dur / 2);

		if(time < 1){
			return delta / 2 * time * time * time + s_pos;
		}else{
			time = time - 2;
			return delta / 2 * ((time * time * time) + 2) + s_pos;
		}
	}

	float easeLinear(float time, float dur, float s_pos, float e_pos){
		float delta = e_pos - s_pos;

		return delta / dur * time + s_pos;
	}
};

#endif
