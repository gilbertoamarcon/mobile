#!/bin/bash
## Kill all teleop spawned processes

pkill driver
pkill v4l2rtspserver
pkill uv4l

# Kill video network stream
pkill raspivid
pkill nc
