#include <random>

#include "utilities.hpp"

int32_t utils::randint(uint32_t min, uint32_t max)
{
    std::mt19937 randomEngine(time(0));
    std::uniform_int_distribution<int32_t> randomDistribution(min, max);
    
    return randomDistribution(randomEngine);
}

char utils::choiceMenu(const utils::ChoiceMenu& menu)
{
    std::cout << menu.title << "\n";
    for (auto& option: menu.options)
    {
        std::cout << "[" << option.key << "]: " << option.label << "\n";
    }
    
    std::cout << "\n\n" << menu.prompt;
    
    char result;
    std::cin >> result;
    
    return result;
}