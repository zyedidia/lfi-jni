CLASS=Call

JAVA_HOME=../jdk/build/linux-x86_64-server-release/jdk
JAVA=../jdk/build/linux-x86_64-server-release/jdk/bin/java
LFIBIND=../lfi-bind/lfi-bind
LFICXX=x86_64-lfi-linux-musl-clang++
LFICC=x86_64-lfi-linux-musl-clang

all: $(CLASS).class libnative_lfi.so libnative_native.so

libnative.a: $(CLASS).o
	ar rcs $@ $<
libnative_lfi.so: libnative.a
	$(LFIBIND) -dyn -o $@ $<
libnative_native.so: $(CLASS).c $(CLASS).h
	clang -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2 -fPIC
$(CLASS).o: $(CLASS).c $(CLASS).h
	$(LFICC) -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2
%.class %.h &: %.java
	javac -h . $<
run: $(CLASS).class libnative_lfi.so libnative_native.so
	$(JAVA) -cp . -Djava.library.path=. $(CLASS)
clean:
	rm -f *.so *.o *.a *.log *.class

.PHONY: all clean

