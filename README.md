# VideoCodecs
VidecoCodecs is a GUI application for testing visual quality of the most popular encoders.
It uses ffmpeg for encoding and decoding raw video bit stream yuv420 (.yuv,.y4m).

###Encoding / Decoding:

Supported encoders are H.264, H.265. VP8, VP9, FLV, Dirac, SorensonSpark,VMW8.
Available encoding options basicaly depend on chosen codec. (Bit rate, Profile, Level, Preset, CFR, Two pass, Fps, Speed, Test sequence)
You can also open more files at once and queue them.

###Testing
This application contains implementation of three objective video quality assessment algorithms. PSNR, SSIM and M-SVD.
You can export results into csv file or directly show a graph.
It is also possible to simulate error transmission channel by defining BER or SER.

