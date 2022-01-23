#pragma once
#include"../component.h"
#include<SFML/Graphics.hpp>
class Draw : public Component ,public sf::Drawable
{
private:
	sf::Drawable* obj;
    sf::Texture* texture;
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if(texture!=nullptr)
            states.texture = texture;
        if(obj!=nullptr)
            target.draw(*obj, states);
    }

    void set(sf::Drawable* dr, sf::Texture* texture = nullptr) { obj = dr; this->texture = texture; }
};