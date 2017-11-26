#ifndef IZOD_H
#define IZOD_H

#include<string>
using std::string;

class FileAudio{
private:
    string titolo;
    int dim;
public:
    //Costruttori
    FileAudio(const string&, int);
    //
    virtual FileAudio* clone() = 0;
    virtual bool qualita() = 0;
    virtual ~FileAudio();
};

class Mp3: public FileAudio{
private:
    static int okBitRate;
    int bitRate;
public:
    Mp3(const string&, int, int);
    virtual Mp3* clone();
    virtual bool qualita();
};

class WAV: public FileAudio{
private:
    static int okFreq;
    int cFreq;
    bool lossless;
public:
    WAV(const string&, int, int, bool);
    virtual WAV* clone();
    virtual bool qualita();
};

#include <vector>
using std::vector;
class iZod{
private:
    class Brano{
    private:
        FileAudio* file;
        static Brano copia(const Brano&);
    public:
        Brano(*FileAudio);
        Brano(const Brano&);
        ~Brano();
    };

    vector<*Brano> mem;
public:
    vector<Mp3> mp3(double,int);
    vector<FileAudio*> braniQual();
    void insert(Mp3*);

};











#endif