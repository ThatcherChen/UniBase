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
docker run -d --name base-env -v ${local-code-path}:/mnt/UniBase cc0de/base-env
```

其中${local-code-path}请替换为你本地的代码路径。

此处有经验的同学也可以直接在容器中克隆代码，然后利用VSCode的dev-container插件直接编辑容器中的代码。

要进入容器中执行命令，通过这行命令启动交互式终端：

```
docker exec -it base-env /bin/bash
```

如果你觉得预打包的镜像不够好，专业用户也可以通过UniBase/docker/dockerfile手动构建镜像：

```
cd UniBase/docker && docker build .
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

1. 克隆[googletest](https://github.com/google/googletest)代码库（或者直接使用UniBase/deps/googletest）
2. cd googletest
3. mkdir build && cd build
4. cmake ..
5. make && sudo make install
