#include "pch.hpp"

#include "utilities.hpp"

#include "main.hpp"

static const std::string_view startingMessageOne = 
R"NengTheProtagon( Hello! Welcome to this adventure game made by Neng Li and Liangyue Zhao.
To play this game, simply read the passages, and you will be presented with 
varias options to choose from. To choose an option, simply type in the cha-
racter that the option is labeled with.

When an option is labeled [*], it means that you can type in whatever charac-
ter you want to choose that option. It is sometimes called the default optio-
n.

Anyways, enough chitchat. Let's get into the game!

Press [ENTER] to continue... )NengTheProtagon";

static const std::string_view startingMessageTwo =
R"NengTheProtagon(
# So, the story began when you are visiting someone named Shiva Jay. Shiva Jay
# is a rather wild character, and often unpredictable. This makes him the last
# person that you would wanted to see. However, due to unforseen circumstances,
# you have to see him.
#     When you arrived at the house that was claimed to be his location, you k-
# nocked on the door. A man answered.
#     "Hi, I'm looking for Shiva Jay", you said, "Does he live here?"
#     "Oh, I'm Shiva Jay! Nice to meet ya! What's your name?", he replied.
#     "Uh, Tony. As in, Tony Yin."
#     "Ah. So, what takes you here?"
#     "I'm just searching for something. It's uh, well, I don't know what it's 
# called, but I know what it looks like."
#     "Ah, a treasure hunter! Anyways, you have a long journey ahead of you. W-
# hy don't you come in for some tea?"

Alright, here are your choices. In the future, this will not be just be labeled
"Choices"

[y]: Accept the tea offer made by Shiva Jay.
[n]: Decline the tea offer made by Shiva Jay.

Choose one of the above by typing in their letter: )NengTheProtagon";

static const std::string_view startingDeathMessageOne =
R"NengTheProtagon(
Okay, so to keep things moving as fast as possible, I'm not going describe eve-
rything in detail, so from now on they will be as fast as possible passages. T-
his is to make the job easier for the writer and for the player reading these
passages. Anyways, sorry for the interruption.

# So, you walked into Shiva Jay's house and you accepted his tea. It tasted be-
# tter than you originally thought. However, after drinking the tea, your stom-
# ach starts to ache, and within seconds you pass out. It appears that the tea 
# was poisoned
# 
# Anyways, you died from poison within Shiva Jay's tea. Better luck next time.
)NengTheProtagon";

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
        std::cin.ignore();
        std::cin.ignore();
        return 0;
    case 'n':
        // Decline the tea offer made by Shiva Jay
        scp::b0();
        break;
    default:
        // Invalid Input
        std::cout << "# Hey listen here, '" << teaChoice << "' isn't a valid choice.\n";
        return 0;
    }
    return 0;
}