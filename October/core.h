#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "util.h"
#include "player.h"
#include "gif.h"

void titleState(sf::RenderWindow&, sf::Event&);
void loadState(sf::RenderWindow&, sf::Event&);

gameLevel state = gameLevel::title;
player p = player();
sf::Sound tsu_music;

void core()
{
	sf::RenderWindow window(sf::VideoMode().getDesktopMode(), "October", sf::Style::Fullscreen);
	sf::Event event;
	window.setFramerateLimit(120);
	tsu_music.setBuffer(tsb_music);
	tsu_music.play();
	tsu_music.setVolume(20);
	while (window.isOpen())
	{
		switch (state)
		{
			case gameLevel::title:
				titleState(window, event);
				break;
			case gameLevel::load:
				loadState(window, event);
				break;
			case gameLevel::home:
				if (tsu_music.Playing) tsu_music.stop();
				break;
			case gameLevel::economy:
				if (tsu_music.Playing) tsu_music.stop();
				break;
			case gameLevel::level1:
				if (tsu_music.Playing) tsu_music.stop();
				break;
			case gameLevel::level2:
				if (tsu_music.Playing) tsu_music.stop();
				break;
			case gameLevel::level3:
				if (tsu_music.Playing) tsu_music.stop();
				break;
			case gameLevel::level4:
				if (tsu_music.Playing) tsu_music.stop();
				break;
			case gameLevel::level5:
				if (tsu_music.Playing) tsu_music.stop();
				break;
		}
	}
}

gif tsBackground = gif(4, 0, getTSBackgroundGif());
sf::Sprite tss_background;
sf::Sprite tss_start;
sf::Sprite tss_title;
sf::Sprite tss_exit;

void titleState(sf::RenderWindow& window, sf::Event& event)
{
	tss_background.setTexture(tsBackground.getNext());
	tss_start.setTexture(tst_start);
	tss_start.setPosition(710, 500);
	tss_title.setTexture(tst_title);
	tss_title.setPosition(610, 100);
	tss_exit.setTexture(tst_exit);
	tss_exit.setPosition(710, 700);
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			system("exit");
			return;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
				system("exit");
				return;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if (tss_start.getGlobalBounds().contains(mouse))
			{
				state = gameLevel::load;
				return;
			}
			if (tss_exit.getGlobalBounds().contains(mouse))
			{
				window.close();
				system("exit");
				return;
			}
		}
	}
	window.clear();
	window.draw(tss_background);
	window.draw(tss_start);
	window.draw(tss_title);
	window.draw(tss_exit);
	window.display();
}

sf::Sprite lss_button1;
sf::Sprite lss_button2;

void loadState(sf::RenderWindow& window, sf::Event& event)
{
	tss_background.setTexture(tsBackground.getNext());
	tss_title.setTexture(tst_title);
	tss_title.setPosition(610, 100);
	lss_button1.setTexture(lst_button1);
	lss_button1.setPosition(610, 500);
	lss_button2.setTexture(lst_button2);
	lss_button2.setPosition(610, 700);
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			system("exit");
			return;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				state = gameLevel::title;
				return;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if (lss_button1.getGlobalBounds().contains(mouse))
			{
				// load player
				return;
			}
			if (lss_button2.getGlobalBounds().contains(mouse))
			{
				// create new file
				// change way of saving/loading so there is only a single save file
				return;
			}
		}
	}
	window.clear();
	window.draw(tss_background);
	window.draw(tss_title);
	window.draw(lss_button1);
	window.draw(lss_button2);
	window.display();
}