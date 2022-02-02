add_executable(
    "adventure-game"
    
    "main.cpp"
    "utilities.cpp"
    
    "pch.hpp"
    "messages.hpp"
    "utilities.hpp"
)

target_precompile_headers("adventure-game" PRIVATE "pch.hpp")