## Design

### Requirements

There are several basic requirements that must be fulfilled to make the watch at least as good as a normal (smart) watch that should be implemented first. Then there are nice to have features that can be implemented after.

Basic requirements:
* Must be able to tell the time accurately.
* Must have >10 days battery life.
* Must be water-resistant or water-proof.
* Must have a working touch screen.
* Must be able to connect to another device over bluetooth.

Other requirements:
* GNSS position and time
* Heart rate + SpO2 sensors
* SD card for data & graphic storage
* Microphone
* Compass
* IMU gesture detection
* Swappable modules (for RFID, LoRa, USB-C etc)

### Frame Selection

The frame for the project was chosen to be the AGPTEK LW11 for its low price and metal frame. Other options were considered like the SENBONO NY20, but were dismissed due to their inferior build quality.

![LW11_smart_watch](/Documentation/Images/LW11_smart_watch.png)

A full dissassembly of the LW11 can be found [here](/Documentation/LW11%20Disassembly.md).

### Display Selection

The display chosen was the [U128BLX03.2](/Documentation/Display/U128BLX03%202_Product%20Spec1.pdf) for its high resolution (416x416 pixels) and low power consumption due to being an [AMOLED](https://en.wikipedia.org/wiki/AMOLED) display. It is the right size for the frame (1.28") and has a MIPI DSI interface with a single data pair.

### Main Board

After the frame and display were selected, the shape of the main PCB and connector locations were known, and therefore component selection and board design could begin.

* [Main board schematic](/PCBs/watch_main_v2/watch_main.pdf) 

![main_board_v2_front](/Documentation/Images/main_board_v2_front.png)