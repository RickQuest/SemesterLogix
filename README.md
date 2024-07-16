# SemesterLogix

## Overview
SemesterLogix is a tool I developed during my time as a student at École de technologie supérieure (ETS) to address the absence of an official school schedule generator. Previously, the only available tool was hosted by a former student and often crashed under heavy usage. In contrast, SemesterLogix runs locally and provides a basic, robust option for creating school schedules.

## Features
- **Local Execution**: Runs on your local machine without the need for an internet connection once set up.
- **Simple Interface**: Easily select your school and upload course schedules directly.
- **Stability**: Designed to handle the initial load without crashing, ensuring reliability during critical scheduling periods.

## Requirements
To run SemesterLogix effectively, you will need the following:

- **Operating System**: Windows
- **Software Dependencies**:
  - [Qt 5.15](https://www.qt.io/download) for the GUI and application logic. More recent version of Qt are not tested.
  - Qt Extension for Visual Studio
  - Xpdf for extracting information from course schedule. It is included in the repo and the application use it automatically. you don't need to do anything. 

### Installation
1. **Clone the repository**
2. **Open the project solution in Visual Studio (2019 and 2022 version are tested and functionnal) and make sure those project properties are correctly set :**
   - Qt Project Settings => Qt Installation : 5.15.0_msvc2019_64
   - Qt Project Settings => Qt Modules : charts;core;network;qml;quick;widgets
   - Qt Project Settings => MOC Macro Names : Q_OBJECT;Q_GADGET;Q_NAMESPACE;Q_NAMESPACE_EXPORT
   - C/C++ => General => Additional Include Directories : C:\Qt\5.15.0\msvc2019_64\include (or where your Qt installation is)
   - Linker => General => Additional Library Directories : C:\Qt\5.15.0\msvc2019_64\lib (or where your Qt installation is)
   - Linker => Input => Additional Dependencies : Qt5Core.lib;Qt5Gui.lib;Qt5Widgets.lib;Qt5Qml.lib;Qt5Quick.lib
3. **Go to Qt extension option and set Qt version to 5.15.0_msvc2019_64 by pointing to "C:\Qt\5.15.0\msvc2019_64" folder (or where your Qt installation is).**

### Precompiled Binaries
If you do not wish to compile the app from source, you can download precompiled binaries available in the [Releases](https://github.com/RickQuest/SemesterLogix/releases) section.

### Usage
1. **Start the application**:
2. **Select ETS school from the dropdown menu**.
3. **Upload the course schedule file** downloaded from the ETS website.
4. **Select the course you possibly want and the number of course by schedule.** 
