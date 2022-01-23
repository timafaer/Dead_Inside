#pragma once
#include"../component.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
class Entity;
class Map :public Component
{
	sf::VertexArray	m_vertices;
	sf::Vector2u size;
    int x, y;
    friend Entity;
public:
	Map(int x, int y, sf::Vector2u size = sf::Vector2u(32, 32)) :size{ size } {
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(x * y * 4);
        this->x = x;
        this->y = y;
	}
	void reader(std::string filename) {
		std::ifstream fin(filename);
        int len;
        for (unsigned int i = 0; i < x; ++i)
            for (unsigned int j = 0; j < y; ++j)
            {
                fin >> len;

                sf::Vertex* quad = &m_vertices[(i + j * x) * 4];

                quad[0].position = sf::Vector2f(i * size.x, j * size.y);
                quad[1].position = sf::Vector2f((i + 1) * size.x, j * size.y);
                quad[2].position = sf::Vector2f((i + 1) * size.x, (j + 1) * size.y);
                quad[3].position = sf::Vector2f(i * size.x, (j + 1) * size.y);

                quad[0].texCoords = sf::Vector2f((len) * size.x, 0);
                quad[1].texCoords = sf::Vector2f((len + 1) * size.x,0);
                quad[2].texCoords = sf::Vector2f((len + 1) * size.x,  size.y);
                quad[3].texCoords = sf::Vector2f(len * size.x, size.y);
            }
        fin.close();

	}

};
