#!/bin/bash
source /usr/share/gazebo/setup.sh

export GAZEBO_RESOURCE_PATH=${GAZEBO_RESOURCE_PATH}:/home/flavio/Scrivania/Workspace/rgsim/worlds
export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:/home/flavio/Scrivania/Workspace/rgsim/models
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/flavio/Scrivania/Workspace/rgsim/build/models/robot

gazebo worlds/rgsim.world
