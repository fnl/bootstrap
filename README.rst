bootstrap
=========

Synopsis
--------

Quick-start a **GNU C project** setup with the GLib_::

  cp /path/to/bootstrap/* .
  export P=program
  mv main.c $P.c
  vim $P.c
  # code the program...
  make
  make clean
  # measure coverage:
  ./gcov.sh program-args

The idea for this bootstrap setup is based on the excellent book `21st Century C`_ by Ben Klemens.

Overview
--------

All default headers are provided via ``standard.h`` and the ``Makefile`` uses
the environment variable ``P`` as the ``PROG`` target name. Write your code in a ``.c``
file with the same name as ``P`` and run ``make`` to compile it.

For Mac OSX users, an easy way to install the essential tools and libraries is using Homebrew_. On GNU-based systems (i.e., some Linux and BSD distros), these should be freely available via your distro's package manager and/or should be installed already.

Environment
-----------

Recommendet development environment tools (install them Homebrew_ on OSX):

* ``c99`` a C99 standard compiler (Clang, GCC, etc.)
* ``make`` the GNU make utility
* ``gdb`` the GNU debugger
* ``gprof`` the GNU profiler
* ``gcov`` code coverage analysis
* ``vim`` the best editor
* ``ctags`` for generating source tags
* ``cscope`` for source code nagivation
* Autotools_ GNU build system (``automake``, ``autoconf``, ``libtool``)
* Doxygen_ document generator (``doxygen``)
* Git_ concurrent versions control system
* Splint_ static code analysis tool
* Valgrind_ dynamic code analysis tool
* pkg-config_ compiler and linker utility

Libraries
---------

Important "standard" libraries (install them with Homebrew_ on Mac OSX):

* Bison_ the GNU LARL(1) parser generator*
* Check_ an alternate unit test library to the GLib
* cURL_ library to connect and communicate with servers
* Flex_ a fast lexical scanner/tokenizer generator\*
* GLib_ the GNOME standard library for unit testin\g, data structures, and threading 
* glibc_ the GNU C Library for systems with a Linux kernel (should already be installed by default)
* GSL_ the GNU Scientific Library for numerical computing
* Libxml2_ the GNOME XML parser toolkit to work with markup documents\*\*
* SQLite_ a self-contained SQL database engine\*\*\*

| --
| \* n/a from Homebrew_ (OSX), but libraries are only needed for developing parsers
| \*\* Homebrew_ does not correctly install Libxml2 with Python support (see `issue <https://github.com/mxcl/homebrew/pull/13511>`_)
| \*\*\* for Homebrew_, check out the installation options using ``brew info sqlite``

.. _21st Century C: http://shop.oreilly.com/product/0636920025108.do
.. _Homebrew: http://mxcl.github.com/homebrew/

.. _Autotools: https://en.wikipedia.org/wiki/GNU_build_system
.. _Doxygen: http://doxygen.org/
.. _Git: http://git-scm.com/
.. _Splint: http://www.splint.org/
.. _Valgrind: http://valgrind.org/
.. _pkg-config: http://pkgconfig.freedesktop.org/

.. _Bison: http://www.gnu.org/software/bison/
.. _Check: http://check.sourceforge.net/
.. _cURL: http://curl.haxx.se/
.. _Flex: http://flex.sourceforge.net/
.. _GLib: http://library.gnome.org/
.. _glibc: http://www.gnu.org/software/libc/
.. _GSL: http://www.gnu.org/software/gsl/
.. _Libxml2: http://xmlsoft.org/
.. _SQLite: http://sqlite.org/
