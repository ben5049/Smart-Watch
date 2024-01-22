# PCBs

## Core PCBs

* [Main board v2](/PCBs/watch_main_v2/) - display controller, power, wireless and most other features.
* [Lower flex](/PCBs/watch_lower/) - flexible PCB with heart rate sensor, power input and haptic motor.
* [Main board test rig v2](/PCBs/watch_test_rig_v2/) - pogo pin connectors for the main board, used for programming and debugging.
* [Main board test rig v2 support](/PCBs/watch_test_rig_support/) - adds mechanical support to the pogo pins of the main board test rig v2.

## Module PCBs
* [RFID module v1.1](/PCBs/rfid_module_v1.1/) - 125kHz RFID reciever and transmitter, based on the [Flipper Zero](https://docs.flipper.net/development/hardware/schematic/).
* [LoRa module](/PCBs/lora_module/) - LoRa reciever and transmitter using an STM32WL.
* [USB module](/PCBs/usb_module/) - Adds a USB-C port for charging and data.
* [Module test rig](/PCBs/module_test_rig/) - pogo pin connectors for modules, used for programming and debugging.

## Archived PCBs
* [Main board v1](/PCBs/archived/watch_main_v1/) - deprecated due to new screen with a different connector.
* [Main board test rig v1](/PCBs/archived/watch_test_rig%20v1/) - deprecated with main board v1.
* [RFID module v1.1](/PCBs/archived/rfid_module_v1/) - deprecated due to inefficient routing (high layer count), and being the wrong dimensions.

## Library

[/component_library](/PCBs/component_library/) contains all the symbols, footprints, 3D models and drawings used in the PCBs. Projects all use relative paths to the library with ```../${KIPRMOD}/``` and as such are portable between devices as long as the folder structure is the same.