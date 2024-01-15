# QMK Mad Noodle Keypads Repository

Welcome to the official repository for QMK firmware source files and comprehensive documentation for all Mad Noodle Keypads. This repository contains the fully updated source `keyboard` folder for QMK firmware, compiled default firmware, and detailed documentation for each Mad Noodle Keypad model. Start by using the provided keymaps as a foundation to customize your own unique layout.
<br>

(_Last tested with QMK v0.23.5_)

![Mad Noodle Keypads](https://static.wixstatic.com/media/59d0ff_93217686786e482a95893e8f7949bd16~mv2.png)


 **For FULL, detailed instructions on how to create, modify, and compile QMK firmware, Please visit https://docs.qmk.fm/**
 <br>
 
> [!TIP]
> If you are looking for an option with a much simpler configuration experience, explore our [Mad Noodle Via](https://github.com/The-Mad-Noodle/Mad-Noodle-Via-Support) Github!
 <br>
 
## QMK Setup Instructions


#### Installing current Mad Noodle keyboard folder to QMK firmware



1. Vist [QMK's Github](https://github.com/qmk/qmk_firmware) and clone or download current release
<sup>Optional (If your local QMK is not up to date with the current release)
2. Place or clone the `qmk_firmware` folder into the directory you plan on working out of.
3. Copy the entire `/QMK-Mad-Noodle-KeyPads/themadnoodle` folder to `qmk_firmware/keyboards` directory of the QMK firmware you just downloaded

Then you're good to go! <br>
Modify your keymaps to your desired layout and follow the instructions on https://docs.qmk.fm/ to compile your new firmware.

> After setting up your [Build Environment](https://docs.qmk.fm/#/getting_started_build_tools?id=set-up-your-environment)

Compile example:

    qmk compile -kb themadnoodle/noodlepad/v2 -km default

Flashing example:

    qmk flash -kb themadnoodle/noodlepad/v2 -km default

See the [Build Your Firmware](https://docs.qmk.fm/#/newbs_building_firmware?id=build-your-firmware) and the [Flashing Your Keyboard](https://docs.qmk.fm/#/newbs_flashing) guides for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

<br>
<br>

# Flashing Firmware To Your Mad Noodle Keypad
![Mad Noodle Keypads Buttons](https://static.wixstatic.com/media/59d0ff_fe5dde7e57db4453997a9c992eb7ae02~mv2.png)
## Flashing Keypads with ATMEGA32U4 Chip
> [!NOTE]
> **This only applies to keypads made _BEFORE_ 2024.**
> - NCC1701KB v2
> - Noodlepad v1 & v2
> - Udon:13
<br>

### Flashing Keypads with ATMEGA32U4 Chip and Enabling "DFU Mode" or "Flash Mode"

1. Connect the keypad to your computer via a USB-C Cable (not included).
2. Open QMK Toolbox software (If not already downloaded, please see https://qmk.fm/toolbox/).
3. Press the `RESET` button located on the bottom of the keypad (Top left corner, to the left of the USB connector) labeled RST.
4. In your QMK Toolbox Consol, you should see `*** DFU device connected:` appear.
5. Under `Local File` open your compliled HEX file.
6. Ensure `Microcontroller` is set to atmega32u4.
7. Click the `Flash` button to begin flashing process.
8. When the flashing is complete, your console should show an indication of a successful flash and the device will disconnect.

Congrats! Your keypad is now successfully flashed with your new Keymap! 

## Flashing Keypads with RP2040 Chip
> [!NOTE]
> **This only applies to keypads made _AFTER_ 2024.**
> - NoodlePad[Micro]
<br>

### Flashing Keypads with RP2040 Chip, and Enabling "Bootloader Mode"

#### If You Already Have A Compiled .u2f File:

1. Connect the keypad to your computer via a USB-C Cable (not included).
2. Quickly double-press the reset button on the back, center, left of the PCB labeled **"R"** to enter the bootloader drive mode.
3. When in **Bootloader Mode**, A drive named `RPI-RP2` will appear on your computer.
4. Copy the compiled .u2f file (I.E. `themadnoodle_noodlepad_micro_default.uf2`) into `RPI-RP2` drive.
5. Once finished copying, the drive will close, and your keypad will restart with the new firmware.

Congrats! Your keypad is now successfully flashed with your new firmware!

#### Flashing Your Keypad using QMK MSYS or Terminal

1. Ensure your _Build Enviroment_ is setup correctly. 
    - See the [Prepare Your Build Environment](https://docs.qmk.fm/#/getting_started_build_tools?id=set-up-your-environment) section on docs.qmk.fm/
2. In your console, type `qmk flash -kb themadnoodle/<keyboard> -km <Keymap>`
    >  Example: `qmk flash -kb themadnoodle/noodlepad_micro -km default`
3. Wait for your firmware to compile. Then you'll be prompted with:
    >Flashing for bootloader: rp2040<br>
    >Waiting for drive to deploy...
4. Quickly double-press the reset button on the back, center, left of the PCB labeled **"R"** to enter the bootloader drive mode and the flashing will begin. 

Congrats! Your keypad is now successfully flashed with your new firmware!
<br>
<br>
> [!TIP]
> If you are having issues, feel free to reach out via our contact form at https://www.themadnoodle.com/contact
