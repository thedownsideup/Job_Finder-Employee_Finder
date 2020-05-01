#include "Company.hpp"


Company::Company(std::string companyName, std::string companyAddress, std::string companyDescription)
{
	name = companyName;
    address = companyAddress;
    description = companyDescription;
}

std::string Company::getCompanyName()
{
    return name;
}

std::string Company::getCompanyAddress()
{
    return address;
}

std::string Company::getCompanyDescription()
{
    return description;
}

std::vector<Experience*> Company::getEmployment()
{
	return employment;
}

void Company::setJobs(Job* job)
{
    jobs.push_back(job);
    return;
}

std::vector<Job* > Company::getJob()
{
    return jobs;
}

Job* Company::searchJob(std::string title)
{
	for(int i = 0; i < jobs.size(); i++)
	{
		if(jobs[i]->getTitle() == title)
		{
			return jobs[i];
		}
	}
	return NULL;
}

void Company::setEmployee(std::string userId, std::string jobTitle,std::string startsAt, std::string endsAt)
{
	Experience* experience = new Experience(userId, jobTitle, startsAt, endsAt);
	employment.push_back(experience);
	return;
}


User* Company::findTheBestApplicant(Job* job)
{
	std::vector<User*> applicants = job->getApplicants();
	if(applicants.size() == 0)
	{
		return NULL;
	}

	User* bestApplicant = applicants[0];
	float maximumSkillRate = bestApplicant->getTotalSkillRate();
	
	for(int i = 0; i < applicants.size(); i++)
	{
		if(applicants[i]->getTotalSkillRate() > maximumSkillRate)
		{
			bestApplicant = applicants[i];
		}
	}
	return bestApplicant;
}

bool Company::isQualified(User* applicant, Job* job)
{
	std::vector<Skill*> skills = applicant->getSkills();
	for(std::map<std::string, float>::iterator it = job->getConditions().begin(); it != job->getConditions().end(); it++)
	{
		bool matched = false;
		for(int i = 0; i < skills.size(); i++)
		{
			if(it->first == skills[i]->getSkillName())
			{
				if(it->second > skills[i]->getSkillRate())
				{
					matched = true;
					break;
				}
			}
		}
		if(!matched)
		{
			return false;
		}
	}
	return true;
}
