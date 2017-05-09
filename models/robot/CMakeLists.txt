include(FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GAZEBO gazebo)
  pkg_check_modules(SDF sdformat)
endif()

add_subdirectory(msgs)

link_directories(${GAZEBO_LIBRARY_DIRS} ${CMAKE_CURRENT_BINARY_DIR}/msgs)

add_library(encoder_plugin SHARED plugins/encoder_plugin.cpp)
add_library(motor_plugin SHARED plugins/motor_plugin.cpp)
target_link_libraries(encoder_plugin encoders_msgs ${GAZEBO_LIBRARIES} ${SDF_LIBRARIES})
target_link_libraries(motor_plugin motors_command_msgs ${GAZEBO_LIBRARIES} ${SDF_LIBRARIES})
add_dependencies(motor_plugin motors_command_msgs)
add_dependencies(encoder_plugin encoders_msgs)
