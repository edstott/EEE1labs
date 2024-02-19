# Running Issie designs on hardware
# Section 1: Getting Started

Issie has an experimental feature that allows you to turn your designs into a configuration for a *field-programmable gate array* (FPGA).
A FPGA is a silicon chip that contains a large number of logic gates that can be programmed with any truth table.
There is also a wiring matrix that can connect gates together in any configuration, plus registers and blocks of RAM for storing data.

The IssieStick FPGA module is designed to support digital design in Issie.
It contains a [Lattice ICE40](https://www.latticesemi.com/iCE40) FPGA with 7680 *Lookup Tables*, each of which can implement a logic gate with up to 4 inputs.
There is also an array of 256 RGB LEDs and 5 push buttons.

## Preparing your computer

Issie uses some open source drivers and tools to synthesise your design (convert it into an FPGA configuration) and load it onto hardware.
These are not yet fully integrated with Issie so some setup is required:

1. Download [OSS CAD Suite](https://github.com/YosysHQ/oss-cad-suite-build).
   1. Go to [latest release](https://github.com/YosysHQ/oss-cad-suite-build/releases/latest) and download the appropriate file for your computer.
   2. Extract the archive:
      * On Windows, move the `.exe` file that you just downloaded to a location with a simple file path, like `C:\oss-cad-suite`, then run it and it will download and extract the archive. Your antivirus software or Windows Defender may block you from doing this. If so, you can safely ignore the warning (for Windows Defender, click "more info" and then "Run anyway").
      * On Linux, you will have downloaded a `.tgz` file. You can extract this file using a terminal with `tar -xvzf /path/to/archive.tgz`.
      * On Mac (Darwin), the download is also a `.tgz`, but can be extracted by just double-clicking it.

2. (Windows only) Install the IssieStick USB drivers.
   1. Download the [driver package](https://imperiallondon-my.sharepoint.com/:f:/g/personal/estott_ic_ac_uk/EpW6CD_3qMFEvWoke3HdNNkBkpuhFE7J5IlhhqzU6c8S9w?e=xxHytz) and extract the files
   2. Run 'InstallDriver' in both of the IssieStickInstaller directories

## Running the sample project

This repository contains an example project which displays a counter on the LED array.

1. [Download](https://github.com/edstott/EEE1labs/archive/refs/heads/main.zip) and unzip this repository
1. Load the environment for OSS CAD Suite
   1. In Windows, run `start.bat` in the main directory for OSS. This will open a terminal with the environment already loaded.
   2. In Mac or Linux, start a terminal and run `source <extracted_location>/oss-cad-suite/environment`. `<extracted location>` is the parent for OSS
   * OSS GitHub has [full instructions](https://github.com/YosysHQ/oss-cad-suite-build#installation)
2. Run Issie in the same terminal. In Windows, `start.bat` creates a terminal for you. You'll need to change to the directory where you have extracted Issie and run `Issie`.
3. In Issie, open the 'LEDCounter' [project](downloads/LEDCounter). Open the `main` sheet. You will always need to return to `main` after editing another sheet because Issie will always try to compile the current sheet.
5. The FPGA build options are hidden by default. Enable them by clicking View -> Show/Hide Build Tab. Open the build Tab.
   * There is a bug in Issie where if you are on the Simulations tab, then clicking on the build tab will not work. Just click on one of the other tabs first, and it should work.
6. Under 'Device Selection', choose 'IssieSick v1.0'.
7. Click 'Build and upload'.

After all the stages successfully complete you will see digits counting on the LED array.
You can reset the counter by pushing the centre button.

## Build errors

The hardware build system does not yet produce meaningful errors, partially because it uses third-party tools.

### Synthesis fails
The synthesis step can fail for the following reasons:

- There are errors in your sheets. Go to the simulation tab and check that simulation is available. If not, fix the errors that are reported
- The project is stored in a directory path that contains spaces. In OneDrive for Windows, you can work around this without moving your files by creating a link to your Issie project directory with a different path. [This guide tells you how](https://blog.jongallant.com/2020/01/onedrive-rename-remove-spaces-from-folder-name/).
- Issie is stored in a directory path that contains spaces. Move it to a path with no spaces.
- OSS tools are not available. Make sure you run Issie in the OSS environment as described above every time you want to build. Running Issie directly (and not through the OSS environment terminal) will **not** work.
- (Mac only) Your project folder does not contain the 'hdl' folder with the build dependencies.
- (Failure after running for several minutes) Your design contains a large asynchronous ROM or RAM, which can't be implemented efficiently on the FPGA. Use a synchronous memory or smaller memory instead.

### Place and route fails
The place and route step can fail for the following reasons:

- You are trying to build a sheet that isn't the main sheet.
- Your sheet contains port names that don't exist on the IssieStick. Refer to the example projects to see the correct port names.
- Your design is too complex for the FPGA. This may be due to an asynchronous ROM or RAM.

### Upload fails
The upload step can fail for the following reasons:

- The IssieStick isn't connected
- (Windows only) The USB driver is not installed
