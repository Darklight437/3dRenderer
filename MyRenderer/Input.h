#pragma once
#include <map>
class Input
{
public:

	struct inputstate
	{
		bool current = false; //is this key down
		bool last = false; //was this key down last frame
	};

	Input();
	~Input();
};

