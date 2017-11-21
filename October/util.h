#pragma once

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

void loadCore()
{
	std::fstream file("uids.txt", std::ios::in);
	std::string contents;
	while (getline(file, contents))
	{
		uids.push_back(contents);
	}
}

std::vector<sf::Texture> getTSBackgroundGif()
{
	std::vector<sf::Texture> q;
	for (int i = 1; i < 2; i++)
	{
		std::cout << "Loading file textures/titleState/backgroundGif/" + std::to_string(i) + ".jpg" << std::endl;
		sf::Texture a;
		a.loadFromFile("textures/titleState/backgroundGif/" + std::to_string(i) + ".jpg");
		q.push_back(a);
	}
	return q;
}