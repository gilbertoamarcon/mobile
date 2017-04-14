# Steps to configure the LAN, video feed and SSH into PI

# 1) Setup a local wireless network.
	# In this example we use a Win10 Laptop to setup a mobile hotspot with gateway address 
	192.168.137.1
# 2) Connect the PI to the local wireless network.
# 3) To set a fixed IP address to PI, edit the network file:
	sudo nano /etc/dhcpcd.conf
	# Add the following lines:
	# Fixed LAN IP Address
	interface wlan0
	static ip_address=192.168.137.2/24
	static routers=192.168.137.1
	static domain_name_servers=192.168.137.1
# 3) To name raspberry as rasp on the host network:
# 	On the host computer, edit the hosts file under
	C:\Windows\System32\drivers\etc\hosts
	# Add the following line at the end of the file:
	192.168.137.2 rasp
# 4) To SSH into rasp go to putty and use rasp as hostname and keep port 22.
	# Click open and login:
	login as: pi
	password: mobilerobotics
# 5) To get the video feed on the host computer, start VLC, click Media -> Open network stream, and enter
	rtsp://rasp:8554/unicast
