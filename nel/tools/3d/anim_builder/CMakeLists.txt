FILE(GLOB SRC *.cpp *.h)

ADD_EXECUTABLE(anim_builder ${SRC})

TARGET_LINK_LIBRARIES(anim_builder nelmisc nel3d)
NL_DEFAULT_PROPS(anim_builder "NeL, Tools, 3D: anim_builder")
NL_ADD_RUNTIME_FLAGS(anim_builder)

INSTALL(TARGETS anim_builder RUNTIME DESTINATION bin COMPONENT tools3d)
