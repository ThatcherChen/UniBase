# 编译运行测试文档

首先，确定自己在UniBase根目录下，然后创建一个构建目录并cd进去：

```
mkdir build && cd build
```

这行命令不会有任何输出，但是你可以通过bash的pormpt得知目前在哪一个目录，例如：

```
root@38905d7c6372:/mnt/UniBase/build#
```

然后执行cmake构建命令：

```
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

输出：

```
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found BISON: /usr/bin/bison (found version "3.8.2")
-- Found FLEX: /usr/bin/flex (found version "2.6.4")
-- Could NOT find Python3 (missing: Python3_EXECUTABLE Interpreter)
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/UniBase/build
```

至此构建系统已经生成完毕，之后根据实验文档的要求到build文件夹下make即可。

例如我们要测试disk_manager，那么则在此处执行：

```
make disk_manager_test
```

系统会自动编译你的代码和测试代码，只需要执行相应的二进制文件即可：

```
./bin/disk_manager_test
```

系统会输出你的评测情况：

```
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from DiskManagerTest
[ RUN      ] DiskManagerTest.FileOperation
disk_manager_test: /mnt/UniBase/src/test/storage/disk_manager_test.cpp:74: virtual void DiskManagerTest_FileOperation_Test::TestBody(): Assertion `false' failed.
Aborted
```
