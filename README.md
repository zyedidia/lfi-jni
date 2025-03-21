# Installation

First initialize the submodules:

```
git submodule update --init --depth 1
```

# Install LFI

Download the appropriate compiler from the LFI releases page: https://github.com/zyedidia/lfi/releases.

The examples are currently set up to use the `x86_64-lfi-clang` compiler.

# Build LFI-bind

```
cd lfi-bind
go build
```

# Build JDK

```
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
