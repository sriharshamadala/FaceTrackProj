## Overview
Autonomous control of Pan-Tilt-Zoom (PTZ) camera is an interesting field of research with numerous applications such as recording lectures, seminars, live coverage of sports, video surveillance, etc. The work done in this project is preliminary in that regard. This work targets a more simplistic scenario of recording a live lecture, where the subject has constrained motion. A PTZ camera records the subject live and the h.264 encoder generates the encoded bit stream in real-time. Traditional facial recognition algorithms can be used to track the subject but they fail in some scenarios such as the subject facing away from the camera or a poster in the background. The objective of this project is to assist traditional Facial recognition algorithms to improve their accuracy by simply using the motion vectors available in the bit stream. We proposed an algorithm to track multiple subjects with motion in each frame.

## Install YUV viewer
I installed the [pyuv-player](https://github.com/gbaruffa/pyuv-player). While there are several choices, I found this one easiest to install. 

## Compile 
```bash
make clean
make install
```

## demo

![before](demo/hall_demo_before.gif) ![after](demo/hall_demo_after.gif)

* Download your choice of [raw yuv sequence](http://trace.eas.asu.edu/yuv/)
* Note the resolution (352x288 px), color space (yuv) and subsampling (4:2:0). This information is necessary for both the encoder and viewing the raw file.
* View the input file with pyuv-player. You may need to set the format (`File->Format`) based on the above information to view the sequency correctly.
* Place the input file in a convenient location (`JM/input`)
* Modify the following variables in `JM/bin/encoder.cfg` as needed:
  * InputFIle
  * FramesToBeEncoded
  * SourceWidth
  * SourceHeight
  * OutputWidth
  * OutputHeight
  * ReconFile
  * OutputFIle
  * StatsFile
* Execute the encoder as follows. This will take a long time depending on the number of frames being encoded (300 frames took approx 30 mins).
```bash
cd JM/bin
./lencod.exe
```
* The output of the above step generates another raw video sequence (i.e, no containers like .avi or .mkv) encoded based on H.264 standard. This file has the motion vector information embeded in it.
* To run the decoder, set the configuration variables - `InputFile, OutputFile`, in `JM/bin/decoder.cfg`.
* Run the decoder like so:
```bash
cd JM/bin
./ldecod.exe
```
* The output file contains the same input video sequence but in each frame, a box is drawn to identify the motion of the subject.
* If you have a h264 encoded bit stream, you can skip the encoder step and run the decoder directly. Use ffmpeg when necessary to convert files to and from .264 format.
```bash
ffmpeg -f h264 -i test.264 demo.mp4
ffmpeg -i demo.mp4 -vcodec libx264 test.264
```

## Documentation
Refer to the report for a detailed description of the project. Refer to the presentation to see the changes made to the open source JM decoder for our implementation.

## Future Work
* Only verified the latest software working on Ubuntu 17.10. Need to port it to work on other OSes.
* Need to separate JM code from the changes we made to make it easier to update JM whenever needed. Also keeps the changes clear.

## Credits
Project by: Yan Meng, Sriharsha Madala.
