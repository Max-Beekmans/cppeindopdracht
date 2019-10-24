//
// Created by Max on 07-Jan-19.
//

#include "FileReader.h"
#include "exceptions/OutOfFileException.h"

FileReader::FileReader(const char* filename) {
    Open(filename);
}

FileReader::~FileReader() {
    Close();
}

const std::string FileReader::GetLine() {
    char buffer[512];
    if(_file_stream.is_open()) {
        _file_stream.getline(buffer, sizeof(buffer));
    }
    return std::string{buffer};
}

const bool FileReader::EndOfFile() {
    return _file_stream.eof();
}

//NOTE I return a ptr to heap memory here cause I cannot return a null object or nullptr when copying a stack object.
//In order to copy the stack object I need it to be an object of type std::string. I could return an empty string but I prefer this method.
std::string* FileReader::GetSpecificLine(const std::string line_specifier) {
    while(!EndOfFile()) {
        std::string* s = new std::string{GetLine()};
        std::string* ptr = s->Split(';');
        //line didn't contain ';' delim
        //If the first column matches the line_specifier return current line and exit
        if(ptr != nullptr && ptr[0] == line_specifier) {
            delete[] ptr;
            return s;
        }
        delete s;
        delete[] ptr;
    }
    return nullptr;
}

std::string FileReader::GetNthLine(const size_t n) {
    size_t count = 0;
    while(!EndOfFile()) {
        std::string s = GetLine();
        if(count == n) {
            return s;
        }
        count++;
    }
    throw exceptions::OutOfFileException("line number N is not in the file.");
}

bool FileReader::Open(const char* filename) {
    if(_file_stream.is_open()) {
        return false;
    }
    _file_stream.open(filename);
    return _file_stream.good();
}

bool FileReader::Close() {
    if(!_file_stream.is_open()) {
        return false;
    }
    _file_stream.close();
    return true;
}
