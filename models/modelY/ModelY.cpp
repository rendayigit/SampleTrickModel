/*************************************************************************
PURPOSE: ( A sample trick model. See ModelX for more details. )
LIBRARY DEPENDENCIES:
    ((ModelY.o))
PROGRAMMERS:
    ((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
**************************************************************************/

#include "ModelY.hpp"
#include <iostream>

void ModelY::update() { std::cout << "ModelY inFlow variable set: " << inFlow.getValue() << std::endl; }
