#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

#include "MotorsCommand.pb.h"

#include <stdio.h>
#include <stdlib.h>

using namespace gazebo;

int main(int argc, char** argv)
{
  msgs::MotorsCommand msg;
  msg.set_left_torque(0.001);
  msg.set_right_torque(0.001);

  transport::init();
  transport::run();
  transport::NodePtr node(new transport::Node());
  node->Init("rgsim");

  transport::PublisherPtr pub = node->Advertise<msgs::MotorsCommand>("~/motors_control");
  pub->WaitForConnection();

  while(1)
  {
    pub->Publish(msg);
    printf("msg published\n");
    common::Time::MSleep(100);
  }

  transport::fini();
  return 0;
}
