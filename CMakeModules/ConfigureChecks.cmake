MACRO(NL_CONFIGURE_CHECKS)
  INCLUDE(CheckIncludeFiles)
  INCLUDE(CheckFunctionExists)
  INCLUDE(CheckLibraryExists)
  INCLUDE(CheckTypeSize)
  
  CHECK_INCLUDE_FILES ("execinfo.h" HAVE_EXECINFO_H)
  CHECK_INCLUDE_FILES ("stdint.h" HAVE_STDINT_H)
  CHECK_INCLUDE_FILES ("sys/types.h" HAVE_SYS_TYPES_H)
  CHECK_INCLUDE_FILES ("inttypes.h" HAVE_INTTYPES_H)
  CHECK_INCLUDE_FILES ("unistd.h" HAVE_UNISTD_H)
  CHECK_INCLUDE_FILES ("utime.h" HAVE_UTIME_H)
  
  CHECK_INCLUDE_FILES ("dl.h" HAVE_DL_H)
  CHECK_INCLUDE_FILES ("limits.h" HAVE_LIMITS_H)
  CHECK_INCLUDE_FILES ("malloc.h" HAVE_MALLOC_H)
  CHECK_INCLUDE_FILES ("sys/param.h" HAVE_SYS_PARAM_H)
  CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h" HAVE_SYS_MOUNT_H)
  CHECK_INCLUDE_FILES ("sys/statvfs.h" HAVE_SYS_STATVFS_H)
  
  CHECK_INCLUDE_FILES ("pthread.h" HAVE_PTHREAD)
  
  CHECK_TYPE_SIZE("size_t" SIZEOF_SIZE_T)
  #if (NOT HAVE_SIZEOF_SIZE_T)
  #  MESSAGE(FATAL_ERROR "size_t is not present on this architecture - aborting")
  #endif (NOT HAVE_SIZEOF_SIZE_T)
  MESSAGE(STATUS "DEBUG size_t is ${SIZEOF_SIZE_T}")
  
  CHECK_TYPE_SIZE("off_t" SIZEOF_OFF_T)
  MESSAGE(STATUS "DEBUG off_t is ${SIZEOF_OFF_T}")
  
  CHECK_FUNCTION_EXISTS("backtrace" HAVE_BACKTRACE)
  CHECK_FUNCTION_EXISTS("getsockname" HAVE_GETSOCKNAME)
  CHECK_FUNCTION_EXISTS("inet_ntoa" HAVE_INET_NTOA)
  CHECK_FUNCTION_EXISTS("inet_ntop" HAVE_INET_NTOP)
  CHECK_FUNCTION_EXISTS("inet_pton" HAVE_INET_PTON)
  CHECK_FUNCTION_EXISTS("regcomp" HAVE_REGCOMP)
  CHECK_FUNCTION_EXISTS("strerror" HAVE_STRERROR)
  CHECK_FUNCTION_EXISTS("strlcat" HAVE_STRLCAT)
  CHECK_FUNCTION_EXISTS("strptime" HAVE_STRPTIME)
  CHECK_FUNCTION_EXISTS("strtok_r" HAVE_STRTOK_R)
  CHECK_FUNCTION_EXISTS("strtoull" HAVE_STRTOULL)
  CHECK_FUNCTION_EXISTS("statvfs" HAVE_STATVFS)
  CHECK_FUNCTION_EXISTS("stat64" HAVE_STAT64)
  
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
  ADD_DEFINITIONS(-DHAVE_CONFIG_H)
ENDMACRO(NL_CONFIGURE_CHECKS)
