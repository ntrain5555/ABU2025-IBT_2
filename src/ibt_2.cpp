#include <Arduino.h>
#include "ibt_2.h"

IBT_2::IBT_2(uint8_t pin_pwm_l, uint8_t pin_pwm_r) : pin{pin_pwm_l, pin_pwm_r}
{
	pinMode(pin.pwm_l, OUTPUT);
	pinMode(pin.pwm_r, OUTPUT);
}

void IBT_2::setSpeed(enum direction direction, uint8_t pwm)
{
#ifdef DEBUG
	Serial.printf("L: %hd, R: %hd, DIR: %s, PWM: %hd\n",
				  pin.pwm_l,
				  pin.pwm_r,
				  direction == FORWARD ? "FORWARD" : "BACKWARD",
				  pwm);
#endif
	switch (direction)
	{
	case FORWARD:
		analogWrite(pin.pwm_l, pwm);
		analogWrite(pin.pwm_r, 0);
		break;
	case BACKWARD:
		analogWrite(pin.pwm_l, 0);
		analogWrite(pin.pwm_r, pwm);
		break;
	}
}
