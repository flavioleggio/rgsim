#include <stdio.h>
#include <stdlib.h>

#include "control_interface.h"

int main(int argc, char** argv)
{
  ControlInterface ctl;

  while(1)
  {
    ctl.set_joint_torques(0.001, 0.001);
    common::Time::MSleep(100);
  }
}
