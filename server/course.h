#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
    Course();

    std::string getRoom() const;
    void setRoom(const std::string &value);

    std::string getBuilding() const;
    void setBuilding(const std::string &value);

    std::string getTerm() const;
    void setTerm(const std::string &value);

    std::string getInstructor() const;
    void setInstructor(const std::string &value);

    std::string getCourseCode() const;
    void setCourseCode(const std::string &value);

private:
    std::string courseCode;
    std::string instructor;
    std::string term;
    std::string building;
    std::string room;
};

#endif // COURSE_H
