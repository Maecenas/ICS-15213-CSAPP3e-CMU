# ICS-15213-CSAPP3e-CMU

[![Open Source Society University - Computer Science](https://img.shields.io/badge/OSSU-computer--science-blue.svg)](https://github.com/ossu/computer-science)
[![Docker Pulls](https://img.shields.io/docker/pulls/lx70716/cmu-15213.svg)](http://hub.docker.com/r/lx70716/cmu-15213)
[![Docker Stars](https://img.shields.io/docker/stars/lx70716/cmu-15213.svg)](http://hub.docker.com/r/lx70716/cmu-15213)

[<img src="http://csapp.cs.cmu.edu/3e/images/csapp3e-cover.jpg" align=right hspace=10 width=150 alt = "Computer Systems: A Programmer's Perspective, 3/E (CS:APP3e) textbook">](https://www.cs.cmu.edu/~213/)

The ICS ([Introduction to Computer Systems, 15-213/18-213/15-513](https://www.cs.cmu.edu/~213/)) course of Carnegie Mellon University provides a programmer's view of how computer systems execute programs, store information, and communicate. It enables students to become more effective programmers, especially in dealing with issues of performance, portability and robustness. It also serves as a foundation for courses on compilers, networks, operating systems, and computer architecture, where a deeper understanding of systems-level issues is required. Topics covered include: machine-level code and its generation by optimizing compilers, performance evaluation and optimization, computer arithmetic, memory organization and management, networking technology and protocols, and supporting concurrent computation.

## Lab Assignments

- C Programming Lab
- Data Lab
- Bomb Lab
- Attack Lab
- Cache Lab
- Shell Lab
- Malloc Lab
- Proxy Lab

## Developing Environment Setup with Docker

The following is about a containerized developing environment for 15213, based on Docker and Ubuntu.

```bash
$ git clone git@github.com:Maecenas/ICS-15213-CSAPP3e-CMU.git && cd ICS-15213-CSAPP3e-CMU
$ docker-compose run --rm shark
# can also run with Docker
$ docker run --rm -v "`pwd`"/labs:/usr/src/app/ -it lx70716/cmu-15213
```

## Reference

- [_Computer Systems: A Programmer's Perspective, 3/E (CS:APP3e)_](http://csapp.cs.cmu.edu/), Randal E. Bryant and David R. O'Hallaron, Pearson, 2016

