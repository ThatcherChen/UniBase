# UniBase base-env setup

尽管配置基础环境有非常多的方法，但是我们仍然推荐使用docker，这样可以免去安装各种依赖的问题。

## Docker Desktop

对于Windows和MacOS用户，要使用docker，需要先安装[Docker Desktop](https://www.docker.com/products/docker-desktop/)。

我们准备了预先安装所有依赖的docker镜像，可以通过这行命令拉取：

```
docker pull cc0de/base-env:1.0
```

输出信息大致如下：

```
1.0: Pulling from cc0de/base-env
44ba2882f8eb: Already exists
dacbbc89975b: Pull complete
Digest: sha256:1c37a764b836c7cae153ec0d479ec23102c3e09a3ee270b5979c2e6d9b2e6c74
Status: Downloaded newer image for cc0de/base-env:1.0
docker.io/cc0de/base-env:1.0
```

如果要运行这个环境，通过这行命令启动容器：

```
docker run -td --name base-env -v ${local-code-path}:/mnt/UniBase cc0de/base-env
```

输出信息是一个ID：

```
973638df18df55511b5291f193ae5d8e4851d8d7be1c273d7f5f7f8d243aa8ed
```

其中${local-code-path}请替换为你本地的代码路径。

此处有经验的同学也可以直接在容器中克隆代码，然后利用VSCode的dev-container插件直接编辑容器中的代码。

要进入容器中执行命令，通过这行命令启动交互式终端：

```
docker exec -it base-env /bin/bash
```

输出信息是bash的prompt：

```
root@973638df18df:/#
```

如果你觉得预打包的镜像不够好，专业用户也可以通过UniBase/docker/dockerfile手动构建镜像：

```
cd UniBase/docker && docker build .
```

输出信息是构建过程中的依赖包安装输出：

```
[+] Building 222.5s (6/6) FINISHED                                              docker:desktop-linux
 => [internal] load build definition from dockerfile                                            0.0s
 => => transferring dockerfile: 397B                                                            0.0s
 => [internal] load .dockerignore                                                               0.0s
 => => transferring context: 2B                                                                 0.0s
 => [internal] load metadata for docker.io/library/ubuntu:latest                                0.0s
 => CACHED [1/2] FROM docker.io/library/ubuntu:latest                                           0.0s
 => [2/2] RUN apt update -y &&     apt upgrade -y &&     apt install -y build-essential cmak  219.5s
 => exporting to image                                                                          2.9s
 => => exporting layers                                                                         2.9s
 => => writing image sha256:66568815aafca0db6456c3b6d24bf6f4b03545dc48b2d131baf7a22d529936fc    0.0s
 => => naming to docker.io/library/base-env                                                     0.0s
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
