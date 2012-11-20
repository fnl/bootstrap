make clean
CFLAGS="$CFLAGS -O0 -fprofile-arcs -ftest-coverage" make
./$P "$@"
for i in *.gcda; do gcov $i; done;
rm -f *.gcda *.gcna
grep -C3 '#####' *.c.gcov
rm -f *.c.gcov
