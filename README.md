# mobile

This is a complete system for a teleoperated skid-steering mobile rover based on Raspberry Pi 3.
Scripts included allow:
  - Setting up a fast video server using the Raspberry camera that can be used for teleoperation over a wifi LAN using VLC. 
  - Sending in movement commands for teleoperating the rover using wifi SSH or Bluetooth.

https://www.youtube.com/watch?v=b43DRCnoCUY&t=624s

To setup the Bluetooth command line control, follow the instructions under setup/bt.
To setup the video server for remotely viewing the camera over wifi, follow the instructions under setup/uv4l.
Use ./build to build the C motor driver. 
To teleoperate:
  - First, start the motor driver and the video server using init_teleop.sh; then
  - Run teleop.sh from the remote computer using SSH or via Bluetooth to drive the rover. 
Both steps can be performed remotely, over wifi or Bluetooth. 
 
