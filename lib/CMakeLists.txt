add_library(control_interface SHARED control_interface.cpp)
add_library(telem_interface SHARED telem_interface.cpp)
target_link_libraries(control_interface motors_command_msgs ${GAZEBO_LIBRARIES})
target_link_libraries(telem_interface encoders_msgs ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES})
