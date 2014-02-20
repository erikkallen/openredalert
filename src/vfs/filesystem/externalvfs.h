// ExternalFiles.h
// 1.0

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

#ifndef EXTERNALVFS_H
#define EXTERNALVFS_H

#include <string>
#include <vector>

#include "SDL/SDL_types.h"

#include "vfs/archive.h"

using std::string;
using std::vector;

/**
 * Object that provide methodes to load/read/write external files (not in original archives of the game
 */
class ExternalFiles : public Archive
{
public:
	ExternalFiles(const char *defpath);
	~ExternalFiles();
	
	const char *getArchiveType() const;
	bool loadArchive(const char *fname);
	/** 
	* Can't use default argument as we need exact type signature for inheritence. 
	* try to load a file. if not found, return -1 else return the filedescriptor(?)
	*/
	size_t getFile(const char* fname);
	///see other overload for details
	size_t getFile(const char *fname, const char* mode);
	void releaseFile(size_t file);

	Uint32 readByte(size_t file, Uint8 *databuf, Uint32 numBytes);
	Uint32 readWord(size_t file, Uint16 *databuf, Uint32 numWords);
	Uint32 readThree(size_t file, Uint32 *databuf, Uint32 numThrees);
	Uint32 readDWord(size_t file, Uint32 *databuf, Uint32 numDWords);
	 /** 
	 * Read a line of file. 
	 */
	char* readLine(size_t file, char *databuf, Uint32 buflen);

	Uint32 writeByte(size_t file, const Uint8 *databuf, Uint32 numBytes);
	Uint32 writeWord(size_t file, const Uint16 *databuf, Uint32 numWords);
	Uint32 writeThree(size_t file, const Uint32 *databuf, Uint32 numThrees);
	Uint32 writeDWord(size_t file, const Uint32 *databuf, Uint32 numDWords);
	void writeLine(size_t file, const char *databuf);
	int vfs_printf(size_t file, const char* fmt, va_list ap);
	void flush(size_t file);

	void seekSet(size_t file, Uint32 pos);
	void seekCur(size_t file, Sint32 pos);

	Uint32 getPos(size_t file) const;
	Uint32 getSize(size_t file) const;
	const char* getPath(size_t file) const;

	static const int ErrorLoadingFile = (Uint32)-1;			///<returned in case file could not be loaded

private:
	string defpath;
	vector<string> path;
};

#endif //EXTERNALVFS_H
