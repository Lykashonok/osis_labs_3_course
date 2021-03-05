#!/bin/bash

ps -Ao user,pcpu,pmem,start,time,cmd --sort=-pcpu | head -n 6 > $1