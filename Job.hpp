#ifndef __JOB_H__
#define __JOB_H__

#include <string>
#include <vector>
#include <map>

#include "User.hpp"

#define NOW "INDIFINITE_DATE"

class Job
{
	public:
		
		Job(std::string companyId, std::string jobTitle,std:: map<std::string, float> jobConditions);
		void addJobRequest(User* user);
		std::string getTitle();
		std::string getCompanyName();
		std::vector<User*> getApplicants();
		std::map<std::string, float> getConditions();
	private:
		
		std::string title;
		std::string companyName;
		std::map<std::string, float> conditions;
		std::vector<User*> applicants;
};

#endif
