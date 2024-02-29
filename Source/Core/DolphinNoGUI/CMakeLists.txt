add_executable(dolphin-triforce-nogui
  Platform.cpp
  Platform.h
  PlatformHeadless.cpp
  MainNoGUI.cpp
)

if(ENABLE_X11 AND X11_FOUND)
  target_sources(dolphin-triforce-nogui PRIVATE PlatformX11.cpp)
endif()

if(WIN32)
  target_sources(dolphin-triforce-nogui PRIVATE PlatformWin32.cpp)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  target_sources(dolphin-triforce-nogui PRIVATE PlatformFBDev.cpp)
endif()

set_target_properties(dolphin-triforce-nogui PROPERTIES OUTPUT_NAME dolphin-triforce-nogui)

target_link_libraries(dolphin-triforce-nogui
PRIVATE
  core
  uicommon
  cpp-optparse
)

if(MSVC)
  # Add precompiled header
  target_link_libraries(dolphin-triforce-nogui PRIVATE use_pch)
endif()

if(USE_DISCORD_PRESENCE)
  target_compile_definitions(dolphin-triforce-nogui PRIVATE -DUSE_DISCORD_PRESENCE)
endif()

set(CPACK_PACKAGE_EXECUTABLES ${CPACK_PACKAGE_EXECUTABLES} dolphin-triforce-nogui)
install(TARGETS dolphin-triforce-nogui RUNTIME DESTINATION ${bindir})

