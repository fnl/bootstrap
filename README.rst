bootstrap
=========

Synopsis
--------

Quick-start a **GNU C project** setup by copying these contents::

  cp /path/to/bootstrap/* .
  export P=main
  vim main.c
  # edit as needed...
  make

The idea for this bootstrap setup is based on the excellent book `21st Century C`_ by Ben Klemens.

Overview
--------

All default headers are provided via ``standard.h`` and the ``Makefile`` uses
the environment variable ``P`` as the ``PROG`` target name. Write your code in a ``.c``
file with the same name as ``P`` and run ``make`` to compile it.

Environment
-----------

Recommendet development environment tools:

* ``c99`` a C99 standard compiler (Clang, GCC, etc.)
* ``make`` the GNU make utility
* ``gdb`` the GNU debugger
* ``gprof`` the GNU profiler
* ``vim`` the best editor
* ``ctags`` for generating source tags
* ``cscope`` for source code nagivation
* Autotools_ GNU build system (``automake``, ``autoconf``, ``libtool``)
* Doxygen_ document generator
* Git_ concurrent versions control system
* Valgrind_ code analysis
* pkg-config_ compiler and linker utility

Libraries
---------

Frequently used "standard" libraries:

* CUnit_ an alternate unit test library to the GLib
* cURL_ library to connect and communicate with servers
* Glib_ the GNOME standard library for unit testing, data structures, and threading 
* glibc_ the GNU C Library for systems with a Linux kernel
* GSL_ the GNU Scientific Library for numerical computing
* Libxml2_ the GNOME XML parser toolkit to work with markup documents
* SQLite_ a self-contained SQL database engine
* uthash_ an alternate hash table implementation for C structures to the GLib

.. _21st Century C: http://shop.oreilly.com/product/0636920025108.do
.. _Autotools: https://en.wikipedia.org/wiki/GNU_build_system
.. _Doxygen: http://doxygen.org/
.. _Git: http://git-scm.com/
.. _Valgrind: http://valgrind.org/
.. _pkg-config: http://pkgconfig.freedesktop.org/

.. _CUnit: http://cunit.sourceforge.net/
.. _cURL: http://curl.haxx.se/
.. _Glib: http://library.gnome.org/
.. _glibc: http://www.gnu.org/software/libc/
.. _GSL: http://www.gnu.org/software/gsl/
.. _Libxml2: http://xmlsoft.org/
.. _SQLite: http://sqlite.org/
.. _uthash: http://uthash.sourceforge.net/
