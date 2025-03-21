JAVA_HOME=../jdk/build/linux-x86_64-server-release/jdk
JAVA=../jdk/build/linux-x86_64-server-release/jdk/bin/java

libnative.a: Hello.o
	ar rcs $@ $<
libnative_lfi.so: libnative.a
	lfi-bind -dyn -o $@ $<
libnative_native.so: Hello.cc Hello.h
	clang++ -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2 -fPIC
Hello.o: Hello.cc Hello.h
	x86_64-lfi-linux-musl-clang++ -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2
%.class %.h &: %.java
	javac -h . $<
run: Hello.class libnative_lfi.so libnative_native.so
	$(JAVA) -cp . -Djava.library.path=. Hello
