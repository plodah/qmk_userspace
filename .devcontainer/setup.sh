#!/usr/bin/env bash

set -eEuo pipefail

wget https://bootstrap.pypa.io/get-pip.py
python3 get-pip.py
python3 -m pip install qmk
rm get-pip.py

python3 -m pip install --upgrade milc

userspacePath="$1"

git config --global --add safe.directory "$userspacePath"
git submodule update --init --recursive

[ -d /workspaces/qmk_firmware ] || git clone https://github.com/plodah/qmk_firmware.git -b mybuilds-2024-09 /workspaces/qmk_firmware
git config --global --add safe.directory /workspaces/qmk_firmware

[ -d /workspaces/via_userspace ] || git clone https://github.com/the-via/qmk_userspace_via.git -b main /workspaces/via-userspace
git config --global --add safe.directory /workspaces/via-userspace

[ -d /workspaces/via_userspace ] || git clone https://github.com/the-via/keyboards.git -b master /workspaces/via-keyboards
git config --global --add safe.directory /workspaces/via-keyboards

qmk config user.qmk_home=/workspaces/qmk_firmware
qmk config user.overlay_dir="$userspacePath"

qmk git-submodule
