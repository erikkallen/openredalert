// Archive.h
// 1.2

//    This file is part of OpenRedAlert.
//
//    OpenRedAlert is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, version 2 of the License.
//
//    OpenRedAlert is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with OpenRedAlert.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "SDL/SDL_types.h"

/**
 * Abstract interface to manipulate VFile in archives
 */
class Archive
{
public:
    virtual ~Archive() {}
    virtual const char *getArchiveType() const = 0;
    virtual bool loadArchive(const char *fname) = 0;
    virtual void unloadArchives() {};
    virtual size_t getFile(const char *fname) = 0;
    virtual void releaseFile(size_t file) = 0;

    virtual Uint32 readByte(size_t file, Uint8 *databuf, Uint32 numBytes) = 0;
    virtual Uint32 readWord(size_t file, Uint16 *databuf, Uint32 numWords) = 0;
    virtual Uint32 readThree(size_t file, Uint32 *databuf, Uint32 numThrees) = 0;
    virtual Uint32 readDWord(size_t file, Uint32 *databuf, Uint32 numDWords) = 0;

    /**
     * Read a line of file.
     * \param file id of the file in archive
     * \param databuf will contain the read  line
     * \param buflen size of the buffer
     */
    virtual char* readLine(size_t file, char *databuf, Uint32 buflen) = 0;

    /* Since only external files can write, we provide stubs here for the other
     * plugins.
     */
    virtual Uint32 writeByte(size_t file, const Uint8* databuf, Uint32 numBytes) {return 0;}
    virtual Uint32 writeWord(size_t file, const Uint16* databuf, Uint32 numWords) {return 0;}
    virtual Uint32 writeThree(size_t file, const Uint32* databuf, Uint32 numThrees) {return 0;}
    virtual Uint32 writeDWord(size_t file, const Uint32* databuf, Uint32 numDWords) {return 0;}
    virtual void writeLine(size_t file, const char* databuf) {}
    
    virtual void flush(size_t file) {}

    virtual void seekSet(size_t file, Uint32 pos) = 0;
    virtual void seekCur(size_t file, Sint32 pos) = 0;

    virtual Uint32 getPos(size_t file) const = 0;
    virtual Uint32 getSize(size_t file) const = 0;
    virtual const char* getPath(size_t filenum) const = 0;
};

#endif //ARCHIVE_H
