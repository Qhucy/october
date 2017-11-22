#pragma once
#include "item.h";

enum class quests
{
	none, first, second
};

std::ostream& operator<<(std::ostream& out, quests const& q)
{
	out << q;
	return out;
}

class quest
{
	public:
		quest();
		quest(quests enumName, std::string name, long coins, float xp, std::vector<item> rewards, std::vector<bool> conditions, std::vector<item> needed);
		bool operator==(const quest& rhs) const;
		quests getQuestEnum();
		std::string getName();
		long getCoins();
		float getXp();
		std::vector<item> getRewards();
		std::vector<bool> getConditions();
		std::vector<item> getNeeded();
		void setQuestEnum(quests);
		void setName(std::string);
		void setCoins(long);
		void addCoins(long);
		void subtractCoins(long);
		void setXp(float);
		void addXp(float);
		void subtractXp(float);
		void setRewards(std::vector<item>);
		void setReward(int, item);
		void addReward(item);
		void removeReward(item);
		void setConditions(std::vector<bool>);
		void addCondition(bool);
		void removeLastCondition();
		void setCondition(int, bool);
		void setNeeded(std::vector<item>);
		void setNeeded(int, item);
		void addNeeded(item);
		void removeNeeded(item);
	private:
		quests enumName;
		std::string name;
		long coins;
		float xp;
		std::vector<item> rewards;
		std::vector<bool> conditions;
		std::vector<item> needed;
};

bool quest::operator==(const quest& rhs) const
{
	return (name == rhs.name && enumName == rhs.enumName);
}

quest::quest()
{

}

quest::quest(quests a, std::string b, long c, float d, std::vector<item> e, std::vector<bool> f, std::vector<item> g)
{
	enumName = a;
	name = b;
	coins = c;
	xp = d;
	rewards = e;
	conditions = f;
	needed = g;
}

quests quest::getQuestEnum()
{
	return enumName;
}

std::string quest::getName()
{
	return name;
}

long quest::getCoins()
{
	return coins;
}

float quest::getXp()
{
	return xp;
}

std::vector<item> quest::getRewards()
{
	return rewards;
}

std::vector<bool> quest::getConditions()
{
	return conditions;
}

std::vector<item> quest::getNeeded()
{
	return needed;
}

void quest::setQuestEnum(quests q)
{
	enumName = q;
}

void quest::setName(std::string q)
{
	name = q;
}

void quest::setCoins(long q)
{
	coins = q;
}

void quest::addCoins(long q)
{
	coins += q;
}

void quest::subtractCoins(long q)
{
	if ((coins - q) < 0) coins = 0;
	else coins -= q;
}

void quest::setXp(float q)
{
	xp = q;
}

void quest::addXp(float q)
{
	xp += q;
}

void quest::subtractXp(float q)
{
	if ((xp - q) < 0) xp = 0;
	else xp -= q;
}

void quest::setRewards(std::vector<item> q)
{
	rewards = q;
}

void quest::setReward(int a, item q)
{
	std::vector<item> r;
	for (int i = 0; i < rewards.size(); i++)
	{
		if (i == a) r.push_back(q);
		else r.push_back(rewards.at(i));
	}
	rewards = r;
}

void quest::addReward(item q)
{
	rewards.push_back(q);
}

void quest::removeReward(item q)
{
	std::vector<item> r;
	for (int i = 0; i < rewards.size(); i++)
	{
		if (q.equals(rewards.at(i))) continue;
		else r.push_back(rewards.at(i));
	}
	rewards = r;
}

void quest::setConditions(std::vector<bool> q)
{
	conditions = q;
}

void quest::addCondition(bool q)
{
	conditions.push_back(q);
}

void quest::removeLastCondition()
{
	std::vector<bool> r;
	if (conditions.size() < 2) { conditions = r; return; }
	for (int i = 0; i < conditions.size(); i++)
	{
		if ((i + 1) == conditions.size()) continue;
		else r.push_back(conditions.at(i));
	}
	conditions = r;
}

void quest::setCondition(int a, bool q)
{
	std::vector<bool> r;
	for (int i = 0; i < conditions.size(); i++)
	{
		if (i == a) r.push_back(q);
		else r.push_back(conditions.at(i));
	}
	conditions = r;
}

void quest::setNeeded(std::vector<item> q)
{
	needed = q;
}

void quest::setNeeded(int a, item q)
{
	std::vector<item> r;
	for (int i = 0; i < needed.size(); i++)
	{
		if (i == a) r.push_back(q);
		else r.push_back(needed.at(i));
	}
	needed = r;
}

void quest::addNeeded(item q)
{
	needed.push_back(q);
}

void quest::removeNeeded(item q)
{
	std::vector<item> r;
	for (int i = 0; i < needed.size(); i++)
	{
		if (q.equals(needed.at(i))) continue;
		else r.push_back(needed.at(i));
	}
	needed = r;
}