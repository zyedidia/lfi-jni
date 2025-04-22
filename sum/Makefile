ARCH=aarch64

JAVA_HOME=../jdk/build/linux-$(ARCH)-server-release/jdk
# JAVA=../jdk/build/linux-$(ARCH)-server-release/jdk/bin/java
JAVA=java
LFIBIND=../lfi-bind/lfi-bind
LFICXX=/opt/aarch64-lfi-sysext-clang/lfi-clang/$(ARCH)-lfi-linux-musl-clang++
LFICC=/opt/aarch64-lfi-sysext-clang/lfi-clang/$(ARCH)-lfi-linux-musl-clang

all: Sum.class libnative_lfi.so libnative_native.so

libnative.a: Sum.o
	ar rcs $@ $<
libnative_lfi.so: libnative.a
	$(LFIBIND) -lficc $(LFICC) -dyn -o $@ $<
libnative_native.so: Sum.cc Sum.h
	clang++ -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2 -fPIC
Sum.o: Sum.cc Sum.h
	$(LFICXX) -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2
%.h %.class &: %.java
	javac -h . $<
run: Sum.class libnative_lfi.so libnative_native.so
	$(JAVA) -cp . -Djava.library.path=. Sum

.PHONY: all
