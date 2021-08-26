#include "examDetails.h"

using namespace mtm;

ExamDetais::ExamDetais(int course_number, unsigned int month, unsigned int day,
    double hour, unsigned int duration, std::string zoom_link): course_number(course_number),
    month(month), day(day), duration(duration), zoom_link(zoom_link) {}

class ExamDetails::IndalidDateException{};
class ExamDetails::IndalidTimeException{};
class ExamDetails::IndalidArgsException{};

ExamDetails::~ExamDetails(){}

ExamDetails::ExamDetails(const ExamDetails& source): course_number(source.course_number),
    month(source.month), day(source.day), duration(source.duration), zoom_link(source.zoom_link) {}

void ExamDetails::operator=(const ExamDetails& source){
    course_number = source.course_number;
    month = source.month;
    day = source.day;
    duration = source.duration;
    zoom_link = source.zoom_link;
}

const std::string& ExamDetails::getLink() const{
    return zoom_link;
}

void ExamDetails::setLink(const std::string& new_link){
    zoom_link = new_link;
}

int ExamDetails::operator-(const ExamDetails& other) const{ 
    //if we are not in the same year we might have an issue :(
    return DAYS_IN_MONTH*(month - other.month) + day - other.day;
}

bool ExamDetails::operator<(const ExamDetails& other) const{
    return *this - other < 0;
}

ostream& operator<<(ostream& os, const ExamDetails& details){
    os << "Course Number: " <<  details.course_number << endl;
    os << "Time: " << details.day << "." << details.month << " at " 
        << ExamDetails::hourToString(details.hour) << endl; 
    os << "Duration: " ExamDetails::hourToString(details.duration) << endl; 
    os << "Zoom Link: " << details.zoom_link << endl;
    return os;
}

static ExamDetails ExamDetails::makeMatamExam(){
    return ExamDetails(234124, 7, 28, 13, 3, "59hzps6m/com.tinyurl://h");
}