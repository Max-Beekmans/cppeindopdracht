//
// Created by Max on 07-Jan-19.
//

#include "FileReader.h"

FileReader::FileReader(const char* filename) {
    _file_stream.open(filename);
}

FileReader::~FileReader() {
    _file_stream.close();
}

const nostd::String FileReader::GetLine() {
    char buffer[512];
    if(_file_stream.is_open()) {
        _file_stream.getline(buffer, sizeof(buffer));
    }
    return nostd::String{buffer};
}

const bool FileReader::EndOfFile() {
    return _file_stream.eof();
}
