//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_NOT_FOUND_IN_FILE_H
#define EINDOPDRACHT_NOT_FOUND_IN_FILE_H

#include <exception>

class PortNotFoundException : public std::exception {
public:
    explicit PortNotFoundException(const char* message) : _message{message} {}
    ~PortNotFoundException() noexcept override = default;

    const char* what() const noexcept override { return _message; }

private:
    const char* _message;
};

#endif //EINDOPDRACHT_NOT_FOUND_IN_FILE_H
