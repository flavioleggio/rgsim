add_executable(telem_test telem_test.cpp)
add_executable(motors_test motors_test.cpp)
target_link_libraries(telem_test telem_interface)
target_link_libraries(motors_test motors_command_msgs control_interface ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES})
