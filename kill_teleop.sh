#!/bin/bash
## Kill all teleop spawned processes

pkill driver

# Kill video network stream
pkill raspivid
pkill nc
