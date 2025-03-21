JAVA_HOME=../jdk/build/linux-x86_64-server-release/jdk
JAVA=../jdk/build/linux-x86_64-server-release/jdk/bin/java
LFIBIND=../lfi-bind/lfi-bind
LFICXX=x86_64-lfi-linux-musl-clang++
LFICC=x86_64-lfi-linux-musl-clang

all: Hello.class libnative_lfi.so libnative_native.so

libnative.a: Hello.o
	ar rcs $@ $<
libnative_lfi.so: libnative.a
	$(LFIBIND) -dyn -o $@ $<
libnative_native.so: Hello.c Hello.h
	clang -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2 -fPIC
Hello.o: Hello.c Hello.h
	$(LFICC) -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2
%.class %.h &: %.java
	javac -h . $<
run: Hello.class libnative_lfi.so libnative_native.so
	$(JAVA) -cp . -Djava.library.path=. Hello

.PHONY: all
