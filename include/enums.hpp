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
	rolling
};

enum StateItem{
	charging,
	used
};

#endif