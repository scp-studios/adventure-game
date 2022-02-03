#include "../utilities.hpp"

#include "../b0.hpp"

static const std::string_view deathByGunshotOnMountainMainMessage = R"NengTheProtagon(
# You and Shiva Jay starts walking up the mountain. It wasn't too steep, or at
# least not so steep that you can't handle it. However, about halfway up the m-
# ountain, Shiva Jay stopped. "You know, when I used to work in the military, 
# one of the most important skills was working with a pistol." He then pulls a
# pistol out of his pockets and points it at you.
)NengTheProtagon";

static const std::string_view deathByGunshotOnMountainDeathMessage1 = R"NengTheProtagon(
# Shiva Jay pulls the trigger and fires. You, being a normal human being, was 
# unable to dodge the bullet and was killed as the bullet penetrated your skull
# .
# 
# In other words, you died from a getting shot by Shiva Jay on a remote mounta-
# in.
)NengTheProtagon";

static const std::string_view deathByGunshotOnMountainMessage2 = R"NengTheProtagon(
# Shiva Jay was about to pull the trigger when he suddenly saw group of securi-
# ty guards near him. He quickly retracted the gun as the security guards walks
# by you.
)NengTheProtagon";

void scp::b00()
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