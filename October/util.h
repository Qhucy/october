#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>

const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;
std::vector<std::string> uids;

std::string genRandom()
{
	std::string str = "";
	while (str == "" || (std::find(uids.begin(), uids.end(), str) != uids.end()))
	{
		str = "";
		for (unsigned int i = 0; i < 20; ++i)
		{
			str += alphanum[rand() % stringLength];
		}
	}
	return str;
}

std::string process(std::string const& s, char until)
{
	std::string::size_type pos = s.find(until);
	if (pos != std::string::npos) return s.substr(0, pos);
	else return s;
}

sf::Texture tst_start;
sf::Texture tst_title;
sf::Texture tst_exit;
sf::SoundBuffer tsb_music;

sf::Texture lst_button1;
sf::Texture lst_button2;

std::vector<sf::Texture> getTSBackgroundGif()
{
	std::vector<sf::Texture> q;
	for (int i = 1; i <= 1; i++)
	{
		std::cout << "Loading file textures/titleState/backgroundGif/" + std::to_string(i) + ".jpg" << std::endl;
		sf::Texture a;
		a.loadFromFile("textures/titleState/backgroundGif/" + std::to_string(i) + ".jpg");
		q.push_back(a);
	}
	return q;
}

void setup()
{
	std::cout << "Loading file textures/titleState/start-button.png" << std::endl;
	tst_start.loadFromFile("textures/titleState/start-button.png");
	std::cout << "Loading file textures/titleState/title.png" << std::endl;
	tst_title.loadFromFile("textures/titleState/title.png");
	std::cout << "Loading file textures/titleState/exit-button.png" << std::endl;
	tst_exit.loadFromFile("textures/titleState/exit-button.png");
	std::cout << "Loading file sounds/titleState/music.wav" << std::endl;
	tsb_music.loadFromFile("sounds/titleState/music.wav");
	std::cout << "Loading file textures/titleState/button1.png" << std::endl;
	lst_button1.loadFromFile("textures/titleState/button1.png");
	std::cout << "Loading file textures/titleState/button2.png" << std::endl;
	lst_button2.loadFromFile("textures/titleState/button2.png");
}