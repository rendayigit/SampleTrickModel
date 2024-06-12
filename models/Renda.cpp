/********************************* TRICK HEADER *******************************
PURPOSE: ( A sample trick model created using only cpp. Renda. )
LIBRARY DEPENDENCY:
    ((Renda.o))
*******************************************************************************/
#include "Renda.hpp"
#include <math.h>
#include <iostream>

int Renda::default_data() {
    std::cout << "Default Data Entered" << std::endl;
    a[0] = 0.0;
    a[1] = 6578000.0;
    b[0] = 7905.0;
    b[1] = 0.0;
    c = 900;
    return 0;
}

int Renda::init() {
    std::cout << "Initialization Entered" << std::endl;
    b[1] = 0.1;
    c = 9000;
    return 0;
}

int Renda::scheduled() {
   std::cout << "Scheduled Entered" << std::endl;
   c++;
   return 0;
}