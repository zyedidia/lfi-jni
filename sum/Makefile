JAVA_HOME=/home/zyedidia/programming/jdk/build/linux-x86_64-server-release/jdk
JAVA=/home/zyedidia/programming/jdk/build/linux-x86_64-server-release/jdk/bin/java

libnative.a: Sum.o
	ar rcs $@ $<
libnative_lfi.so: libnative.a
	lfi-bind -dyn -o $@ $<
libnative_native.so: Sum.cc Sum.h
	clang++ -shared -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2 -fPIC
Sum.o: Sum.cc Sum.h
	x86_64-lfi-linux-musl-clang++ -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $< -o $@ -O2
%.h %.class &: %.java
	javac -h . $<
run: Sum.class libnative_lfi.so libnative_native.so
	$(JAVA) -cp . -Djava.library.path=. Sum
