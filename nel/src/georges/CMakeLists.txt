FILE(GLOB SRC *.cpp *.h)
FILE(GLOB HEADERS ../../include/nel/georges/*.h)

# SOURCE_GROUP(headers FILES ${HEADERS})

NL_TARGET_LIB(nelgeorges ${HEADERS} ${SRC})

INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

IF(WITH_STLPORT)
  TARGET_LINK_LIBRARIES(nelgeorges ${CMAKE_THREAD_LIBS_INIT})
ENDIF(WITH_STLPORT)

TARGET_LINK_LIBRARIES(nelgeorges ${LIBXML2_LIBRARIES} nelmisc)
SET_TARGET_PROPERTIES(nelgeorges PROPERTIES LINK_INTERFACE_LIBRARIES "")
NL_DEFAULT_PROPS(nelgeorges "NeL, Library: NeL Georges")
NL_ADD_RUNTIME_FLAGS(nelgeorges)

NL_ADD_LIB_SUFFIX(nelgeorges)

ADD_DEFINITIONS(${LIBXML2_DEFINITIONS})

IF(WITH_PCH)
  ADD_NATIVE_PRECOMPILED_HEADER(nelgeorges ${CMAKE_CURRENT_SOURCE_DIR}/stdgeorges.h ${CMAKE_CURRENT_SOURCE_DIR}/stdgeorges.cpp)
ENDIF(WITH_PCH)

NL_GEN_PC(nel-georges.pc)
INSTALL(TARGETS nelgeorges LIBRARY DESTINATION lib ARCHIVE DESTINATION lib COMPONENT libraries)
