#include <iostream>
#include <string>

int main(){
    char teaChoice;
    std::cout << "# Hello!\n# Welcome to this adventure game, jolly fellow. I am Shiva Jay, your guide. Before we start, would you care for a spot of tea? [y/n] ";
    std::cin >> teaChoice;
    switch (teaChoice)
    {
    case 'y':
        std::cout << "# Oops! You got poisoned by Shiva Jay.\nYou died.\n";
        return 0;
    case 'n':
        break;
    default:
        std::cout << "# Hey listen here, '" << teaChoice << "' isn't a valid choice.\n";
        return 0;
    }
    return 0;
}