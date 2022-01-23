#pragma once
#include<vector>
#include"Soul.h"
#include"base_comps/Draw.h"
class Editor;

class Entity: public sf::Drawable
{
	std::vector<Component*> components;
	Soul* soul;
	int x, y;
	friend Editor;
	
public:
	int deep;

	Entity() {};
	Entity(Soul* soul) :soul{ soul } {};
	void set_s(Soul* soul) { this->soul = soul; }

	template<class T>
	void add() {
		components.push_back(new T());
	}

	template<class T>
	T& comp() const{
		for (auto& com : components)
			if (typeid(*com) == typeid(T))
				return static_cast<T&>(*com);
	}

	void logic() { soul->logic(); }

	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(comp<Draw>(), states);
	}
};	