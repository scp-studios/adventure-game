#ifndef C8AED1A5_E28C_4235_8A51_3C3D497641C8
#define C8AED1A5_E28C_4235_8A51_3C3D497641C8

#include "pch.hpp"

namespace utils
{
    // A choice option
    struct ChoiceMenuOption
    {
        char key;
        std::string label;
    };
    
    // A choice menu
    struct ChoiceMenu
    {
        std::string title;
        std::string prompt;
        std::vector<ChoiceMenuOption> options;
    };
    
    // Generate a random integer within a certain range
    int32_t randint(uint32_t min, uint32_t max);
    
    // Create a choice menu and returns the result.
    char choiceMenu(const ChoiceMenu& menu);
}

#endif /* C8AED1A5_E28C_4235_8A51_3C3D497641C8 */
