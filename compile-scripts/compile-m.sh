
#!/bin/bash
MXE_PATH=/mnt/mxe-build/mxe

CC=$MXE_PATH/usr/bin/i686-w64-mingw32.static-gcc \
AR=$MXE_PATH/usr/bin/i686-w64-mingw32.static-ar \
CFLAGS="-DSTATICLIB -I$MXE_PATH/usr/i686-w64-mingw32.static/include" \
LDFLAGS="-L$MXE_PATH/usr/i686-w64-mingw32.static/lib" \
make -j8 libminiupnpc.a

mkdir $MXE_PATH/usr/i686-w64-mingw32.static/include/miniupnpc
cp *.h $MXE_PATH/usr/i686-w64-mingw32.static/include/miniupnpc
cp libminiupnpc.a $MXE_PATH/usr/i686-w64-mingw32.static/lib
