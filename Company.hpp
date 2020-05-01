#ifndef __COMPANY_H__
#define __COMPANY_H__

#include <string>
#include <vector>

#include "User.hpp"
#include "Experience.hpp"
#include "Job.hpp"

class Company
{
    public:

        Company(std::string companyName, std::string companyAddress, std::string companyDescription);
        std::string getCompanyName();
        std::string getCompanyAddress();
        std::string getCompanyDescription();
        std::vector<Experience*> getEmployment();
        void setJobs(Job* job);
        std::vector<Job* > getJob();
        Job* searchJob(std::string jobTitle);
        void setEmployee(std::string userId, std::string jobTitle,std::string startsAt, std::string endsAt = NOW);
		User* findTheBestApplicant(Job* job);
		bool isQualified(User* applicant, Job* job);
		
    private:

        std::string name;
        std::string address;
        std::string description;
        std::vector<Job*> jobs;
        std::vector<Experience*> employment;
};

#endif