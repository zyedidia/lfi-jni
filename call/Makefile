ARCH=aarch64
CLASS=Call
JAVA_HOME=../jdk/build/linux-$(ARCH)-server-release/jdk
# JAVA=../jdk/build/linux-$(ARCH)-server-release/jdk/bin/java
JAVA=java
LFIBIND=../lfi-bind/lfi-bind
LFICXX=/opt/aarch64-lfi-sysext-clang/lfi-clang/$(ARCH)-lfi-linux-musl-clang++
LFICC=/opt/aarch64-lfi-sysext-clang/lfi-clang/$(ARCH)-lfi-linux-musl-clang

all: $(CLASS).class libcall_lfi.so libcall_native.so

libcall_lfi.a: $(CLASS).o
	ar rcs $@ $<
libcall_lfi.so: libcall_lfi.a
	$(LFIBIND) -lficc $(LFICC) -dyn -o $@ $<
libcall_native.so: $(CLASS).c $(CLASS).h
	clang -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2 -fPIC
$(CLASS).o: $(CLASS).c $(CLASS).h
	$(LFICC) -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2
%.class %.h &: %.java
	javac -h . $<
run: $(CLASS).class libcall_lfi.so libcall_native.so
	$(JAVA) -cp . -Djava.library.path=. $(CLASS)
clean:
	rm -f *.so *.o *.a *.log *.class

.PHONY: all clean

