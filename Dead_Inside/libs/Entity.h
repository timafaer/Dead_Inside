#pragma once
#include<vector>
#include"component.h"
#include"Soul.h"

class Entity {
	std::vector<Component*> components;
	Soul* soul;
public:
	Entity() {};
	Entity(Soul* soul) :soul{ soul } {};
	void set_s(Soul* soul) { this->soul = soul; }

	template<class T>
	void add() {
		components.push_back(new T());
	}

	template<class T>
	T& comp(){
		for (auto& comp : components)
			if (typeid(*comp) == typeid(T))
				return static_cast<T&>(*comp);
	}

	void logic() { soul->logic(); }
};