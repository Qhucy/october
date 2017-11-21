#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <memory>
#include <stdlib.h>
#include "util.h";
#include "item.h";
#include "quest.h";
#include "inventory.h";
#include "player.h";
#include "gif.h";
#include "core.h";

int main()
{
	loadCore();
	core();
	return 0;
}