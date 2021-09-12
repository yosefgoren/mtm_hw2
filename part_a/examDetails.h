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
        friend ostream& operator<<(ostream& os, const ExamDetails& details);


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

    };

    bool operator<(const ExamDetails& first, const ExamDetails& second);
}

#endif
