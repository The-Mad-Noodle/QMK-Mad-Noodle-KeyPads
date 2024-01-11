# QMK Mad Noodle KeyPads
The updated repository for all of the Mad Noodle Keypads QMK source files and Documentation

![Mad Noodle Keypads](https://static.wixstatic.com/media/59d0ff_93217686786e482a95893e8f7949bd16~mv2.png)


 Fully updated Source `keyboard` folder for QMK firmware, Compiled Default Firmware, and Documentation for every Mad Noodle Keypad.  
 Use the included keymaps as a template to create your own!


 **For FULL, detailed instructions on how to create, modify, and compile QMK firmware, Please visit https://docs.qmk.fm/**
 <br>

> **If you are looking for a much simpler option check out our [Mad Noodle Via](https://github.com/The-Mad-Noodle/Mad-Noodle-Via-Support) Github!**

## QMK Setup Instructions


#### Installing current Mad Noodle keyboard folder to QMK firmware



1. Vist [QMK's Github](https://github.com/qmk/qmk_firmware) and clone download current release
<sup>Optional (If your QMK is not up to date with the current release):
2. Place the entire `qmk_firmware` in the directory you plan on working out of
3. Copy the entire `/QMK-Mad-Noodle-KeyPads/themadnoodle` folder to `qmk_firmware/keyboards` directory of the QMK firmware folder you just downloaded

Then you're good to go! <br>
Modify your keymaps to your desired layout and follow the instructions on https://docs.qmk.fm/ to compile your new firmware.

Compile example (after setting up your build environment):

    qmk compile -kb themadnoodle/noodlepad/v2 -km default

Flashing example:

    qmk flash -kb themadnoodle/noodlepad/v2 -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


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
7. Click the `Flash` button to begin flashing your keypad with the selected HEX file.
8. When the flashing is complete, your console should show an indication of a successful flash and the device disconnected.
9. Congrats! Your keypad is now successfully flashed with your new Keymap! 

## Flashing Keypads with RP2040 Chip
> [!NOTE]
> **This only applies to keypads made _AFTER_ 2024.**
> - NoodlePad[Micro]
<br>

### Flashing Keypads with RP2040 Chip, and Enabling "Bootloader Mode"

#### If You Already Have A Compiled .u2f File:

1. Connect the keypad to your computer via a USB-C Cable (not included).
2. Double press the button on the back, center, left of the PCB labeled **"R"** to enter the bootloader drive mode.
3. When in **Bootloader Mode**, on your computer a new drive is created called `RPI-RP2`
4. Copy the compiled .u2f file (I.E. `themadnoodle_noodlepad_micro_default.uf2`) into `RPI-RP2` drive.
5. Once finished copying, the drive will close, and your keypad will reset automatically.
6. Congrats! Your keypad is now successfully flashed with your new firmware!

#### Flashing Your Keypad using QMK MSYS or Terminal

1. Ensure your _Build Enviroment_ is setup correctly. 
    - See the [Prepare Your Build Environment](https://docs.qmk.fm/#/getting_started_build_tools?id=set-up-your-environment) section on docs.qmk.fm/
2. In your console, type `qmk flash -kb themadnoodle/{Keyboard} -km {Keymap}`, I.E., `qmk flash -kb themadnoodle/noodlepad_micro -km default`
3. Wait for your firmware to compile. Then you'll be prompted with:
    >Flashing for bootloader: rp2040<br>
    >Waiting for drive to deploy...
4. Double press the button on the back, center, left of the PCB labeled **"R"** to enter the bootloader drive mode and the flashing will begin. 
5. Congrats! Your keypad is now successfully flashed with your new firmware!
<br>
<br>

>If you are having issues, feel free to reach out via our contact form at https://www.themadnoodle.com/contact
