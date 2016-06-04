#ifndef CustumServo_h
#define CustumServo_h

#include "Servo.h"

class CustomServo : public Servo{
public:
	void adjust(float pos){
		int degree = map(pos, 0, 200, 12, 180);

		_pos = pos;

		if(degree >= 1){
			write(degree - 1);
		}
		delay(300);
		write(degree);
	}

	void move(String ease, float dur, float pos, float delta){
		for(int t = 0; t <= dur; t++){
			float c = 0;
			int degree = 0;

			switch(ease){
				case("easeLinear"):
					c = easeLinear(t, dur, pos, delta);
					break;
				case ("easeInOutCubic"):
					c = easeInOutCubic(t, dur, pos, delta);
					break;
				default:
					c = 0;
					break;
			}

			degree = map(c, 0, 200, 12, 180);

			write(degree);
			delay(1);
		}
	}


private:
	float _pos = 0; // position: 0 to 200

	// time = current time, dur = duration, pos = starting position, delta = change of the position
	float easeInOutCubic(float time, float dur, float pos, float delta){
		time = time / (dur / 2);

		if(time < 1){
			return delta / 2 * time * time * time + pos;
		}else{
			time = time - 2;
			return delta / 2 * ((time * time * time) + 2) + pos;
		}
	}

	float easeLinear(float time, float dur, float pos, float delta){
		return delta / dur * time + pos;
	}
};

#endif
