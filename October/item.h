#pragma once

enum itemType
{
	sword, bow, blaster, potion, questItem, unique, artifact
};

class item
{
	public:
		item();
		item(std::string name, float damage, float crit, long price, int level, int maxLevel, float multiplier, itemType type);
		std::string getName();
		bool operator==(const item& rhs) const;
		float getDamage();
		float getCrit();
		long getPrice();
		int getLevel();
		int getMaxLevel();
		float getMultiplier();
		itemType getType();
		void setDamage(float);
		void addDamage(float);
		void subtractDamage(float);
		void setCrit(float);
		void addCrit(float);
		void subtractCrit(float);
		void setPrice(long);
		void addPrice(long);
		void subtractPrice(long);
		void setLevel(int);
		void addLevel(int);
		void subtractLevel(int);
		void setMaxLevel(int);
		void addMaxLevel(int);
		void subtractMaxLevel(int);
		void setMultiplier(float);
		void addMultiplier(float);
		void subtractMultiplier(float);
		void setType(itemType);
		bool equals(item);
	private:
		std::string name;
		float damage;
		float crit;
		long price;
		int level;
		int maxLevel;
		float multiplier;
		itemType type;
};

item::item()
{

}

item::item(std::string a, float b, float c, long d, int e, int f, float g, itemType i)
{
	name = a;
	damage = b;
	crit = c;
	price = d;
	level = e;
	maxLevel = f;
	multiplier = g;
	type = i;
}

bool item::operator==(const item& rhs) const
{
	return (name == rhs.name && type == rhs.type);
}

bool item::equals(item q)
{
	return (name == q.getName() && damage == q.getDamage() && crit == q.getCrit() && price == q.getPrice() && level == q.getLevel() && maxLevel == q.getMaxLevel() && multiplier == q.getMultiplier() && type == q.getType());
}

std::string item::getName()
{
	return name;
}

float item::getDamage()
{
	return damage;
}

float item::getCrit()
{
	return crit;
}

long item::getPrice()
{
	return price;
}

int item::getLevel()
{
	return level;
}

int item::getMaxLevel()
{
	return maxLevel;
}

float item::getMultiplier()
{
	return multiplier;
}

itemType item::getType()
{
	return type;
}

void item::setDamage(float q)
{
	damage = q;
}

void item::addDamage(float q)
{
	damage += q;
}

void item::subtractDamage(float q)
{
	if ((damage - q) < 0.1) damage = 0.1;
	else damage -= q;
}

void item::setCrit(float q)
{
	crit = q;
}

void item::addCrit(float q)
{
	crit += q;
}

void item::subtractCrit(float q)
{
	if ((crit - q) < 0.1) crit = 0.1;
	else crit -= q;
}

void item::setPrice(long q)
{
	price = q;
}

void item::addPrice(long q)
{
	price += q;
}

void item::subtractPrice(long q)
{
	if ((price - q) < 1) price = 1;
	else price -= q;
}

void item::setLevel(int q)
{
	level = q;
}

void item::addLevel(int q)
{
	level += q;
}

void item::subtractLevel(int q)
{
	if ((level - q) < 1) level = 1;
	else level -= q;
}

void item::setMaxLevel(int q)
{
	maxLevel = q;
}

void item::addMaxLevel(int q)
{
	maxLevel += q;
}

void item::subtractMaxLevel(int q)
{
	if ((maxLevel - q) < 1) maxLevel = 1;
	else maxLevel -= q;
}

void item::setMultiplier(float q)
{
	multiplier = q;
}

void item::addMultiplier(float q)
{
	multiplier += q;
}

void item::subtractMultiplier(float q)
{
	if ((multiplier - q) < 1) multiplier = 1;
	else multiplier -= q;
}

void item::setType(itemType q)
{
	type = q;
}