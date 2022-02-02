#include "pch.hpp"

#include "messages.hpp"
#include "utilities.hpp"

static void b0();

static void b00();

static void b01();

static void b02();

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
        // Accept the tea offer made by Shiva Jay
        std::cout << startingDeathMessageOne;
        return 0;
    case 'n':
        // Decline the tea offer made by Shiva Jay
        b0();
        break;
    default:
        // Invalid Input
        std::cout << "# Hey listen here, '" << teaChoice << "' isn't a valid choice.\n";
        return 0;
    }
    return 0;
}

static void b0()
{
    std::cout << mountainHikeMainMessage;

    char option;
    std::cin >> option;
    
    switch (option)
    {
    case '1':
        // Hike up the mountain with Shiva Jay
        b00();
        break;
    case '2':
        // Say no to hiking up the mountain with Shiva Jay
        b01();
        break;
    case '3':
        // Start running away from Shiva Jay
        b02();
        break;
    case '4':
        // Dial 911
        break;
    default:
        // Stand still and do nothing.
        break;
    }
}

static void b00()
{
    std::cout << deathByGunshotOnMountainMainMessage;
    
    switch (utils::randint(1, 2))
    {
    case 1:
        std::cout << deathByGunshotOnMountainDeathMessage1;
        return;
    case 2:
        std::cout << deathByGunshotOnMountainMessage2;
        break;
    }
    
    utils::ChoiceMenu choiceMenu = {};
    choiceMenu.title = "Choices:";
    choiceMenu.options = {
        { '1', "Run away from Shiva Jay." },
        { '2', "Tackle Shiva Jay." },
        { '*', "Stand still and do nothing." }
    };
    choiceMenu.prompt = "Your Choice: ";
    
    switch (utils::choiceMenu(choiceMenu))
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    default:
        break;
    }
}

static void b01()
{
    
}

static void b02()
{
    
}