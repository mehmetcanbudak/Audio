/* Audio Library for Teensy 3.X
 * Copyright (c) 2014, Paul Stoffregen, paul@pjrc.com
 *
 * Development of this audio library was funded by PJRC.COM, LLC by sales of
 * Teensy and Audio Adaptor boards.  Please support PJRC's efforts to develop
 * open source software by purchasing Teensy or other PJRC products.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, development funding notice, and this permission
 * notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//
// Created by Nicholas Newdigate on 10/02/2019.
//

#ifndef TEENSYAUDIOLIBRARY_PLAY_SD_RAW_RESAMPLED_H
#define TEENSYAUDIOLIBRARY_PLAY_SD_RAW_RESAMPLED_H
#include "Arduino.h"
#include "AudioStream.h"
#include "SD.h"
#include "stdint.h"
#include "utility/ResamplingSdReader.h"

class AudioPlaySdRawResampled : public AudioStream
{
public:
    AudioPlaySdRawResampled(void) :
            AudioStream(0, NULL),
            sdReader()
    {
        begin();
    }

    void begin(void);
    bool play(const char *filename);
    void stop(void);
    bool isPlaying(void) { return playing; }
    uint32_t positionMillis(void);
    uint32_t lengthMillis(void);
    virtual void update(void);

    void setPlaybackRate(float f) {
        sdReader.setPlaybackRate(f);
    }

    void setLoopType(loop_type t) {
        sdReader.setLoopType(t);
    }

private:

    uint32_t file_size;
    volatile uint32_t file_offset;
    volatile bool playing;
    ResamplingSdReader sdReader;
};

#endif //TEENSYAUDIOLIBRARY_PLAY_SD_RAW_RESAMPLED_H
