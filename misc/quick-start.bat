@echo off

REM 克隆 UniBase 仓库
git clone --recursive https://github.com/ThatcherChen/UniBase.git

REM 启动 Docker 容器
docker run -itd -v "%cd%\UniBase:/mnt/UniBase" --name unibase-env-test base-env

REM 进入 Docker 容器
docker exec -it unibase-env bash -c "cd /mnt/UniBase && mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug"

REM 进入交互模式
docker attach unibase-env