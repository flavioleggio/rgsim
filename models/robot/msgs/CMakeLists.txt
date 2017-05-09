find_package(Protobuf REQUIRED)

set(PROTOBUF_IMPORT_DIRS)
foreach(ITR ${GAZEBO_INCLUDE_DIRS})
  if(ITR MATCHES ".*gazebo-[0-9.]+$")
    set(PROTOBUF_IMPORT_DIRS "${ITR}/gazebo/msgs/proto")
  endif()
endforeach()

set(encoders_proto EncoderMsg.proto)
set(motors_proto MotorsCommand.proto)

protobuf_generate_cpp(ENCODERS_SRCS ENCODERS_HDRS ${encoders_proto})
protobuf_generate_cpp(MOTORS_SRCS MOTORS_HDRS ${motors_proto})

add_library(encoders_msgs SHARED ${ENCODERS_SRCS})
add_library(motors_command_msgs SHARED ${MOTORS_SRCS})
target_link_libraries(encoders_msgs ${PROTOBUF_LIBRARY})
target_link_libraries(motors_command_msgs ${PROTOBUF_LIBRARY})
