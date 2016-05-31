#ifndef CustumServo_h
#define CustumServo_h

#include "Servo.h"

class CustomServo : public Servo{
public:
	int init = 0;

	void move(int degree){
		_degree = degree;

		if(degree >= 1){
			write(degree - 1);
		}
		delay(300);
		write(degree);
	}

	void orig(){
		easeLinear(200, init);
	}

	void easeLinear(float time, float pos){
		float s_degree = _degree;
		float e_degree = map(pos, 1, 100, 12, 180);
		float delta = (e_degree - s_degree) / time;

		for(int i = 0; i < time; i++){
			write(s_degree + delta * (float(i) + 1));
			delay(1);
		}

		_degree = e_degree;
	}

private:
	int _degree = 0;
};

#endif
