#ifndef __EXPERIENCE_H__
#define __EXPERIENCE_H__

#include <vector>
#include <string>

#define NOW "INDIFINITE_DATE"

class Experience
{
    public:
        Experience(std::string companyId, std::string jobTittle, std::string startedAt, std::string endedAt);
        std::string getCompanyName();
        std::string getTitle();
        std::string getStartAt();
        std::string getEndAt();
        std::string getDisplacedStartAt();
        std::string getDisplacedEndAt();
        void setDisplacedStartAt(std::string start);

    private:

        std::string companyName;
        std::string title;
        std::string startAt;
        std::string endAt;
        std::string displacedStartAt;
        std::string displacedEndAt;
};

#endif