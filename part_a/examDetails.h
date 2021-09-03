#ifndef EXAM_DETAILS_H
#define EXAM_DETAILS_H

#include <string>
#include <exception>
#include <iostream>
#include <cmath>

using std::endl;
using std::exception;
using std::ostream;

namespace mtm{

    class ExamDetails{  
    public:
        ExamDetails() = default;
        ExamDetails(int course_number, unsigned int month, unsigned int day,
            double hour, unsigned int duration, std::string zoom_link = "");

        class InvalidDateException : public std::exception {};
        class InvalidTimeException : public std::exception {};

        ~ExamDetails() noexcept;
        ExamDetails(const ExamDetails& source);
        ExamDetails& operator=(const ExamDetails& source);
        const std::string& getLink() const;
        void setLink(const std::string& new_link);
        int operator-(const ExamDetails& other) const;
        static ExamDetails makeMatamExam(); 

        static constexpr unsigned int MIN_MONTH = 1;
        static constexpr unsigned int MAX_MONTH = 12;
        static constexpr unsigned int MIN_DAY = 1;
        static constexpr unsigned int MAX_DAY = 30;
        static constexpr double HALF_HOUR = 0.5 ;

    private:
        int course_number;
        unsigned int month;
        unsigned int day;
        double hour;
        unsigned int duration;
        std::string zoom_link;

        static std::string hourToString(double hour);
        friend ostream& operator<<(ostream& os, const ExamDetails& details);

    };

    // bool operator<(const ExamDetails& first, const ExamDetails& second);

    ostream& operator<<(ostream& os, const ExamDetails& details)
    { 
        os << "Course Number: " <<  details.course_number << endl;
        os << "Time: " << details.day << "." << details.month << " at " 
        << ExamDetails::hourToString(details.hour) << endl; 

        os << "Duration: " << ExamDetails::hourToString((double)details.duration) << endl; 
        os << "Zoom Link: " << details.zoom_link << endl;
        return os;
    }
}

#endif
