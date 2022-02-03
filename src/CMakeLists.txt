add_executable(
    "adventure-game"
    
    "b0.cpp"
    "main.cpp"
    "utilities.cpp"
    
    "b0.hpp"
    "main.hpp"
    "pch.hpp"
    "utilities.hpp"
)

target_precompile_headers("adventure-game" PRIVATE "pch.hpp")

add_subdirectory("b0")