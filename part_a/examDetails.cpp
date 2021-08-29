#include "examDetails.h"
#include <cmath>

using namespace mtm;

static bool isValidHour(double hour){
    if(hour < 0){
        return false;
    }
    double intpart;
    if( std::modf(hour, &intpart) != ExamDetails::HALF_HOUR ){
        return false;
    }
    return true;
        
}

ExamDetails::ExamDetails(int course_number, unsigned int month, unsigned int day,
    double hour, unsigned int duration, std::string zoom_link): course_number(course_number),
    month(month), day(day), duration(duration), zoom_link(zoom_link) {
    if(month < MIN_MONTH || month > MAX_MONTH || day < MIN_DAY || day > MAX_DAY){
        throw InvalidDateException();
    }
    if(!isValidHour(hour) ){
        throw InvalidTimeException();
    }
}

ExamDetails::~ExamDetails(){}

ExamDetails::ExamDetails(const ExamDetails& source): course_number(source.course_number),
    month(source.month), day(source.day), duration(source.duration), zoom_link(source.zoom_link) {}

ExamDetails& ExamDetails::operator=(const ExamDetails& source){
    if (this == &source){
        return *this;
    }
    course_number = source.course_number;
    month = source.month;
    day = source.day;
    duration = source.duration;
    zoom_link = source.zoom_link;
    return *this;
}

const std::string& ExamDetails::getLink() const{
    return zoom_link;
}

void ExamDetails::setLink(const std::string& new_link){
    zoom_link = new_link;
}

int ExamDetails::operator-(const ExamDetails& other) const{ 
    //if we are not in the same year we might have an issue :(
    return MAX_DAY*(month - other.month) + day - other.day;
}

bool operator<(const ExamDetails& first, const ExamDetails& second){ //changed to non-member function
    return first-second < 0;
}




ExamDetails ExamDetails::makeMatamExam(){
    return ExamDetails(234124, 7, 28, 13, 3, "https://tinyurl.com/59hzps6m");
}

std::string ExamDetails::hourToString(double hour){
    unsigned int hour_halfs = std::nearbyint(hour*2);
    std::string result = std::to_string(hour_halfs/2);
    result += ":";
    result += hour_halfs%2 ? "00" : "30";
    return result;
}
