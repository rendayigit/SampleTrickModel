/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCIES:
    ((ModelX.o))
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
ICG: (No)
**************************************************************************/
#ifndef MODELX_HH
#define MODELX_HH

#include "common/OutFlow.hh"

class ModelX {
public:
  double a;    /* m     sample a value */
  double b[2];    /* m/s   sample b value */
  OutFlow<int> c; /* cm    sample c value */

  int init();
};

#endif // MODELX_HH