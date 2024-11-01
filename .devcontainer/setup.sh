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

[ -d /workspaces/via_userspace ] || git clone https://github.com/the-via/qmk_userspace_via.git -b main /workspaces/via_userspace
git config --global --add safe.directory /workspaces/via_userspace

qmk config user.qmk_home=/workspaces/qmk_firmware
qmk config user.overlay_dir="$userspacePath"

qmk git-submodule

[ -d /workspaces/via_keyboards ] || git clone https://github.com/the-via/keyboards.git -b master /workspaces/via_keyboards
git config --global --add safe.directory /workspaces/via_keyboards

[ -d /workspaces/qmk_firmware_upstream ] || git clone https://github.com/plodah/qmk_firmware.git -b master /workspaces/qmk_firmware_upstream
git config --global --add safe.directory /workspaces/qmk_firmware_upstream
cd /workspaces/qmk_firmware_upstream
git submodule update --init --recursive
