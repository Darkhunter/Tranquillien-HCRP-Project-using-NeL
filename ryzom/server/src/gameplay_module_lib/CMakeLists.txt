FILE(GLOB SRC *.cpp *.h)

NL_TARGET_LIB(ryzom_gameplaymodule ${SRC})

INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

IF(WITH_STLPORT)
  TARGET_LINK_LIBRARIES(ryzom_gameplaymodule ${CMAKE_THREAD_LIBS_INIT})
ENDIF(WITH_STLPORT)

TARGET_LINK_LIBRARIES(ryzom_gameplaymodule nelmisc)
NL_DEFAULT_PROPS(ryzom_gameplaymodule "Ryzom, Library: Gameplay Module")
NL_ADD_RUNTIME_FLAGS(ryzom_gameplaymodule)
NL_ADD_LIB_SUFFIX(ryzom_gameplaymodule)

ADD_DEFINITIONS(${LIBXML2_DEFINITIONS})

INSTALL(TARGETS ryzom_gameplaymodule LIBRARY DESTINATION lib ARCHIVE DESTINATION lib COMPONENT libraries)
