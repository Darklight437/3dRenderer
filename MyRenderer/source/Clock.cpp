#include "Clock.h"



Clock::Clock()
{
	m_createTime = m_timer.now();
	m_lastTime = m_createTime;
}






int64_t Clock::getTimeSeconds()
{
	return std::chrono::duration_cast<std::chrono::seconds>(m_timer.now() - m_createTime).count();
}

int64_t Clock::getTimeMilliseconds()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_timer.now() - m_createTime).count();
}

int64_t Clock::getTimeMicroseconds()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(m_timer.now() - m_createTime).count();
}

void Clock::resetClock()
{
	m_createTime = m_timer.now();
}

void Clock::update()
{
	m_deltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(m_timer.now() - m_lastTime).count() / 1000.0f;
	m_lastTime = m_timer.now();
}

float Clock::deltaTime()
{
	return m_deltaTime;
}

Clock& Clock::getInstance()
{

	static Clock clock;
	return clock;

}