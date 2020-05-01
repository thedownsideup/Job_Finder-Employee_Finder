#include <iostream>
#include <string>
#include <vector>

#include "Experience.hpp"

Experience::Experience(std::string companyId, std::string jobTittle, std::string startedAt, std::string endedAt)
{
    companyName = companyId;
    title = jobTittle;
    startAt = startedAt;
    endAt = endedAt;
}

void Experience::setDisplacedStartAt(std::string start)
{
	displacedStartAt = start;
	return;
}

std::string Experience::getDisplacedStartAt()
{
    return displacedStartAt;
}

std::string Experience::getDisplacedEndAt()
{
    return displacedEndAt;
}

std::string Experience::getCompanyName()
{
    return companyName;
}

std::string Experience::getTitle()
{
    return title;
}

std::string Experience::getStartAt()
{
    return startAt;
}

std::string Experience::getEndAt()
{
    return endAt;
}

