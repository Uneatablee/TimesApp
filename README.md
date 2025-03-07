# **Time'sApp**
![Project Status](https://img.shields.io/badge/status-early--development-yellow)

- [**Time'sApp**](#timesapp)
  - [About](#about)
  - [System Requirements](#system-requirements)
  - [Installation](#installation)
  - [Git workflow](#git-workflow)

## About
> [!WARNING]
> **Early Development**

This project is in an early stage of development.
Features may change or be unstable. Contributions and feedback are welcome!

Time'sApp is comprehensive cross-platform application designed to help
users efficiently manage their day-to-day life.
Available for desktop, mobile, and a streamlined web version, the app
integrates a variety of features aimed at enhancing productivity,
financial planning, habit tracking, and event management.
With synchronized database across all platforms, users can seamlessly
switch between devices while staying up-to-date with their schedules, tasks, finances, and routines.

**Currently working on:**
- centralized calendar for events appointments, and reminders
- task prioritization system, allowing users to create a work plan based on deadlines or importance
- database system, switching SQLite3 -> PostgreSQL

**Plans:**
- integration with other calendars for easy syncing (e.g.,Google Calendar, Apple Calendar)
- shareable calendars for team coordination and collaboration
- Web API development
- financial tracking module
- routines and habit tracking module
- synchronization of data across all platforms, ensuring consistency no matter the device.
- colaboration module

## System Requirements
**MacOS**

Currently working on MacOS implementation.<br>

In the near future there will be Windows version available.<br>
With Web Api developed there will be also web and mobile version to play with.

## Installation
> [!NOTE]
> Implementation uses QT Widgets so in order to run this project, you need to have qt6 installed on your machine.<br>

**Mac OS**<br>
Install:<br>
Qt Widgets installation is recommended to be managed by official Qt installer, but homebrew is also available:
```
brew install qt6
```

Then you may need to add Qt to your PATH:
```
echo 'export PATH="/opt/homebrew/opt/qt6/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
```
If that does not work you have to check your path, and add Qt accordingly:
```
brew --prefix qt6
```

If you dont have CMake installed:
```
brew install cmake
```

Build:<br>
Standard cmake build:
```
mkdir build
cd build
cmake .. -G "Ninja"
cmake --build .
```

Run created exec:
```
./qt_implementation
```
Homebrew recommend using Ninja generator, so you may also download it, tho it's not necessary:
```
brew install ninja
```
Corresponding build flag:
```
cmake .. -G "Ninja"
```

**Compiler**<br>
Default compiler used for MacOS is clang:
```
xcode-select --install
```

## Git workflow
- **main** - release branch
- **dev** -  main develop branch, merged into the main branch on releases via Pull Request.
- **features branches** - will be created from dev and merged back by Pull Requests.