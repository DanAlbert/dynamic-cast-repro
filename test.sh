#!/bin/bash
set -e

TEST_PATH=/data/local/tmp/dyncast

$NDK/ndk-build -B -j8
adb shell rm -rf $TEST_PATH
adb shell mkdir -p $TEST_PATH
adb push libs/armeabi-v7a/* $TEST_PATH
adb shell "LD_LIBRARY_PATH=$TEST_PATH $TEST_PATH/foo $@"
