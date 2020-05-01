#ifndef __USERANDCOMPANY_H__
#define __USERANDCOMPANY_H__

#include <string>
#include <map>
#include <vector>

#include "User.hpp"
#include "Company.hpp"

class UserAndCompany
{
	public:
		void addUser(std::string firstName, std::string lastName, std::string emailAddress, std::string biography);
		void addCompany(std::string name, std::string address, std::string description);
		void addExperience(std::string userId, std::string companyId, std::string title, std::string startAt, std::string endsAt);
		void assignSkillToUser(std::string userId, std::string skillName);
		void printUser(std::string userId);
		void printCompany(std::string companyName);
		void endorse(std::string endorserUserId, std::string skilledUserId, std::string skillName);
		void addFollower(std::string followerId, std::string followingId);
		void addJobRequest(std::string companyName, std::string title, std::map<std::string, float> conditions);
		void addApplicants(std::string userId, std::string companyId, std::string jobTitle);
		void hire(std::string companyId, std::string jobTitle, std::string startsAt);
		void printSuggestedUsers(std::string companyName, std::string jobTitle);
		void printSuggestedJobs(std::string userId);
		bool checkJobExistence(std::string title, std::string companyId);
		void printExperiences(std::string userId);
		void printSkills(std::string userId);
		void printJobs(std::string companyName);
		User* searchUser(std::string userId);
    	Company* searchCompany(std::string companyName);
    	bool checkUserExistence(std::string userId);
    	bool checkCompanyExistence(std::string companyId);
    	void printRequests(std::string companyId);
     
	private:
		std::vector<User*> users;
        std::vector<Company*> companies;
};

#endif