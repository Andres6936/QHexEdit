#ifndef JUNK_H
#define JUNK_H

#include <QtCore>

struct Chunk
{
    QByteArray data;
    QByteArray dataChanged;
    qint64 absPos;
};

class Chunks
{
public:
    // Constructors and file settings
    Chunks();
    Chunks(QIODevice &ioDevice);
    bool setIODevice(QIODevice &ioDevice);

    // Getting data out of Chunks
    QByteArray data(qint64 pos=0, qint64 count=-1, QByteArray *highlighted=0);
    bool data(QIODevice &iODevice, qint64 pos=0, qint64 count=-1);

    // Set and get highlighting infos
    void setDataChanged(qint64 pos, bool dataChanged);
    bool dataChanged(qint64 pos);

    // Search API
    qint64 indexOf(const QByteArray &ba, qint64 from);
    qint64 lastIndexOf(const QByteArray &ba, qint64 from);

    // Char manipulations
    bool insert(qint64 pos, char b);
    bool overwrite(qint64 pos, char b);
    bool removeAt(qint64 pos);

    // Utility functions
    char operator[](qint64 pos);
    qint64 pos();
    qint64 size();


private:
    int getChunkIndex(qint64 absPos);

    QIODevice * _ioDevice;
    qint64 _pos;
    qint64 _size;
    QList<Chunk> _chunks;

#ifdef MODUL_TEST
public:
    int chunkSize();
#endif
};

#endif // JUNK_H
