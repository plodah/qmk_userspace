#!/usr/bin/env bash

set -eEuo pipefail
# mkdir -p /workspaces/qmk_firmware /workspaces/via_userspace /workspaces/via_keyboards /workspaces/qmk_firmware_upstream

wget https://bootstrap.pypa.io/get-pip.py
python3 get-pip.py
python3 -m pip install qmk
rm get-pip.py

python3 -m pip install --upgrade milc

userspacePath="$1"

git config --global --add safe.directory "$userspacePath"
git submodule update --init --recursive

### Clone Firmware Repos
[ -d /workspaces/qmk_qmk_firmware ] || git clone https://github.com/qmk/qmk_firmware.git -b master /workspaces/qmk_qmk_firmware
git config --global --add safe.directory /workspaces/qmk_qmk_firmware
cd /workspaces/qmk_qmk_firmware
git submodule update --init --recursive

[ -d /workspaces/plodah_qmk_firmware ] || git clone https://github.com/plodah/qmk_firmware.git -b mybuilds-2025-03-20 /workspaces/plodah_qmk_firmware
git config --global --add safe.directory /workspaces/plodah_qmk_firmware
cd /workspaces/plodah_qmk_firmware
git submodule update --init --recursive

[ -d /workspaces/vial_qmk_firmware ] || git clone https://github.com/vial-kb/vial-qmk.git -b vial /workspaces/vial_qmk_firmware
git config --global --add safe.directory /workspaces/vial_qmk_firmware
cd /workspaces/vial_qmk_firmware
git submodule update --init --recursive

[ -d /workspaces/keychron_qmk_firmware ] || git clone https://github.com/Keychron/qmk_firmware.git -b wireless_playground /workspaces/keychron_qmk_firmware
git config --global --add safe.directory /workspaces/keychron_qmk_firmware
cd /workspaces/keychron_qmk_firmware
git submodule update --init --recursive

### Via Stuff
[ -d /workspaces/via_userspace ] || git clone https://github.com/the-via/qmk_userspace_via.git -b main /workspaces/via_userspace
git config --global --add safe.directory /workspaces/via_userspace

[ -d /workspaces/via_keyboards ] || git clone https://github.com/the-via/keyboards.git -b master /workspaces/via_keyboards
git config --global --add safe.directory /workspaces/via_keyboards

### qmk configs
cd $userspacePath
qmk config user.qmk_home=/workspaces/plodah_qmk_firmware
qmk config user.overlay_dir="$userspacePath"
qmk git-submodule -f
