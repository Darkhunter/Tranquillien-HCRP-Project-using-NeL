# These are Windows/MFC apps
IF(WIN32)
#  ADD_SUBDIRECTORY(bug_report)
  SET(SEVENZIP_LIBRARY "ryzom_sevenzip")
ENDIF(WIN32)

ADD_SUBDIRECTORY(client_sheets)
ADD_SUBDIRECTORY(seven_zip)

FILE(GLOB CFG ../*.cfg ../*.cfg.in)
FILE(GLOB SRC *.cpp *.h motion/*.cpp motion/*.h client.rc)
FILE(GLOB SRC_INTERFACE interface_v3/*.h interface_v3/*.cpp)
FILE(GLOB SRC_MODE motion/modes/*.cpp motion/modes/*.h)
FILE(GLOB SRC_R2 r2/*.h r2/*.cpp r2/dmc/*.h r2/dmc/*.cpp)

# Filter out the source files not actually compiled.
LIST(REMOVE_ITEM SRC
	${CMAKE_CURRENT_SOURCE_DIR}/animated_scene_object.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/animated_scene_object.h
	${CMAKE_CURRENT_SOURCE_DIR}/animation_fx_sheet.h
	${CMAKE_CURRENT_SOURCE_DIR}/animation_fx_sheet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/3d_notes.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/3d_notes.h
	${CMAKE_CURRENT_SOURCE_DIR}/rosace_functions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/rosace_functions.h
	${CMAKE_CURRENT_SOURCE_DIR}/scene_parser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/scene_parser.h)
LIST(REMOVE_ITEM SRC_MODE
	${CMAKE_CURRENT_SOURCE_DIR}/motion/modes/free_head.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/motion/modes/free_head.h)
LIST(REMOVE_ITEM SRC_INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/interface_v3/lua_dll.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/interface_v3/lua_dll.h
	${CMAKE_CURRENT_SOURCE_DIR}/interface_v3/view_bitmap_progress.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/interface_v3/view_bitmap_progress.h)

SOURCE_GROUP("" FILES ${SRC})
SOURCE_GROUP("cfg" FILES ${CFG})
SOURCE_GROUP("interface_v3" FILES ${SRC_INTERFACE})
SOURCE_GROUP("mode" FILES ${SRC_MODE})
SOURCE_GROUP("r2" FILES ${SRC_R2})

# on Mac, create a .App Bundle
if(APPLE)
  SET(MACOSX_BUNDLE_INFO_STRING "Ryzom Core Client")
  SET(MACOSX_BUNDLE_ICON_FILE "")
  SET(MACOSX_BUNDLE_GUI_IDENTIFIER "")
  SET(MACOSX_BUNDLE_LONG_VERSION_STRING ${NL_VERSION})
  SET(MACOSX_BUNDLE_BUNDLE_NAME "Ryzom Core Client")
  SET(MACOSX_BUNDLE_SHORT_VERSION_STRING "0.8")
  SET(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
  SET(MACOSX_BUNDLE_COPYRIGHT "Winchgate and The Ryzom Core Community")

  # TODO: in release mode, cmake could copy all the dylibs into the .app
  # bundle for redistribution... should some part of cpack handle that?
  # ADD_CUSTOM_COMMAND(TARGET ryzom_client POST_BUILD
  #   # make frameworks directory in app bundle
  #   COMMAND ${CMAKE_COMMAND} -E make_directory
  #     ${CMAKE_CURRENT_BINARY_DIR}/ryzom_client.app/Contents/Frameworks
  #   # copy framework into app bundle
  #   COMMAND ${CMAKE_COMMAND} -E copy ${SOME_LIBRARY}
  #     ${CMAKE_CURRENT_BINARY_DIR}/ryzom_client.app/Contents/Frameworks
  #   # ...
  #   # install_name_tool the lib pathes
ENDIF(APPLE)

ADD_EXECUTABLE(ryzom_client WIN32 MACOSX_BUNDLE ${SRC} ${SRC_INTERFACE} ${SRC_MODE} ${SRC_R2})

INCLUDE_DIRECTORIES(
			${CMAKE_CURRENT_SOURCE_DIR}
			${LIBXML2_INCLUDE_DIR}
			${LUA_INCLUDE_DIR}
			${LUABIND_INCLUDE_DIR}
			${LIBWWW_INCLUDE_DIR}
			${CURL_INCLUDE_DIRS}
)

TARGET_LINK_LIBRARIES(ryzom_client
						nelmisc
						nelnet
						nelligo
						nelgeorges
						nel3d
						nelsound
						ryzom_clientsheets
						ryzom_gameshare
						nelpacs
						${LIBXML2_LIBRARIES}
						${LUA_LIBRARIES}
						${LUABIND_LIBRARIES}
						${CURL_LIBRARIES}
						${LIBWWW_LIBRARIES}
						${SEVENZIP_LIBRARY}
)

IF(NOT APPLE AND NOT WIN32)
	TARGET_LINK_LIBRARIES(ryzom_client ${X11_LIBRARIES})
ENDIF(NOT APPLE AND NOT WIN32)

IF(APPLE)
	FIND_LIBRARY(FOUNDATION_LIBRARY Foundation)
	TARGET_LINK_LIBRARIES(ryzom_client ${FOUNDATION_LIBRARY})
ENDIF(APPLE)

ADD_DEFINITIONS(${LIBXML2_DEFINITIONS} ${CURL_DEFINITIONS})

NL_DEFAULT_PROPS(ryzom_client "Ryzom, Client: Ryzom Core Client")
NL_ADD_RUNTIME_FLAGS(ryzom_client)

NL_ADD_LIB_SUFFIX(ryzom_client)

IF(WITH_PCH)
  ADD_NATIVE_PRECOMPILED_HEADER(ryzom_client ${CMAKE_CURRENT_SOURCE_DIR}/stdpch.h ${CMAKE_CURRENT_SOURCE_DIR}/stdpch.cpp)
ENDIF(WITH_PCH)

INSTALL(TARGETS ryzom_client RUNTIME DESTINATION games COMPONENT client BUNDLE DESTINATION /Applications)
