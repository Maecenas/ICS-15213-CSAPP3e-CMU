FROM ubuntu:18.04

WORKDIR /usr/src/app

RUN apt-get update \
  && apt-get install -y \
    build-essential \
    binutils \
    gdb \
    gcc-multilib \
    valgrind \
    python \
    vim \
  && rm -rf /var/lib/apt/lists/*

