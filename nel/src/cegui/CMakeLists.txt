FILE(GLOB SRC *.cpp *.h)
FILE(GLOB HEADERS ../../include/nel/cegui/*.h)

ADD_LIBRARY(nelceguirenderer SHARED ${HEADERS} ${SRC} nelceguirenderer.def)

INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR} ${FREETYPE_INC} ${CEGUI_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(nelceguirenderer nelmisc nel3d ${CEGUI_LIBRARY})
NL_DEFAULT_PROPS(nelceguirenderer "NeL, Library: CEGUI Renderer")
NL_ADD_RUNTIME_FLAGS(nelceguirenderer)
NL_ADD_LIB_SUFFIX(nelceguirenderer)

ADD_DEFINITIONS(${LIBXML2_DEFINITIONS} -DNEL_CEGUIRENDERER_EXPORTS)

INSTALL(TARGETS nelceguirenderer RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib COMPONENT libraries)
