//
// Created by Max on 07-Jan-19.
//

#include "FileReader.h"
#include "exceptions/OutOfFileException.h"

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

//NOTE I return a ptr to heap memory here cause I cannot return a null object or nullptr when copying a stack object.
//In order to copy the stack object I need it to be an object of type nostd::String. I could return an empty string but I prefer this method.
nostd::String* FileReader::GetSpecificLine(const nostd::String line_specifier) {
    while(!EndOfFile()) {
        nostd::String* s = new nostd::String{GetLine()};
        nostd::String* ptr = s->Split(';');
        //line didn't contain ';' delim
        //If the first column matches the line_specifier return current line and exit
        if(ptr != nullptr && ptr[0] == line_specifier) {
            return s;
        }
        delete s;
        delete[] ptr;
    }
    return nullptr;
}

nostd::String FileReader::GetNthLine(const size_t n) {
    size_t count = 0;
    while(!EndOfFile()) {
        nostd::String s = GetLine();
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
