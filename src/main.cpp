#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main(  )
{
    Chess::Game( SCREEN_WIDTH, SCREEN_HEIGHT, "Chess" );
    std::cout << "hello world." << std::endl;
    return EXIT_SUCCESS; 
}
