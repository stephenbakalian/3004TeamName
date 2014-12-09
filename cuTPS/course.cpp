#include "course.h"

Course::Course()
{
}
std::string Course::getRoom() const
{
    return room;
}

void Course::setRoom(const std::string &value)
{
    room = value;
}
std::string Course::getBuilding() const
{
    return building;
}

void Course::setBuilding(const std::string &value)
{
    building = value;
}
std::string Course::getCourseNum() const
{
    return courseNum;
}

void Course::setCourseNum(const std::string &value)
{
    courseNum = value;
}
std::string Course::getTerm() const
{
    return term;
}

void Course::setTerm(const std::string &value)
{
    term = value;
}
std::string Course::getInstructor() const
{
    return instructor;
}

void Course::setInstructor(const std::string &value)
{
    instructor = value;
}
std::string Course::getCourseCode() const
{
    return courseCode;
}

void Course::setCourseCode(const std::string &value)
{
    courseCode = value;
}






