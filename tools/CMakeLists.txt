add_executable(motors_test motors_test.cpp)
target_link_libraries(motors_test motors_command_msgs ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES})
