# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/XMLManager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/XMLManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/XMLManager.dir/flags.make

CMakeFiles/XMLManager.dir/pugixml.cpp.o: CMakeFiles/XMLManager.dir/flags.make
CMakeFiles/XMLManager.dir/pugixml.cpp.o: ../pugixml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/XMLManager.dir/pugixml.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLManager.dir/pugixml.cpp.o -c "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/pugixml.cpp"

CMakeFiles/XMLManager.dir/pugixml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLManager.dir/pugixml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/pugixml.cpp" > CMakeFiles/XMLManager.dir/pugixml.cpp.i

CMakeFiles/XMLManager.dir/pugixml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLManager.dir/pugixml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/pugixml.cpp" -o CMakeFiles/XMLManager.dir/pugixml.cpp.s

CMakeFiles/XMLManager.dir/pugixml.cpp.o.requires:

.PHONY : CMakeFiles/XMLManager.dir/pugixml.cpp.o.requires

CMakeFiles/XMLManager.dir/pugixml.cpp.o.provides: CMakeFiles/XMLManager.dir/pugixml.cpp.o.requires
	$(MAKE) -f CMakeFiles/XMLManager.dir/build.make CMakeFiles/XMLManager.dir/pugixml.cpp.o.provides.build
.PHONY : CMakeFiles/XMLManager.dir/pugixml.cpp.o.provides

CMakeFiles/XMLManager.dir/pugixml.cpp.o.provides.build: CMakeFiles/XMLManager.dir/pugixml.cpp.o


CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o: CMakeFiles/XMLManager.dir/flags.make
CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o: /home/isaac/Escritorio/Proyecto\ Programado\ 3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o -c "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp"

CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp" > CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.i

CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp" -o CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.s

CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.requires:

.PHONY : CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.requires

CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.provides: CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.requires
	$(MAKE) -f CMakeFiles/XMLManager.dir/build.make CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.provides.build
.PHONY : CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.provides

CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.provides.build: CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o


CMakeFiles/XMLManager.dir/main.cpp.o: CMakeFiles/XMLManager.dir/flags.make
CMakeFiles/XMLManager.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/XMLManager.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLManager.dir/main.cpp.o -c "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/main.cpp"

CMakeFiles/XMLManager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLManager.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/main.cpp" > CMakeFiles/XMLManager.dir/main.cpp.i

CMakeFiles/XMLManager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLManager.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/main.cpp" -o CMakeFiles/XMLManager.dir/main.cpp.s

CMakeFiles/XMLManager.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/XMLManager.dir/main.cpp.o.requires

CMakeFiles/XMLManager.dir/main.cpp.o.provides: CMakeFiles/XMLManager.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/XMLManager.dir/build.make CMakeFiles/XMLManager.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/XMLManager.dir/main.cpp.o.provides

CMakeFiles/XMLManager.dir/main.cpp.o.provides.build: CMakeFiles/XMLManager.dir/main.cpp.o


CMakeFiles/XMLManager.dir/XMLManager.cpp.o: CMakeFiles/XMLManager.dir/flags.make
CMakeFiles/XMLManager.dir/XMLManager.cpp.o: ../XMLManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/XMLManager.dir/XMLManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLManager.dir/XMLManager.cpp.o -c "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/XMLManager.cpp"

CMakeFiles/XMLManager.dir/XMLManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLManager.dir/XMLManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/XMLManager.cpp" > CMakeFiles/XMLManager.dir/XMLManager.cpp.i

CMakeFiles/XMLManager.dir/XMLManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLManager.dir/XMLManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/XMLManager.cpp" -o CMakeFiles/XMLManager.dir/XMLManager.cpp.s

CMakeFiles/XMLManager.dir/XMLManager.cpp.o.requires:

.PHONY : CMakeFiles/XMLManager.dir/XMLManager.cpp.o.requires

CMakeFiles/XMLManager.dir/XMLManager.cpp.o.provides: CMakeFiles/XMLManager.dir/XMLManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/XMLManager.dir/build.make CMakeFiles/XMLManager.dir/XMLManager.cpp.o.provides.build
.PHONY : CMakeFiles/XMLManager.dir/XMLManager.cpp.o.provides

CMakeFiles/XMLManager.dir/XMLManager.cpp.o.provides.build: CMakeFiles/XMLManager.dir/XMLManager.cpp.o


CMakeFiles/XMLManager.dir/XMLParts.cpp.o: CMakeFiles/XMLManager.dir/flags.make
CMakeFiles/XMLManager.dir/XMLParts.cpp.o: ../XMLParts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/XMLManager.dir/XMLParts.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLManager.dir/XMLParts.cpp.o -c "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/XMLParts.cpp"

CMakeFiles/XMLManager.dir/XMLParts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLManager.dir/XMLParts.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/XMLParts.cpp" > CMakeFiles/XMLManager.dir/XMLParts.cpp.i

CMakeFiles/XMLManager.dir/XMLParts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLManager.dir/XMLParts.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/XMLParts.cpp" -o CMakeFiles/XMLManager.dir/XMLParts.cpp.s

CMakeFiles/XMLManager.dir/XMLParts.cpp.o.requires:

.PHONY : CMakeFiles/XMLManager.dir/XMLParts.cpp.o.requires

CMakeFiles/XMLManager.dir/XMLParts.cpp.o.provides: CMakeFiles/XMLManager.dir/XMLParts.cpp.o.requires
	$(MAKE) -f CMakeFiles/XMLManager.dir/build.make CMakeFiles/XMLManager.dir/XMLParts.cpp.o.provides.build
.PHONY : CMakeFiles/XMLManager.dir/XMLParts.cpp.o.provides

CMakeFiles/XMLManager.dir/XMLParts.cpp.o.provides.build: CMakeFiles/XMLManager.dir/XMLParts.cpp.o


# Object files for target XMLManager
XMLManager_OBJECTS = \
"CMakeFiles/XMLManager.dir/pugixml.cpp.o" \
"CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o" \
"CMakeFiles/XMLManager.dir/main.cpp.o" \
"CMakeFiles/XMLManager.dir/XMLManager.cpp.o" \
"CMakeFiles/XMLManager.dir/XMLParts.cpp.o"

# External object files for target XMLManager
XMLManager_EXTERNAL_OBJECTS =

XMLManager: CMakeFiles/XMLManager.dir/pugixml.cpp.o
XMLManager: CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o
XMLManager: CMakeFiles/XMLManager.dir/main.cpp.o
XMLManager: CMakeFiles/XMLManager.dir/XMLManager.cpp.o
XMLManager: CMakeFiles/XMLManager.dir/XMLParts.cpp.o
XMLManager: CMakeFiles/XMLManager.dir/build.make
XMLManager: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
XMLManager: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
XMLManager: /usr/lib/x86_64-linux-gnu/libQt5Sql.so.5.9.5
XMLManager: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.9.5
XMLManager: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
XMLManager: CMakeFiles/XMLManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable XMLManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/XMLManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/XMLManager.dir/build: XMLManager

.PHONY : CMakeFiles/XMLManager.dir/build

CMakeFiles/XMLManager.dir/requires: CMakeFiles/XMLManager.dir/pugixml.cpp.o.requires
CMakeFiles/XMLManager.dir/requires: CMakeFiles/XMLManager.dir/home/isaac/Escritorio/Proyecto_Programado_3/Odyssey2-0/Servidor/MySQLConnector/MySQLConnector.cpp.o.requires
CMakeFiles/XMLManager.dir/requires: CMakeFiles/XMLManager.dir/main.cpp.o.requires
CMakeFiles/XMLManager.dir/requires: CMakeFiles/XMLManager.dir/XMLManager.cpp.o.requires
CMakeFiles/XMLManager.dir/requires: CMakeFiles/XMLManager.dir/XMLParts.cpp.o.requires

.PHONY : CMakeFiles/XMLManager.dir/requires

CMakeFiles/XMLManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/XMLManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/XMLManager.dir/clean

CMakeFiles/XMLManager.dir/depend:
	cd "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager" "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager" "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug" "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug" "/home/isaac/Escritorio/Proyecto Programado 3/Odyssey2-0/Servidor/XMLManager/cmake-build-debug/CMakeFiles/XMLManager.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/XMLManager.dir/depend

