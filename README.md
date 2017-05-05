# **rgsim**
Rover on Gazebo simulator to test and develop navigation strategies.

### **System configuration**
First, you have to **install** the Gazebo development package for your linux distribution.
###### Ubuntu:
```
sudo apt-get update
sudo apt-get install libgazebo8-dev
```
###### Debian:
```
sudo apt-get install libgazebo5-dev
```
###### Fedora:
```
sudo dnf install gazebo-devel-7.4.0-2.fc25.x86_64
```
###### Other distributions:
You can find the correct version for your distribution on the official [gazebosim website](http://gazebosim.org/tutorials?cat=install)

### **Verify your installation**
To verify if gazebo has been correctly installed on your system, you can start gazebo by entering on a terminal the simple command
```
gazebo
```
or you can try to load a preset world with a pioneer2dx model with the command
```
gazebo worlds/pioneer2dx.world
```

### **Compile the project**
```
cd ~/path/to/rgsim/
mkdir build
cd build/
cmake ..
make
```

### **Start the simulation**
To run the whole simulation you can simply execute the bash script runsim.sh
```
cd ~/path/to/rgsim/
./runsim.sh
```

The script executes in your place the standard procedure for running a simulation.
Just for reference purposes, the **procedure** is explained below.
First you have to set up the environment variables.
```
source /usr/share/gazebo/setup.sh
```
Then you have to export the environment variables for models and worlds.
```
export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/path/to/rgsim/models
export GAZEBO_RESOURCE_PATH=${GAZEBO_RESOURCE_PATH}:~/path/to/rgsim/worlds
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/path/to/rgsim/build/models/robot
```
To run the simulation you can enter the command
```
gazebo worlds/rgsim.world
```
