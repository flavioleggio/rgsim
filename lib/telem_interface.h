#pragma once

#include <string>

#include <gazebo/common/common.hh>
#include <gazebo/transport/transport.hh>

#include "EncoderMsg.pb.h"

using namespace gazebo;

typedef const boost::shared_ptr<const msgs::EncoderMsg> ConstEncoderMsgPtr;

class TelemInterface {
  public:
    TelemInterface();
    void print();

  private:
    void telemCallback(const ConstEncoderMsgPtr& msg);
    // Topic to read encoder signals from.
    std::string topic;

    // The node on which we're advertising.
    transport::NodePtr node;

    // Subscriber handle.
    transport::SubscriberPtr sub;

    float m_ts;
    float m_left_ticks;
    float m_right_ticks;
    float m_left_velocity;
    float m_right_velocity;
};
