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