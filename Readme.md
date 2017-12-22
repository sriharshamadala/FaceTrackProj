Project by: Yan Meng, Sriharsha Madala.

1. Refer to the report for a detailed description of the project.
2. Refer to the presentation to see the changes made to the open source JM decoder for our implementation.
3. Executing the source code is same as before. Use lencod.exe to encode any .yuv file. Make sure to configure the encoder using  encoder.cfg
4. If you have a h264 encoded bit stream, run ldecod.exe. configuration is done using decoder.cfg.

# Install YUV viewer
I installed the [pyuv-player](https://github.com/gbaruffa/pyuv-player). While there are several choices, I found this one easiest to install. 

# Compile 
```bash
make clean
make install
```

# Test 
```bash
cd JM/bin
./ldecod.exe
```
To play the output file, open it with the pyuv-player. Go to File-\>Format to select resolution, color space, subsampling and ordering. If these are not chosen correctly, you will not be able to view the video.

