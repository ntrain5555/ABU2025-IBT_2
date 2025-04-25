#include <Arduino.h>
#include "ibt_2.h"

IBT_2::IBT_2(uint8_t pin_pwm_l, uint8_t pin_pwm_r) : pin{pin_pwm_l, pin_pwm_r},
													 pwm{0, FORWARD}
{
	pinMode(pin.pwm_l, OUTPUT);
	pinMode(pin.pwm_r, OUTPUT);
	xTaskCreatePinnedToCore([](void *param)
							{
			IBT_2 *ibt_2 = (IBT_2 *) param;
			enum IBT_2::direction direction = ibt_2->pwm.direction;
			uint8_t pwm_curr = ibt_2->pwm.curr;
			while (true) {
				if ((pwm_curr == ibt_2->pwm.curr) && (direction == ibt_2->pwm.direction)) {
					continue;
				}
				pwm_curr = ibt_2->pwm.curr;
				direction = ibt_2->pwm.direction;
#ifdef DEBUG
				Serial.printf("PWM: %hd, DIR: %s\n",
					ibt_2->pwm.curr,
					ibt_2->pwm.direction == FORWARD ? "FORWARD" : "BACKWARD"
				);
#endif
				switch (ibt_2->pwm.direction) {
					case FORWARD:
						analogWrite(ibt_2->pin.pwm_l, 255 - ibt_2->pwm.curr); // The transistor is pull up
						analogWrite(ibt_2->pin.pwm_r, 255); // The transistor is pulling down
						break;
					case BACKWARD:
						analogWrite(ibt_2->pin.pwm_l, 255); // The transistor is pulling down
						analogWrite(ibt_2->pin.pwm_r, 255 - ibt_2->pwm.curr); // The transistor is pull up
						break;
				}
			} }, "pwm Retaining", 4000, this, 1, NULL, 1);
}