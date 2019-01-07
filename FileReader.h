//
// Created by Max on 07-Jan-19.
//

#ifndef EINDOPDRACHT_FILEREADER_H
#define EINDOPDRACHT_FILEREADER_H


#include "nostd/String.h"
#include <fstream>

class FileReader {
public:
    FileReader() = default;
    ~FileReader() = default;

    nostd::String GetLine() {
        char buffer[512];
        std::ifstream file_stream{"schepen.csv"};
        file_stream.getline(buffer, sizeof(buffer));
        return nostd::String{buffer};
    }

};


#endif //EINDOPDRACHT_FILEREADER_H
