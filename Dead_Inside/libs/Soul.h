#pragma once
class Scence;
class Entity;

class Soul {
protected:
	Entity* comps;
	Scence* scence;
public:
	Soul(){}
	Soul(Entity* comps, Scence* scence) :
		comps{ comps }, scence{ scence }{}
	virtual void set(Entity* comps, Scence* scence) 
		{ this->comps = comps; this->scence = scence; }
	virtual void logic(){}
};