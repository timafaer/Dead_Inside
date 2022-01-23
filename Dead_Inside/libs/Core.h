#pragma once
#include"Scence.h"
#include<SFML/Graphics.hpp>
#include"editor/Edit.h"
class Game {
private:
	std::map<std::string, sf::Texture> textures;
	Scence n_scence;
	Scence* redact;
	friend Editor;
public:
	sf::Event event;
	sf::RenderWindow window;
	Game() {
		window.create(sf::VideoMode(800, 600), "Dead_Inside");
		window.setFramerateLimit(60);
		
	}

	
	void main_loop() {
		while (window.isOpen())
		{

			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();
			//n_scence->logic();//неопределенна сцена
		}
		
	}

};