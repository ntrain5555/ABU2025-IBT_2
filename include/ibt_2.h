#ifndef IBT_2_H
#define IBT_2_H
#include <unistd.h>

class IBT_2
{
	struct
	{
		uint8_t pwm_l;
		uint8_t pwm_r;
	} pin;

public:
	enum direction
	{
		FORWARD,
		BACKWARD
	};
	struct
	{
		uint8_t curr;
		enum direction direction;
	} pwm;

	IBT_2(uint8_t pin_pwm_l, uint8_t pin_pwm_r);
};

#endif