#ifndef EXAM_DETAILS
#define EXAM_DETAILS

#include <string>
#include <exception>
#include <iostream>

namespace mtm{
    class ExamDetails{
    public:
        ExamDetais(int course_number, unsigned int month, unsigned int day,
            double hour, unsigned int duration, std::string zoom_link);

        class IndalidDateException : public std::exception;
        class IndalidTimeException : public std::exception;
        class IndalidArgsException : public std::exception;

        ~ExamDetails() noexcept;
        ExamDetails(const ExamDetails& source);
        ExamDetails& operator=(const ExamDetails& source);
        const std::string& getLink() const;
        void setLink(const std::string& new_link);

        static constexpr unsigned int DAYS_IN_MONTH = 30;
        int operator-(const ExamDetails& other) const;
        bool operator<(const ExamDetails& other) const;
        friend ostream& operator<<(ostream& os, const ExamDetails&);
    
        static ExamDetails makeMatamExam();  
    };

    private:
        int course_number;
        unsigned int month;
        unsigned int day;
        double hour;
        unsigned int duration;
        std::string zoom_link;

    static std::string hourToString(double hour);
}

#endif
