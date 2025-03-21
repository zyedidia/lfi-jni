# Installation

First initialize the submodules:

```
git submodule update --init
```

# Install LFI

Download the appropriate compiler from the LFI releases page: https://github.com/zyedidia/lfi/releases.

If you don't have the LFI tools installed separately, you'll want to put `x86_64-lfi-clang/lfi-bin` on your path. Otherwise, just put `x86_64-lfi-clang/lfi-clang` on your path.

The examples are currently set up to use the `x86_64-lfi-clang` compiler.

# Build LFI-bind

```
cd lfi-bind
go build
```

# Build JDK

```
git clone https://github.com/zyedidia/jdk -b lfi-jdk-21 --depth 1
cd jdk
bash configure
cd build/linux-x86_64-server-release
make JOBS=$(nproc)
```

This should produce `jdk/bin/java`.

# Try an example

```
cd hello
make run
```

In `Hello.java` you can change `System.loadLibrary` to use `native_lfi` or `native_native` to switch between LFI and native versions of the native library.
