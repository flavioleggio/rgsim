#include "control_interface.h"

ControlInterface::ControlInterface()
{
  transport::init();
  transport::run();
  transport::NodePtr node(new transport::Node());
  node->Init("rgsim");

  pub = node->Advertise<msgs::MotorsCommand>("~/motors_control");
  pub->WaitForConnection();
}

ControlInterface::~ControlInterface()
{
  node->Fini();
  pub->Fini();
}

void ControlInterface::set_joint_torques(float left_signal, float right_signal)
{
  msgs::MotorsCommand msg;
  msg.set_left_torque(left_signal);
  msg.set_right_torque(right_signal);

  pub->Publish(msg);
}
