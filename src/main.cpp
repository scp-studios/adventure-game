#include <iostream>
#include <string>

#include "messages.hpp"

static void mountainHike();

static void deathByGunshotOnMountain();

static void gettingChasedByShivaJay();

static void uncertainPlot1();

int main()
{
    char teaChoice;
    std::cout << startingMessageOne;
    
    std::string nullLine;
    std::getline(std::cin, nullLine);

    std::cout << startingMessageTwo;
    
    std::cin >> teaChoice;
    switch (teaChoice)
    {
    case 'y':
        std::cout << startingDeathMessageOne;
        return 0;
    case 'n':
        mountainHike();
        break;
    default:
        std::cout << "# Hey listen here, '" << teaChoice << "' isn't a valid choice.\n";
        return 0;
    }
    return 0;
}

static void mountainHike()
{
    std::cout << mountainHikeMainMessage;

    char option;
    std::cin >> option;
    
    switch (option)
    {
    case '1':
        deathByGunshotOnMountain();
        break;
    case '2':
        uncertainPlot1();
        break;
    case '3':
        gettingChasedByShivaJay();
        break;
    case '4':
        break;
    default:
        break;
    }
}

static void deathByGunshotOnMountain()
{
    
}

static void uncertainPlot1()
{
    
}

static void gettingChasedByShivaJay()
{
    
}