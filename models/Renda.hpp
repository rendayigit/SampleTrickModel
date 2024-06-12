/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. Renda. )
LIBRARY DEPENDENCIES:
    ((Renda.o))
**************************************************************************/
#ifndef RENDA_HPP
#define RENDA_HPP

class Renda {
    public:
        double a[2] ;               /* m     a value */
        double b[2] ;               /* m/s   b value */
        unsigned long long c ;      /* cm    c value  */

        int default_data();
        int init();
        int scheduled();
};

#endif // RENDA_HPP