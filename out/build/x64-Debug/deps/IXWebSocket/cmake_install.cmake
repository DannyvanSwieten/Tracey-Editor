# Install script for directory: C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/danny/Documents/code/Tracey Editor/out/install/x64-Debug")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/danny/Documents/code/Tracey Editor/out/build/x64-Debug/deps/IXWebSocket/ixwebsocket.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ixwebsocket" TYPE FILE FILES
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXBench.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXCancellationRequest.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXConnectionState.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXDNSLookup.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXExponentialBackoff.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXGetFreePort.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXGzipCodec.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXHttp.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXHttpClient.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXHttpServer.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXNetSystem.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXProgressCallback.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSelectInterrupt.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSelectInterruptFactory.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSelectInterruptPipe.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSelectInterruptEvent.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSetThreadName.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSocket.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSocketConnect.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSocketFactory.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSocketServer.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSocketTLSOptions.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXStrCaseCompare.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXUdpSocket.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXUniquePtr.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXUrlParser.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXUuid.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXUtf8Validator.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXUserAgent.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocket.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketCloseConstants.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketCloseInfo.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketErrorInfo.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketHandshake.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketHandshakeKeyGen.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketHttpHeaders.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketInitResult.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketMessage.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketMessageType.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketOpenInfo.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketPerMessageDeflate.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketPerMessageDeflateCodec.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketPerMessageDeflateOptions.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketProxyServer.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketSendData.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketSendInfo.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketServer.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketTransport.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXWebSocketVersion.h"
    "C:/Users/danny/Documents/code/Tracey Editor/deps/IXWebSocket/ixwebsocket/IXSocketOpenSSL.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-config.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-config.cmake"
         "C:/Users/danny/Documents/code/Tracey Editor/out/build/x64-Debug/deps/IXWebSocket/CMakeFiles/Export/lib/cmake/ixwebsocket/ixwebsocket-config.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-config-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-config.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket" TYPE FILE FILES "C:/Users/danny/Documents/code/Tracey Editor/out/build/x64-Debug/deps/IXWebSocket/CMakeFiles/Export/lib/cmake/ixwebsocket/ixwebsocket-config.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket" TYPE FILE FILES "C:/Users/danny/Documents/code/Tracey Editor/out/build/x64-Debug/deps/IXWebSocket/CMakeFiles/Export/lib/cmake/ixwebsocket/ixwebsocket-config-debug.cmake")
  endif()
endif()

