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
	ibt_2->setSpeed(IBT_2::FORWARD, 100);
	delay(5000);
	ibt_2->setSpeed(IBT_2::BACKWARD, 100);
	delay(5000);
}