# UniBase base-env setup

尽管配置基础环境有非常多的方法，但是我们仍然推荐使用docker，这样可以免去安装各种依赖的问题。

## Docker Desktop

对于Windows和MacOS用户，要使用docker，需要先安装[Docker Desktop](https://www.docker.com/products/docker-desktop/)。

我们准备了预先安装所有依赖的docker镜像，可以通过这行命令拉取：

```
docker pull cc0de/base-env:1.0
```

如果要运行这个环境，通过这行命令启动容器：

```
docker run -d --name base-env cc0de/base-env
```

## 其他方式

如果你是个专业Linux用户，可以选择适合你自己的环境搭建方法（例如：虚拟机、WSL2和本机安装Linux）。

以下是本实验的依赖包清单：

- build-essential
- cmake
- flex
- bison
- libreadline-dev
- googletest

关于如何安装googletest：

1. 克隆[googletest]()代码库（或者直接使用UniBase/deps/googletest）
2. cd googletest
3. mkdir build && cd build
4. cmake ..
5. sudo make install
