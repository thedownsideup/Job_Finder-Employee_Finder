#include "Job.hpp"

Job::Job(std::string companyId, std::string jobTitle,std:: map<std::string, float> jobConditions)
{
	companyName = companyId;
	title = jobTitle;
	conditions = jobConditions;
}

std::map<std::string, float> Job::getConditions()
{
	return conditions;
}

std::string Job::getTitle()
{
	return title;
}

std::string Job::getCompanyName()
{
	return companyName;
}

std::vector<User*> Job::getApplicants()
{
	return applicants;
}

void Job::addJobRequest(User* user)
{
	applicants.push_back(user);
}