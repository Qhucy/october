#pragma once
#include <SFML/Graphics.hpp>
#include "util.h";
#include "player.h";
#include "gif.h";

void titleState(sf::RenderWindow&, sf::Event&, std::vector<sf::Sprite>&);

gameLevel state = gameLevel::title;
player p = player();

void core()
{
	sf::RenderWindow window(sf::VideoMode().getDesktopMode(), "October", sf::Style::Fullscreen);
	sf::Event event;
	std::vector<sf::Sprite> q;
	for (int i = 1; i < 2; i++)
	{
	std::cout << "Loading file textures/titleState/backgroundGif/" + std::to_string(i) + ".jpg" << std::endl;
	sf::Texture a;
	a.loadFromFile("textures/titleState/backgroundGif/" + std::to_string(i) + ".jpg");
	sf::Sprite b;
	b.setTexture(a);
	b.setPosition(300, 300);
	q.push_back(b);
	}
	window.setFramerateLimit(120);
	while (window.isOpen())
	{
		switch (state)
		{
			case gameLevel::title:
				titleState(window, event, q);
				break;
		}
	}
}

gif tsBackground = gif(4, 0, getTSBackgroundGif());
sf::Sprite background;

void titleState(sf::RenderWindow& window, sf::Event& event, std::vector<sf::Sprite>& q)
{
	background.setTexture(tsBackground.getNext());
	background.setPosition(200, 200);
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			saveUids();
			window.close();
			system("exit");
			return;
		}
	}
	window.clear();
	window.draw(background);
	window.display();
}