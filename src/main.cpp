#include <Arduino.h>
#include "ibt_2.h"

IBT_2 *ibt_2 = nullptr;

void setup()
{
#ifdef DEBUG
	Serial.begin(115200);
#endif
	ibt_2 = new IBT_2(22, 21);
}

void loop()
{
	//ibt_2->pwm.direction = IBT_2::FORWARD;
	ibt_2->pwm.curr = 10;
	delay(5000);
	ibt_2->pwm.curr = 20;
	//ibt_2->pwm.direction = IBT_2::BACKWARD;
	delay(5000);
}