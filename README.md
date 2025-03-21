# Build JDK

```
cd jdk
bash configure
cd build/linux-x86_64-server-release
make JOBS=$(nproc)
```

# Try an example

```
cd hello
make run
```

In `Hello.java` you can change `System.loadLibrary` to use `native_lfi` or `native_native` to switch between LFI and native versions of the native library.
