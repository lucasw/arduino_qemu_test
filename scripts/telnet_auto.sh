#!/bin/sh
PORT=5678
while :
do
  telnet localhost $PORT
  sleep 1
done
