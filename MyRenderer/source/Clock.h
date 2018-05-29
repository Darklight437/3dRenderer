#pragma once
#include <chrono>

class Clock
{
public:

	int64_t getTimeSeconds();
	int64_t getTimeMilliseconds();
	int64_t getTimeMicroseconds();
	void resetClock();


	void update();

	float getDeltaTime();
	static Clock& getInstance();

private:
	//singleton tools
	static bool instanceflag;
	Clock();
	Clock(Clock const&);
	void operator=(Clock const&);


	//functional elements
	std::chrono::high_resolution_clock m_timer;

	//the time that this clock was created at
	std::chrono::time_point<std::chrono::high_resolution_clock> m_createTime;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_lastTime;



	float deltaTime = 0.0f;

};
};

