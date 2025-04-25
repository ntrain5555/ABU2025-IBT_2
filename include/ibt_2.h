#ifndef IBT_2_H
#define IBT_2_H
#include <unistd.h>

class IBT_2
{
public:
	enum direction
	{
		FORWARD,
		BACKWARD
	};

private:
	struct
	{
		uint8_t pwm_l;
		uint8_t pwm_r;
	} pin;

public:
	IBT_2(uint8_t pin_pwm_l, uint8_t pin_pwm_r);
	void setSpeed(enum direction direction, uint8_t speed);
};

#endif