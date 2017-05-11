#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "telem_interface.h"

int main(int argc, char** argv)
{
  TelemInterface telem;
  while(1)
  {
    telem.print();
    usleep(500000);
  }
}
