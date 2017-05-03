#!/bin/bash
~/v4l2rtspserver/v4l2rtspserver -W 1920 -H 1080 -F 60 -P 8554 /dev/video0 > /dev/null 2>&1
