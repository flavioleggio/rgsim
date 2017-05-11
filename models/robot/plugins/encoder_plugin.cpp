#include "encoder_plugin.h"

using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(Encoder)

void Encoder::Load(physics::ModelPtr model, sdf::ElementPtr sdf) {
  this->model = model;

  // Parse SDF properties
  left_joint = model->GetJoint("left_encoder");
  right_joint = model->GetJoint("right_encoder");

  topic = "~/encoders";

  gzmsg << "Initializing encoders: " << topic
        << " left_joint=" << left_joint->GetName()
        << " right_joint=" << right_joint->GetName() << std::endl;

  // Connect to Gazebo transport for messaging
  node = transport::NodePtr(new transport::Node());
  node->Init(model->GetWorld()->GetName());
  pub = node->Advertise<msgs::EncoderMsg>(topic);

  // Connect to the world update event.
  // This will trigger the Update function every Gazebo iteration
  updateConn = event::Events::ConnectWorldUpdateBegin(boost::bind(&Encoder::Update, this, _1));
}

void Encoder::Update(const common::UpdateInfo& info) {
  msgs::EncoderMsg msg;
  msg.set_timestamp(model->GetWorld()->GetSimTime().Float());
  msg.set_left_angle(left_joint->GetAngle(0).Radian());
  msg.set_right_angle(right_joint->GetAngle(0).Radian());
  msg.set_left_velocity(left_joint->GetVelocity(0));
  msg.set_right_velocity(right_joint->GetVelocity(0));

  /*
  gzmsg << "Encoder message: " << std::endl
        << "timestamp= " << msg.timestamp()
        << " left_angle=" << msg.left_angle()
        << " right_angle=" << msg.right_angle()
        << " left_velocity=" << msg.left_velocity()
        << " right_velocity=" << msg.right_velocity() << std::endl;
  */

  pub->Publish(msg);
}
