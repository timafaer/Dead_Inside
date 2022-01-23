#pragma once
#include"Entity.h"
#include<map>
#include<string>
#include<SFML/Graphics.hpp>
class Editor;
class Game;
class Scence: public sf::Drawable
{
private:
	Scence* prev;
	std::vector<Scence> scences;
	std::map<std::string, std::vector<Entity>> objects;
	std::vector<Entity*> drawing;
	int x, y;
	float rotate;
	int deep;
	friend Editor;
	friend Game;
	friend Scence;
public:
	void add_obj(std::string name) { objects[name].push_back(Entity()); }

	Entity& get_one(std::string type, int numb) { return objects[type][numb]; }
	std::vector<Entity>& get_name(std::string type) { return objects[type]; }
	bool s(Entity* a, Entity* b) {
		return a->deep > b->deep;
	}

	void logic() {
		for (auto& i : objects) 
			for (auto& j : i.second) 
				j.logic();
		//std::sort(drawing.begin(), drawing.end(),s);
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for(auto& i:drawing)
			target.draw(*i, states);
	}
};