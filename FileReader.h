//
// Created by Max on 07-Jan-19.
//

#ifndef EINDOPDRACHT_FILEREADER_H
#define EINDOPDRACHT_FILEREADER_H


#include "nostd/String.h"
#include <fstream>

class FileReader {
public:
    //Default constructor for filereader.
    //If this method of construction is chosen FileReader.Open(filename) needs to be called
    FileReader();
    explicit FileReader(const char* filename);
    ~FileReader();

    /* GetLine from current loaded file */
    const nostd::String GetLine();

    /* Check if eof flag is set */
    const bool EndOfFile();

    /* Read for specific line that starts with given string */
    /* specifier has to be in the first column */
    /* if the specifier can't be found a nullptr is returned */
    const nostd::String* GetSpecificLine(nostd::String line_specifier);

    /* Opens _file_stream with file.
    returns false is already opened or if file can't be found */
    bool Open(const char* filename);

    /* Closes _file_stream */
    void Close();

private:
    std::ifstream _file_stream;
};


#endif //EINDOPDRACHT_FILEREADER_H
