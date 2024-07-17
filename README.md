
# SemesterLogix

## Overview
SemesterLogix was developed during my time at École de technologie supérieure (ETS) as a response to the lack of an official tool for generating school schedules. The existing tools, including one hosted by a former student, frequently crashed under heavy usage. In contrast, SemesterLogix runs locally, providing a stable and straightforward option for managing school schedules.

## Features
- **Local Execution**: Runs locally without requiring an internet connection once set up.
- **Simple Interface**: Allows easy selection of schools and uploading of course schedules.
- **Stability**: Built to handle high loads without crashing, ensuring reliability during critical scheduling periods.

## Requirements
To effectively run SemesterLogix, you will need:
- **Operating System**: Windows
- **Software Dependencies**:
  - [Qt 5.15](https://www.qt.io/download) for GUI and application logic. Note: Versions newer than Qt 5.15 are not tested.
  - Qt Extension for Visual Studio
  - Xpdf (included in the repo) for extracting information from PDF course schedules.

## Installation
1. **Clone the repository**:
   ```bash
   git clone https://github.com/RickQuest/SemesterLogix.git
   ```
2. **Open the project solution in Visual Studio (2019 or 2022) ensuring the following settings:**
   - **Qt Project Settings**: 
     - Qt Installation: `5.15.0_msvc2019_64`
     - Qt Modules: `charts; core; network; qml; quick; widgets`
     - MOC Macro Names: `Q_OBJECT; Q_GADGET; Q_NAMESPACE; Q_NAMESPACE_EXPORT`
   - **C/C++ General**:
     - Additional Include Directories: `C:\Qt\5.15.0\msvc2019_64\include` (adjust as per your Qt installation path)
   - **C/C++ Preprocessor**:
     - Preprocessor Definitions: `SOLUTION_DIR=R"$(SolutionDir)";%(PreprocessorDefinitions)`
   - **Linker General**:
     - Additional Library Directories: `C:\Qt\5.15.0\msvc2019_64\lib` (adjust as per your Qt installation path)
   - **Linker Input**:
     - (RELEASE) Additional Dependencies: `Qt5Core.lib;Qt5Gui.lib;Qt5Widgets.lib;Qt5Qml.lib;Qt5Quick.lib`
     - (DEBUG) Additional Dependencies: `Qt5Cored.lib;Qt5Guid.lib;Qt5Widgetsd.lib;Qt5Qmld.lib;Qt5Quickd.lib`
3. **Set the Qt version in the Qt extension options to `5.15.0_msvc2019_64` pointing to your Qt installation folder.**
4. **For Release Builds**:
   - Navigate to your project's Release directory:
     ```bash
     cd path\to\project\x64\Release
     ```
     and deploy Qt libraries:
     ```bash
     C:\Path\To\Qt\bin\windeployqt.exe --qmldir <path_to_your_qml_sources> SemesterLogix.exe
     ```
     here's the command for common configuration : 
     ```bash
     C:\Qt\5.15.0\msvc2019_64\bin\windeployqt.exe --qmldir C:\Qt\5.15.0\msvc2019_64\qml SemesterLogix.exe
     ```
     

## Precompiled Binaries
If you prefer not to compile the app from source, precompiled binaries are available in the [Releases](https://github.com/RickQuest/SemesterLogix/releases) section.

## Usage
1. **Launch the application.**
2. **Select 'ETS' from the school dropdown menu.**
3. **Upload the course schedule file obtained from the [ETS course schedule page](https://www.etsmtl.ca/etudier-a-lets/inscription-aux-cours/horaire-cours).**
4. **Choose the desired courses and the number of courses per schedule.**

## Support
For support, feature requests, or bug reporting, please open an issue through the GitHub issue tracker associated with this repository.
