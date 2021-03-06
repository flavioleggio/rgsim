#include <math.h>

#include "telem_interface.h"

#define RESOLUTION 4000 // ticks per revolution

TelemInterface::TelemInterface()
{
  transport::init();
  transport::run();
  node = transport::NodePtr(new transport::Node());
  node->Init("rgsim");
  sub = node->Subscribe("~/encoders", &TelemInterface::telem_callback, this);
}

TelemInterface::~TelemInterface()
{
  node->Fini();
  sub->Unsubscribe();
}

void TelemInterface::get_sample(float* ts, int* left_ticks, int* right_ticks, float* left_velocity, float* right_velocity)
{
  *ts = m_ts;
  *left_ticks = m_left_ticks;
  *right_ticks = m_right_ticks;
  *left_velocity = m_left_velocity;
  *right_velocity = m_right_velocity;
}

void TelemInterface::print()
{
  printf("Timestamp = %f, Left ticks = %d, Right ticks = %d, Left velocity = %f, Right velocity = %f\n", \
          m_ts, m_left_ticks, m_right_ticks, m_left_velocity, m_right_velocity);
}

void TelemInterface::telem_callback(const ConstEncoderMsgPtr& msg)
{
  m_ts = msg->timestamp();
  m_left_ticks = msg->left_angle() * RESOLUTION / (2 * M_PI);
  m_right_ticks = msg->right_angle() * RESOLUTION / (2 * M_PI);
  m_left_velocity = msg->left_velocity();
  m_right_velocity = msg->right_velocity();
}
