#pragma once

enum Direction{
	up,
	down,
	left,
	right,
	null=0
};


enum StateEntity{
	standing,
	walking,
	running,
	taking_damage,
	hitting,
	rolling,
	NB_OF_STATE
};

enum StateItem{
	charging,
	used
};