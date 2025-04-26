#include <Arduino.h>
#include "ibt_2.h"

IBT_2 *m_fl = nullptr;
IBT_2 *m_fr = nullptr;
IBT_2 *m_bl = nullptr;
IBT_2 *m_br = nullptr;

void setup()
{
#ifdef DEBUG
	Serial.begin(115200);
#endif
	m_fl = new IBT_2(21, 19);
	m_fr = new IBT_2(14, 13);
	m_bl = new IBT_2(23, 22);
	m_br = new IBT_2(32, 33);
}

void loop()
{
	m_fl->setSpeed(IBT_2::FORWARD, 100);
	m_fr->setSpeed(IBT_2::FORWARD, 100);
	m_bl->setSpeed(IBT_2::FORWARD, 100);
	m_br->setSpeed(IBT_2::FORWARD, 100);
	delay(1000);
	m_fl->setSpeed(IBT_2::FORWARD, 200);
	m_fr->setSpeed(IBT_2::FORWARD, 200);
	m_bl->setSpeed(IBT_2::FORWARD, 200);
	m_br->setSpeed(IBT_2::FORWARD, 200);
	delay(1000);
}
