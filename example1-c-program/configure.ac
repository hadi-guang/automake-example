AC_INIT([amhello], [1.0], [bug-automake@gnu.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_CONFIG_HEADERS([config.h])

# Automake will require the sources fle declared with AC_LIBSOURCE
# in the directory specifed by this macro
# AC_CONFIG_LIBOBJ_DIR([])

# *.AM -> *.in -> Makefile
AC_CONFIG_FILES([
		 Makefile
		 src/Makefile
		 ])
AC_OUTPUT
