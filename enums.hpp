#ifndef ENUMS
#define ENUMS

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
	taking_damage,
	hitting,
	rolling,
	NB_OF_STATE
};

enum StateItem{
	charging,
	used
};

#endif