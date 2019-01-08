//
// Created by Max on 07-Jan-19.
//

#ifndef EINDOPDRACHT_FILEREADER_H
#define EINDOPDRACHT_FILEREADER_H


#include "nostd/String.h"
#include <fstream>

class FileReader {
public:
    explicit FileReader(const char* filename);
    ~FileReader();

    /* GetLine from current loaded file */
    const nostd::String GetLine();

    /* Check if eof flag is set */
    const bool EndOfFile();

private:
    std::ifstream _file_stream;
};


#endif //EINDOPDRACHT_FILEREADER_H
