#include <iostream>
#include <string>

void deathByGunshotOnMountain()
{
    
}

void uncertainPlot1()
{
    
}

void gettingChasedByShivaJay()
{
    
}

void mountainHike()
{
    std::cout << R"NengTheProtagon(
# "So, you don't like tea, eh?" said Shiva Jay.
# "No, not really", you replied, "I'm not exactly a fan of tea. 
# "Very well, then. You into hiking?"
# "Well, not really. I've hiked before, but not much."
# "Okay. So, would you like to hike up this mountain?"

Choices:
[1]: Hike up the mountain with Shiva Jay.
[2]: Say no to hiking up the mountain with Shiva Jay.
[3]: Start running away from Shiva Jay.
[4]: Dial 911.
[*]: Stand still and do nothing.

Your choice: )NengTheProtagon";

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

int main()
{
    char teaChoice;
    std::cout << "# \"Welcome to this adventure game, jolly fellow. I am Shiva Jay, your guide. Before we start, would you care for a spot of tea?\" \n\nChoices:\n[y]: Accept the tea.\n[n]: Decline the tea and make Shiva Jay sad.\n\nYour choice: ";
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