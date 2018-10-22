//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_ROOM_H
#define EINDOPDRACHT_ROOM_H

class Room {
public:
    Room();
    ~Room();
    explicit Room(const int Id);
    Room(const Room& r);
    Room(Room&& r);

    Room& operator=(const Room& copy);
    Room& operator=(Room&& move) noexcept;

    char GetChar();
    bool IsStart = false;
    bool IsEndBoss = false;
    bool IsStairUp = false;
    bool IsStairDown = false;
    bool IsVisited = false;

private:
    int _Id;
    void copy_from(const Room& r);
    void move_from(Room& r);
};


#endif //EINDOPDRACHT_ROOM_H
