# Udon:13 v.2

![Udon:13 v2](https://i.imgur.com/2APzX6M.jpg)

The Udon:13 v.2 is and updated version of its predecessor, A 12 Key, 1 Encoder Premium Macro Keypad, designed using RP2040 chipset.

* Keyboard Maintainer: [The Mad Noodle](https://github.com/The-Mad-Noodle)
* Hardware Supported: Udon:13 v.2
* Hardware Availability: https://www.themadnoodle.com/shop

Compile example for this keyboard (after setting up your build environment):

    qmk compile -kb themadnoodle/udon13/v2 -km default

Flashing example for this keyboard:

    qmk flash -kb themadnoodle/udon13/v2 -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader & Flashing


**Physical Boot button**: 

* While holding the "BOOT" Button below the USB connector on the back of the PCB, plug in your keypad. This will enter the bootloader drive mode.

* If you have a pre-compiled .uf2 file, copy it into bootloader drive (RPI-RP2), board will reset automatically once file is copied sucessfully