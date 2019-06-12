# automake-example

## Basic Installation

autoreconf --install

./configure

make

make check

make install

make installcheck

## Standard Makefile Targets

> Build programs, libraries, documentation, etc. (same as make)
make all

> Install what needs to be installed, copying the fles from the package's tree to
> system-wide directories.
make install

> Same as make install, then strip debugging symbols. Some users like to trade
> space for useful bug reports. . .
make install-strip

> The opposite of make install: erase the installed fles. (This needs to be run
> from the same build tree that was installed.)
make uninstall

> Erase from the build tree the files built by make all.
make clean

> Additionally erase anything ./configure created.
make distclean

> Run the test suite, if any.
make check

> Check the installed programs or libraries, if supported.
make installcheck

> Recreate package-version.tar.gz from all the source fles
make dist

## Standard Directory Variables

Directory variable Default value
prefix /usr/local
exec_prefix ${prefix}
bindir ${exec_prefix}/bin
libdir ${exec_prefix}/lib
. . .
includedir ${prefix}/include
datarootdir ${prefix}/share
datadir ${datarootdir}
mandir ${datarootdir}/man
infodir ${datarootdir}/info
docdir ${datarootdir}/doc/${PACKAGE}
. . .

./configure --prefix ~/usr

## Standard Confguration Variables

CC C compiler command
CFLAGS C compiler flags
CXX C++ compiler command
CXXFLAGS C++ compiler flags
LDFLAGS linker flags
CPPFLAGS C/C++ preprocessor flags

./configure --prefix ~/usr CC=gcc-3 \
CPPFLAGS=-I$HOME/usr/include LDFLAGS=-L$HOME/usr/lib

create ~/usr/share/config.site fle:
test -z "$CC" && CC=gcc-3
test -z "$CPPFLAGS" && CPPFLAGS=-I$HOME/usr/include
test -z "$LDFLAGS" && LDFLAGS=-L$HOME/usr/lib

./configure --prefix ~/usr
configure: loading site script /home/adl/usr/share/config.site
...

## Parallel Build Trees (a.k.a. VPATH Builds)

tar zxf ~/amhello-1.0.tar.gz
cd amhello-1.0
mkdir build && cd build
../configure
make

## Two-Part Installation

These targets are install-exec for architecture-dependent fles and install-data for
architecture-independent fles. The command we used up to now, make install, can be
thought of as a shorthand for make install-exec install-data.

## Cross-Compilation

--build=build
The system on which the package is built.

--host=host
The system where built programs and libraries will run

for cross-compiler i586-mingw32msvc-gcc, i586-mingw32msvc-ld, i586-mingw32msvc-as
./configure --build i686-pc-linux-gnu --host i586-mingw32msvc

--target=target
When building compiler tools: the system for which the tools will create output.

For instance when installing GCC, the GNU Compiler Collection, we can use --target=
target to specify that we want to build GCC as a cross-compiler for target. Mixing
--build and --target, we can actually cross-compile a cross-compiler; such a three-way
cross-compilation is known as a Canadian cross.

## Renaming Programs at Install Time

--program-prefix=prefix
Prepend prefx to installed program names.
--program-suffix=suffix
Append sufx to installed program names.
--program-transform-name=program
Run sed program on installed program names.

./configure --program-prefix test-
make 
make install

## Building Binary Packages Using DESTDIR

./configure --prefix /usr
make
make DESTDIR=$HOME/inst install
cd ~/inst
find . -type f -print > ../files.lst
tar zcvf ~/amhello-1.0-i686.tar.gz ‘cat ../files.lst‘
./usr/bin/hello
./usr/share/doc/amhello/README

After this example, amhello-1.0-i686.tar.gz is ready to be uncompressed in / on
many hosts. (Using ‘cat ../files.lst‘ instead of ‘.’ as argument for tar avoids entries
for each subdirectory in the archive: we would not like tar to restore the modifcation time
of /, /usr/, etc.)

## Preparing Distributions

Recreate package-version.tar.gz from all the source fles,and check the package.
make distcheck

## Automatic Dependency Tracking

./configure

--disable-dependency-tracking
Speed up one-time builds

--enable-dependency-tracking
Do not reject slow dependency extractors.

## Nested Packages
The command configure --help=recursive can be used to display the options supported by all the included packages.
