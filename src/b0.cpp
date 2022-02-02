#include "pch.hpp"

#include "main.hpp"
#include "b0.hpp"

static const std::string_view mountainHikeMainMessage = R"NengTheProtagon(
# So, you told Shiva Jay that you are not a fan of tea. He accepts that, and i-
# nvites you to go on a hike with him on a nearby mountain.

Choices:
[1]: Hike up the mountain with Shiva Jay.
[2]: Say no to hiking up the mountain with Shiva Jay.
[3]: Start running away from Shiva Jay.
[4]: Dial 911.
[*]: Stand still and do nothing.

Your choice: )NengTheProtagon";

void scp::b0()
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
        b03();
        break;
    default:
        // Stand still and do nothing.
        b04();
        break;
    }
}