//
// Created by MaxBe on 11-Jan-19.
//

#ifndef EINDOPDRACHT_OUTOFFILEEXCEPTION_H
#define EINDOPDRACHT_OUTOFFILEEXCEPTION_H

#include <exception>

namespace exceptions {
class OutOfFileException : public std::exception {
public:
    explicit OutOfFileException(const char* message) : _message(message) {};
    ~OutOfFileException() noexcept override = default;
    const char* what() const noexcept override { return _message; }
private:
    const char* _message;
};
}

#endif //EINDOPDRACHT_OUTOFFILEEXCEPTION_H
