#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <regex>
#include "item.h";
#include "quest.h";
#include "inventory.h";

enum gameLevel
{
	title, load, home, economy, level1, level2, level3, level4, level5
};

class player
{
	public:
		player();
		player(std::string uid);
		player(std::string uid, std::string name, long coins, int level, float xp, float strength, float defense, float agility, float health, float maxHealth, inventory inv, gameLevel gmLvl, sf::Sprite spr, std::vector<quests> completedQuests, quests curQuest);
		std::vector<quests>& getCompletedQuests();
		quests& getCurrentQuest();
		std::string getUid();
		std::string getName();
		long getCoins();
		int getLevel();
		float getXp();
		float getStrength();
		float getDefense();
		float getAgility();
		float getHealth();
		float getMaxHealth();
		inventory& getInventory();
		gameLevel getGameLevel();
		sf::Sprite& getSprite();
		bool questCompleted(quests);
		void setCompletedQuests(std::vector<quests>);
		void setCurrentQuest(quests);
		void addCompletedQuest(quests);
		void setHealth(float);
		void setMaxHealth(float);
		void setCoins(long);
		void setUid(std::string);
		void setName(std::string);
		void setStrength(float);
		void setDefense(float);
		void setAgility(float);
		void setLevel(int);
		void setXp(float);
		void setInventory(inventory);
		void setGameLevel(gameLevel);
		void setSprite(sf::Sprite);
		void saveStats();
		void addHealth(float);
		void subtractHealth(float);
		void addMaxHealth(float);
		void subtractMaxHealth(float);
		void addCoins(long);
		void subtractCoins(long);
		void addStrength(float);
		void subtractStrength(float);
		void addDefense(float);
		void subtractDefense(float);
		void addAgility(float);
		void subtractAgility(float);
		void addLevel(int);
		void subtractLevel(int);
		void addXp(float);
		void subtractXp(float);
	private:
		quests curQuest;
		std::vector<quests> comQuests;
		std::string uid;
		std::string name;
		long coins;
		int level;
		float xp;
		float strength;
		float defense;
		float agility;
		float health;
		float maxHealth;
		inventory inv;
		gameLevel gl;
		sf::Sprite spr;
};

player::player()
{

}

player::player(std::string a, std::string b, long c, int d, float e, float f, float g, float h, float i, float j, inventory l, gameLevel m, sf::Sprite n, std::vector<quests> o, quests p)
{
	uid = a;
	name = b;
	coins = c;
	level = d;
	xp = e;
	strength = f;
	defense = g;
	agility = h;
	health = i;
	maxHealth = j;
	inv = l;
	gl = m;
	spr = n;
	comQuests = o;
	curQuest = p;
}

player::player(std::string a)
{
	uid = a;
	std::fstream file(a + ".txt", std::ios::in);
	std::string contents;
	int i = 0;
	while (getline(file, contents))
	{
		i++;
		std::vector<quests> q;
		std::vector<item> r;
		int s;
		std::string before = "";
		long b1;
		float c1;
		float d1;
		float e1;
		int f1;
		float g1;
		gameLevel h1;
		float i1;
		float j1;
		quests k1;
		std::string a2;
		float b2;
		float c2;
		long d2;
		int f2;
		float g2;
		float h2;
		itemType i2;
		switch (i)
		{
			case 1:
				name = contents;
				break;
			case 2:
				b1 = std::stol(process(contents, ':'));
				coins = b1;
				c1 = std::stof(process(std::regex_replace(contents, std::regex(b1 + ":"), ""), ':'));
				strength = c1;
				d1 = std::stof(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":"), ""), ':'));
				defense = d1;
				e1 = std::stof(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":"), ""), ':'));
				agility = e1;
				f1 = std::stoi(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":" + std::to_string(e1) + ":"), ""), ':'));
				level = f1;
				g1 = std::stof(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":" + std::to_string(e1) + ":" + std::to_string(f1) + ":"), ""), ':'));
				xp = g1;
				h1 = static_cast<gameLevel>(std::stoi(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":" + std::to_string(e1) + ":" + std::to_string(f1) + ":" + std::to_string(g1) + ":"), ""), ':')));
				gl = h1;
				i1 = std::stof(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":" + std::to_string(e1) + ":" + std::to_string(f1) + ":" + std::to_string(g1) + ":" + std::to_string(h1) + ":"), ""), ':'));
				health = i1;
				j1 = std::stof(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":" + std::to_string(e1) + ":" + std::to_string(f1) + ":" + std::to_string(g1) + ":" + std::to_string(h1) + ":" + std::to_string(i1) + ":"), ""), ':'));
				maxHealth = j1;
				k1 = static_cast<quests>(std::stoi(process(std::regex_replace(contents, std::regex(b1 + ":" + std::to_string(c1) + ":" + std::to_string(d1) + ":" + std::to_string(e1) + ":" + std::to_string(f1) + ":" + std::to_string(g1) + ":" + std::to_string(h1) + ":" + std::to_string(i1) + ":" + std::to_string(j1) + ":"), ""), ':')));
				curQuest = k1;
				break;
			case 3:
				while (before != "")
				{
					q.push_back(static_cast<quests>(std::stoi(process(std::regex_replace(contents, std::regex(before + ":"), ""), ':'))));
					before = std::regex_replace(contents, std::regex(process(contents, ':')), "");
				}
				comQuests = q;
				break;
			case 4:
				s = stoi(contents);
			default:
				a2 = process(contents, ':');
				b2 = std::stof(process(std::regex_replace(contents, std::regex(a2 + ":"), ""), ':'));
				c2 = std::stof(process(std::regex_replace(contents, std::regex(a2 + ":" + std::to_string(b2) + ":"), ""), ':'));
				d2 = std::stol(process(std::regex_replace(contents, std::regex(a2 + ":" + std::to_string(b2) + ":" + std::to_string(c2) + ":"), ""), ':'));
				f2 = std::stoi(process(std::regex_replace(contents, std::regex(a2 + ":" + std::to_string(b2) + ":" + std::to_string(c2) + ":" + std::to_string(d2) + ":"), ""), ':'));
				g2 = std::stof(process(std::regex_replace(contents, std::regex(a2 + ":" + std::to_string(b2) + ":" + std::to_string(c2) + ":" + std::to_string(d2) + ":" + std::to_string(f2) + ":"), ""), ':'));
				h2 = std::stof(process(std::regex_replace(contents, std::regex(a2 + ":" + std::to_string(b2) + ":" + std::to_string(c2) + ":" + std::to_string(d2) + ":" + std::to_string(f2) + ":" + std::to_string(g2) + ":"), ""), ':'));
				i2 = static_cast<itemType>(std::stoi(process(std::regex_replace(contents, std::regex(a2 + ":" + std::to_string(b2) + ":" + std::to_string(c2) + ":" + std::to_string(d2) + ":" + std::to_string(f2) + ":" + std::to_string(g2) + ":" + std::to_string(h2) + ":"), ""), ':')));
				r.push_back(item(a2, b2, c2, d2, f2, g2, h2, i2));
				break;
		}
		inv = inventory(s, r);
	}
}

void player::saveStats()
{
	std::ofstream ofs(uid + ".txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	std::fstream file(uid + ".txt", std::ios::out);
	file << name << std::endl
		<< coins << ":" << strength << ":" << defense << ":" << agility << ":" << level << ":" << gl << ":" << health << ":" << maxHealth << ":" << curQuest << std::endl;
	for (int i = 0; i < comQuests.size(); i++)
	{
		if (i == 0) file << comQuests.at(i);
		else file << ":" << comQuests.at(i);
	}
	file << std::endl << inv.getSize() << std::endl;
	if (!inv.getContents().empty())
	{
		for (item i : inv.getContents())
		{
			file << i.getName() << ":" << i.getDamage() << ":" << i.getCrit() << ":" << i.getPrice() << ":" << i.getLevel() << ":" << i.getMaxLevel() << ":" << i.getMultiplier() << ":" << i.getType();
		}
	}
	file.close();
}

std::vector<quests>& player::getCompletedQuests()
{
	return comQuests;
}

quests& player::getCurrentQuest()
{
	return curQuest;
}

std::string player::getUid()
{
	return uid;
}

std::string player::getName()
{
	return name;
}

long player::getCoins()
{
	return coins;
}

int player::getLevel()
{
	return level;
}

float player::getXp()
{
	return xp;
}

float player::getStrength()
{
	return strength;
}

float player::getDefense()
{
	return defense;
}

float player::getAgility()
{
	return agility;
}

float player::getHealth()
{
	return health;
}

float player::getMaxHealth()
{
	return maxHealth;
}

inventory& player::getInventory()
{
	return inv;
}

gameLevel player::getGameLevel()
{
	return gl;
}

sf::Sprite& player::getSprite()
{
	return spr;
}

bool player::questCompleted(quests q)
{
	if (comQuests.empty()) return false;
	if (std::find(comQuests.begin(), comQuests.end(), q) != comQuests.end()) return true;
	else return false;
}

void player::setCompletedQuests(std::vector<quests> q)
{
	comQuests = q;
}

void player::setCurrentQuest(quests q)
{
	curQuest = q;
}

void player::addCompletedQuest(quests q)
{
	comQuests.push_back(q);
}

void player::setHealth(float q)
{
	health = q;
}

void player::setMaxHealth(float q)
{
	maxHealth = q;
}

void player::setCoins(long q)
{
	coins = q;
}

void player::setLevel(int q)
{
	level = q;
}

void player::setXp(float q)
{
	xp = q;
}

void player::setUid(std::string str)
{
	uid = str;
}

void player::setName(std::string str)
{
	name = str;
}

void player::setStrength(float q)
{
	strength = q;
}

void player::setDefense(float q)
{
	defense = q;
}

void player::setAgility(float q)
{
	agility = q;
}

void player::setInventory(inventory q)
{
	inv = q;
}

void player::setGameLevel(gameLevel q)
{
	gl = q;
}

void player::setSprite(sf::Sprite q)
{
	spr = q;
}

void player::addHealth(float q)
{
	if ((health + q) > maxHealth) health = maxHealth;
	else health += q;
}

void player::subtractHealth(float q)
{
	if ((health - q) < 0) health = 0;
	else health -= q;
}

void player::addMaxHealth(float q)
{
	maxHealth += q;
}

void player::subtractMaxHealth(float q)
{
	maxHealth -= q;
	if (health > maxHealth) health = maxHealth;
}

void player::addCoins(long q)
{
	coins += q;
}

void player::subtractCoins(long q)
{
	if ((coins - q) < 0) coins = 0;
	else coins -= q;
}

void player::addStrength(float q)
{
	strength += q;
}

void player::subtractStrength(float q)
{
	if ((strength - q) < 1) strength = 1;
	else strength -= q;
}

void player::addDefense(float q)
{
	defense += q;
}

void player::subtractDefense(float q)
{
	if ((defense - q) < 1) defense = 1;
	else defense -= q;
}

void player::addAgility(float q)
{
	agility += q;
}

void player::subtractAgility(float q)
{
	if ((agility - q) < 1) agility = 1;
	else agility -= q;
}

void player::addLevel(int q)
{
	level += q;
}

void player::subtractLevel(int q)
{
	if ((level - q) < 1) level = 1;
	else level -= q;
}

void player::addXp(float q)
{
	xp += q;
}

void player::subtractXp(float q)
{
	if ((xp - q) < 0) xp = 0;
	xp -= q;
}