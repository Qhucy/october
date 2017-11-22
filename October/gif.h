#pragma once
#include <SFML/Graphics.hpp>

class gif
{
	public:
		gif(int maxFps, int number, const std::vector<sf::Texture>& textures);
		~gif();
		int getNumber();
		std::vector<sf::Texture>& getTextures();
		void setNumber(int);
		void addNumber(int);
		void subtractNumber(int);
		void setTextures(std::vector<sf::Texture>);
		void addTextures(sf::Texture);
		int getMaxFps();
		void setMaxFps(int);
		void addMaxFps(int);
		void subtractMaxFps(int);
		sf::Texture& getNext();
		int getFps();
	private:
		int fps;
		int maxFps;
		int number;
		std::vector<sf::Texture> textures;
};

gif::~gif()
{
	std::cout << "Object is being deleted";
}

gif::gif(int a, int b, const std::vector<sf::Texture>& c)
{
	fps = 0;
	maxFps = a;
	number = b;
	textures = c;
}

sf::Texture& gif::getNext()
{
	sf::Texture texture = textures.at(number);
	if ((fps + 1) >= maxFps)
	{
		fps = 0;
		if ((number + 1) >= textures.size()) number = 0;
		else number++;
	}
	else fps++;
	return texture;
}

int gif::getNumber()
{
	return number;
}

std::vector<sf::Texture>& gif::getTextures()
{
	return textures;
}

void gif::setNumber(int q)
{
	number = q;
}

void gif::addNumber(int q)
{
	number += q;
}

void gif::subtractNumber(int q)
{
	if ((number - q) < 0) number = 0;
	else number -= q;
}

void gif::setTextures(std::vector<sf::Texture> q)
{
	textures = q;
}

void gif::addTextures(sf::Texture q)
{
	textures.emplace_back(q);
}

int gif::getMaxFps()
{
	return maxFps;
}

void gif::setMaxFps(int q)
{
	maxFps = q;
}

void gif::addMaxFps(int q)
{
	maxFps += q;
}

void gif::subtractMaxFps(int q)
{
	if ((maxFps - q) < 0) maxFps = 0;
	else maxFps -= q;
}

int gif::getFps()
{
	return fps;
}