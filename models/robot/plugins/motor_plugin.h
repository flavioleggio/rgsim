#pragma once

#include <string>

#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>

#include "MotorsCommand.pb.h"

namespace gazebo
{

  typedef const boost::shared_ptr<const msgs::MotorsCommand> ConstMotorsCommandPtr;

  class DCMotor : public ModelPlugin {
    public:
    // Load the dc motor and configures it according to the sdf.
    void Load(physics::ModelPtr model, sdf::ElementPtr sdf);

    // Update the torque on the joint from the dc motor each timestep.
    void Update(const common::UpdateInfo& info);

    private:
      // Topic to read control signal from.
      std::string topic;

      // The pwm signals limited to the range [-1,1].
      float left_signal;
      float right_signal;

      // The magic torque multiplier. torque=multiplier*signal
      float multiplier;

      // Joints to drive
      physics::JointPtr left_joint;
      physics::JointPtr right_joint;

      // Callback for receiving msgs and storing the signal.
      void Callback(const ConstMotorsCommandPtr& msg);

      // The model to which this is attached.
      physics::ModelPtr model;

      //  Pointer to the world update function.
      event::ConnectionPtr updateConn;

      // The node on which we're advertising.
      transport::NodePtr node;

      // Subscriber handle.
      transport::SubscriberPtr sub;
  };

}
