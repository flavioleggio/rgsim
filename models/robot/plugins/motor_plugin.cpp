#include "motor_plugin.h"

using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(DCMotor)

void DCMotor::Load(physics::ModelPtr model, sdf::ElementPtr sdf) {
  this->model = model;
  left_signal = 0;
  right_signal = 0;

  // Parse SDF properties
  left_joint = model->GetJoint("left_wheel_hinge");
  right_joint = model->GetJoint("right_wheel_hinge");

  topic = "~/motors_control";

  multiplier = sdf->Get<float>("multiplier");

  gzmsg << "Initializing motors: " << topic
        << " left_joint=" << left_joint->GetName()
        << " right_joint=" << right_joint->GetName()
        << " multiplier=" << multiplier << std::endl;

  // Connect to Gazebo transport for messaging
  node = transport::NodePtr(new transport::Node());
  node->Init(model->GetWorld()->GetName());
  sub = node->Subscribe(topic, &DCMotor::Callback, this);

  // Connect to the world update event.
  // This will trigger the Update function every Gazebo iteration
  updateConn = event::Events::ConnectWorldUpdateBegin(boost::bind(&DCMotor::Update, this, _1));
}

void DCMotor::Update(const common::UpdateInfo& info) {
  left_joint->SetForce(0, left_signal * multiplier);
  right_joint->SetForce(0, right_signal * multiplier);
}

void DCMotor::Callback(const ConstMotorsCommandPtr& msg) {
  left_signal = msg->left_torque();

  if (left_signal < -1) {
    left_signal = -1;
  } else if (left_signal > 1) {
    left_signal = 1;
  }

  right_signal = msg->right_torque();

  if (right_signal < -1) {
    right_signal = -1;
  } else if (right_signal > 1) {
    right_signal = 1;
  }
}
