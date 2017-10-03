#!/bin/bash
$NDK/ndk-build
adb push libs/armeabi-v7a/* /data/local/tmp/ && \
  adb shell 'LD_LIBRARY_PATH=/data/local/tmp /data/local/tmp/foo'
