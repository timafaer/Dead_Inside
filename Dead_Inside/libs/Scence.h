#pragma once
#include"Entity.h"
#include<map>
#include<string>
class Scence {
	std::map<std::string, std::vector<Entity>> objects;
public:
	void add_obj(std::string name) { objects[name].push_back(Entity()); }

	Entity& get_one(std::string type, int numb) { return objects[type][numb]; }
	std::vector<Entity>& get_name(std::string type) { return objects[type]; }

	void logic() {
		for (auto& i : objects) 
			for (auto& j : i.second) 
				j.logic();
	}
};