txplayer
========

a player based on ffmpeg


ANDROID BUILD:

#Before compiling, please set NDK path
#My NDK path like this:
#export ANDROID_NDK=/home/yyl/javatool/android-ndk-r9d
#export PATH=${ANDROID_NDK}:$PATH
#Execute the following command in shell 

1、 cd txplayer
2、 ./init-android.sh
3、 cd android
4、 ./compile-ffmpeg.sh armv7a
5、 ./compile-tx.sh



MAC OS X BUILD:

1、 cd taxpayer
2、 ./init-ios.sh
3、 cd ios
4、 ./compile-ffmpeg.sh all
5、 open TXMediaDemo with Xcode

