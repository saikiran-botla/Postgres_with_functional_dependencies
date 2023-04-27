make distclean
./configure --prefix=$POSTGRES_INSTALLDIR --enable-debug
make | tee gmake.out > log.txt
make install | tee gmake.out > log_install.txt
