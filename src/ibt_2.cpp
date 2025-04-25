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
					vTaskDelay(5 / portTICK_PERIOD_MS);
					continue;
				}
				pwm_curr = ibt_2->pwm.curr;
				direction = ibt_2->pwm.direction;
#ifdef DEBUG
				Serial.printf("DIR: %s, PWM: %hd\n",
					ibt_2->pwm.direction == FORWARD ? "FORWARD" : "BACKWARD",
					ibt_2->pwm.curr
				);
#endif
				switch (ibt_2->pwm.direction) {
					case FORWARD:
						analogWrite(ibt_2->pin.pwm_l, ibt_2->pwm.curr);
						analogWrite(ibt_2->pin.pwm_r, 0);
						break;
					case BACKWARD:
						analogWrite(ibt_2->pin.pwm_l, 0);
						analogWrite(ibt_2->pin.pwm_r, ibt_2->pwm.curr);
						break;
				}
				vTaskDelay(5 / portTICK_PERIOD_MS);
			} }, "PWM Retaining", 2000, this, 1, NULL, 1);
}