#ifndef CONFIG_H
#define CONFIG_H

#cmakedefine HAVE_DL_H 1
#cmakedefine HAVE_EXECINFO_H 1
#cmakedefine HAVE_ICONV 1
#cmakedefine HAVE_INTTYPES_H 1
#cmakedefine HAVE_LANGINFO_CODESET 1
#cmakedefine HAVE_LIMITS_H 1
#cmakedefine HAVE_MALLOC_H 1
#cmakedefine HAVE_PAM_MISC_H 1
#cmakedefine HAVE_PAM_PAM_APPL_H 1
#cmakedefine HAVE_PTHREAD 1
#cmakedefine HAVE_SECURITY_PAM_APPL_H 1
#cmakedefine HAVE_SECURITY_PAM_MISC_H 1
#cmakedefine HAVE_STDINT_H 1
#cmakedefine HAVE_SYS_MOUNT_H 1
#cmakedefine HAVE_SYS_PARAM_H 1
#cmakedefine HAVE_SYS_STATVFS_H 1
#cmakedefine HAVE_SYS_TYPES_H 1
#cmakedefine HAVE_UNISTD_H 1
#cmakedefine HAVE_UTIME_H 1
#cmakedefine HAVE_WCHAR_H 1

#cmakedefine HAVE_BACKTRACE 1
#cmakedefine HAVE_INET_NTOA 1
#cmakedefine HAVE_INET_NTOP 1
#cmakedefine HAVE_INET_PTON 1
#cmakedefine HAVE_STRERROR 1
#cmakedefine HAVE_STRLCAT 1
#cmakedefine HAVE_STRPTIME 1
#cmakedefine HAVE_STRTOK_R 1
#cmakedefine HAVE_STRTOULL 1
#cmakedefine HAVE_STATVFS 1
#cmakedefine HAVE_STAT64 1

#cmakedefine NL_BIN_PREFIX "${NL_BIN_PREFIX}"
#cmakedefine NL_ETC_PREFIX "${NL_ETC_PREFIX}"
#cmakedefine NL_SHARE_PREFIX "${NL_SHARE_PREFIX}"
#cmakedefine NL_LIB_PREFIX "${NL_LIB_PREFIX}"
#cmakedefine NL_DRIVER_PREFIX "${NL_DRIVER_PREFIX}"

#cmakedefine RYZOM_PREFIX "${RYZOM_PREFIX}"
#cmakedefine RYZOM_BIN_PREFIX "${RYZOM_BIN_PREFIX}"
#cmakedefine RYZOM_ETC_PREFIX "${RYZOM_ETC_PREFIX}"
#cmakedefine RYZOM_SHARE_PREFIX "${RYZOM_SHARE_PREFIX}"

#endif // CONFIG_H
