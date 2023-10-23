<<<<<<< HEAD
# Install script for directory: C:/Users/Bárbara/Desktop/2ano/AED/ProjetoAED
=======
# Install script for directory: C:/Users/User/Documents/SEGUNDO ANO/projetoaed2
>>>>>>> be717d92983e7115c520b4e35c5528314b67a7d4

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/P_AED")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "C:/Users/Bárbara/Desktop/2ano/AED/CLion 2023.2.2/bin/mingw/bin/objdump.exe")
=======
  set(CMAKE_OBJDUMP "C:/Users/User/Documents/CLion 2022.3.2/bin/mingw/bin/objdump.exe")
>>>>>>> be717d92983e7115c520b4e35c5528314b67a7d4
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "C:/Users/Bárbara/Desktop/2ano/AED/ProjetoAED/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "C:/Users/User/Documents/SEGUNDO ANO/projetoaed2/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> be717d92983e7115c520b4e35c5528314b67a7d4
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
