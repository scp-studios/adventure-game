#include <iostream>
#include <string>

void mountainHike()
{
    std::cout << "\"So, you don't like tea, I assume?\", said Shiva Jay. \"Yeah\"";
    std::cout << ", you replied, \"I'm not exactly a fan of tea.\n";
    std::cout << "\"Very well then.\", said Shiva Jay, \"Then would you like to co";
    std::cout << "me with me to hike up this mountain?\"\n\n";
    
    std::cout << "Choices:\n";
    std::cout << "[1]: Hike up the mountain with Shiva Jay.\n";
    std::cout << "[2]: Decline to hike up the mountain.\n";
    std::cout << "[3]: Start running away.\n";
    std::cout << "[4]: Dial 911.\n";
    
    std::cout << "\n\nYour Choice: ";
    
    char option;
    std::cin >> option;
}

int main()
{
    char teaChoice;
    std::cout << "# Hello!\n# Welcome to this adventure game, jolly fellow. I am Shiva Jay, your guide. Before we start, would you care for a spot of tea? [y/n] ";
    std::cin >> teaChoice;
    switch (teaChoice)
    {
    case 'y':
        std::cout << "# Oops! You got poisoned by Shiva Jay.\nYou died.\n";
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