#include "izod.h"
#include <string>
using std::string;

//FILEAUDIO

FileAudio::FileAudio(const string& tit, int Idim): titolo(tit), dim(Idim){};
FileAudio::~FileAudio(){}

//MP3

int okBitRate = 192;

Mp3::Mp3(const string& tit, int Idim, int br): FileAudio(tit,Idim), bitRate(br){};

Mp3* Mp3::clone(){
    return new Mp3(*this);
}

bool Mp3::qualita(){
    return bitRate >= okBitRate;
}

//WAV

int okFreq = 96;

WAV::WAV(const string& tit, int Idim, int CF, bool ll): FileAudio(tit, Idim), cFreq(CF), lossless(ll){};

WAV* WAV::clone(){
    return new WAV(*this);
}

bool WAV::qualita(){
    return cFreq >= okFreq;
}


//BRANO

iZod::Brano::Brano(*FileAudio f): file(f->clone()) {};

iZod::Brano::Brano(const Brano& b): file(b.file->clone()){};

iZod::Brano::~Brano()
{
    delete file;
}

//IZOD

#include <vector>
void iZod::insert(Mp3* m){
    if ( std::find(mem.begin(), mem.end(), m) != mem.end() ){}
        mem.push_front(*m);
    }
}



