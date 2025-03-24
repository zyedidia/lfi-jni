JAVA_HOME=../jdk/build/linux-x86_64-server-release/jdk
JAVA=../jdk/build/linux-x86_64-server-release/jdk/bin/java
LFIBIND=../lfi-bind/lfi-bind
LFICXX=x86_64-lfi-linux-musl-clang++
LFICC=x86_64-lfi-linux-musl-clang

LZ4_INCLUDE = lz4/lib

LZ4_SRCS = lz4_compressor.c \
		   lz4/lib/lz4.c \
		   lz4/lib/lz4hc.c \
		   lz4/lib/xxhash.c
LZ4_OBJS = $(patsubst %.c, %.o, $(LZ4_SRCS))

all: LZ4Compressor.class libnative_lfi.so libnative_native.so

libnative.a: $(LZ4_OBJS)
	ar rcs $@ $^
libnative_lfi.so: libnative.a
	$(LFIBIND) -dyn -o $@ $<
libnative_native.so: $(LZ4_SRCS) LZ4Compressor.h
	clang -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -I$(LZ4_INCLUDE) -o $@ -O2 -fPIC $(LZ4_SRCS)
%.o: %.c LZ4Compressor.h
	$(LFICC) -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -I$(LZ4_INCLUDE) $< -o $@ -O2
%.class %.h &: %.java
	javac -h . $<
run: LZ4Compressor.class libnative_lfi.so libnative_native.so
	$(JAVA) -cp . -Djava.library.path=. LZ4Compressor

.PHONY: all
