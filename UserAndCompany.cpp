#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "UserAndCompany.hpp"

struct sorter
{
	bool operator() (Experience* a,Experience* b) { return (a->getDisplacedStartAt() < b->getDisplacedStartAt());}
}sortobj;

void UserAndCompany::addUser(std::string firstName, std::string lastName, std::string emailAddress, std::string biography)
{
	if(checkUserExistence(emailAddress) ==  false)
	{
		User* user = new User(firstName, lastName, emailAddress, biography);
       	users.push_back(user);
    }
    return;
}

void UserAndCompany::addCompany(std::string name, std::string address, std::string description)
{
	if(checkCompanyExistence(name) == false)
	{
		Company* company = new Company(name, address, description);
        companies.push_back(company);
    }
    return;
}

void UserAndCompany::addExperience(std::string userId, std::string companyId, std::string title, std::string startAt, std::string endsAt)
{
	User* user = searchUser(userId);
	Company* company = searchCompany(companyId);

    if(user != NULL && company != NULL)
    {
    	Experience* experience = new Experience(companyId, title, startAt, endsAt);
   		user->setExperiences(experience);
   		company->setEmployee(userId, title, startAt, endsAt);
	}
    return;
}

void UserAndCompany::assignSkillToUser(std::string userId, std::string skillName)
{
    User* user = searchUser(userId);
    if(user != NULL)
    {
    	Skill* skill = new Skill;
    	skill->setSkillName(skillName);
   		user->setSkills(skill);
	}
    return;
}

void UserAndCompany::printUser(std::string userId)
{
	User* user = searchUser(userId);
	if(user != NULL)
	{
	    std::cout << "Name: " << user->getFirstName() << " " << user->getLastName() << std::endl;
	    std::cout << "Email: " << user->getEmailAddress() << std::endl;
	    std::cout << "Biography: " << user->getBiography() << std::endl;
	    std::cout << "Network: " << user->getFollowersCount() + user->getFollowingsCount() << " connections" << std::endl;
	    std::cout << "Experiences:" << std::endl;
	    printExperiences(userId);
	    std::cout << "Skills:" << std::endl;
	    printSkills(userId);
	}
    return;
}

void UserAndCompany::printCompany(std::string companyName)
{
	Company* company = searchCompany(companyName);
	if(company != NULL)
	{
	    std::cout << "Name: " << company->getCompanyName() << std::endl;
	    std::cout << "Address: " << company->getCompanyAddress() << std::endl;
	    std::cout << "Description: " << company->getCompanyDescription() << std::endl;
	    std::cout << "Jobs:" << std::endl;
	    printJobs(companyName);
	    std::cout << "Requests: " << std::endl;
	    printRequests(companyName);
	}
    return;
}

void UserAndCompany::endorse(std::string endorserUserId, std::string skilledUserId, std::string skillName)
{
	User* endorsee = searchUser(skilledUserId);
	User* endorser = searchUser(endorserUserId);
	if(endorser != NULL && endorsee != NULL)
	{
		Skill* skill = endorsee->searchSkill(skillName);
		if(skill != NULL)
		{
			skill->addEndorser(endorser);	
		}
	}
	return;
}

void UserAndCompany::addFollower(std::string followerId, std::string followingId)
{
	User* follower = searchUser(followerId);
	User* following = searchUser(followingId);
	if(follower != NULL && following != NULL)
	{
		follower->addFollowing(following);
		following->addFollower(follower);
		following->addFollowing(follower);
	}
	return;
}

void UserAndCompany::addJobRequest(std::string companyName, std::string title, std::map<std::string, float> conditions)
{
	Company* company = searchCompany(companyName);
	if(company != NULL)
	{
		Job* job = new Job(companyName, title, conditions);
		company->setJobs(job);
	}
	return;
}

void UserAndCompany::addApplicants(std::string userId, std::string companyId, std::string jobTitle)
{
	User* applicant = searchUser(userId);
	Company* company = searchCompany(companyId);
	if(company != NULL && applicant != NULL)
	{
		Job* job = company->searchJob(jobTitle);
		if(job != NULL && company->isQualified(applicant, job) == true)
		{
			job->addJobRequest(applicant);
		}
	}
	return;
}

void UserAndCompany::hire(std::string companyId, std::string jobTitle, std::string startsAt)
{
	Company* company = searchCompany(companyId);
	if(company != NULL)
	{
		Job* job = company->searchJob(jobTitle);
		if(job != NULL)
		{
			User* bestApplicant = company->findTheBestApplicant(job);
			if(bestApplicant != NULL)
			{
				std::string userId = bestApplicant->getEmailAddress();
				addExperience(userId, companyId, jobTitle, startsAt, NOW);
				company->setEmployee(userId, jobTitle, startsAt, NOW);
			}
		}
	}
	return;
}

void UserAndCompany::printSuggestedJobs(std::string userId)
{
	int count = 1;
	User* user = searchUser(userId);
	Job* job;

	for(int i = 0; i < companies.size(); i++)
	{
		for(int j = 0; j < companies[i]->getJob().size(); j++)
		{
			job = companies[i]->getJob()[j];
			if(companies[i]->isQualified(user, job) == true)
			{
				std::cout << count << " " << job->getTitle() << " in " << job->getCompanyName() << " - needed skills: ";

				for (std::map<std::string, float>::iterator it = job->getConditions().begin(); it != job->getConditions().end(); ++it)
   					 {
   					 	std::cout << it->first << "(" << it->second << ") ";
   					 }
				std::cout << std::endl;
				count++;
			}
		}
	}
}

void UserAndCompany::printSuggestedUsers(std::string companyName, std::string jobTitle)
{
	Company* company = searchCompany(companyName);
	if(company != NULL)
	{
		Job* job = company->searchJob(jobTitle);
		for(int i = 0; i < users.size(); i++)
		{
			if(company->isQualified(users[i], job) == true)
			{
				printUser(users[i]->getEmailAddress());
			}
		}
	}
}

User* UserAndCompany::searchUser(std::string userId)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i]->getEmailAddress() == userId)
        {
            return users[i];
        }
    }
    return NULL;
}

Company* UserAndCompany::searchCompany(std::string companyName)
{
    for(int i = 0; i < companies.size(); i++)
    {
    	if(companies[i]->getCompanyName() == companyName)
        {
            return companies[i]; 
        }
    }
    return NULL;
}

bool UserAndCompany::checkUserExistence(std::string userId)
{
	if(searchUser(userId) != NULL)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool UserAndCompany::checkCompanyExistence(std::string companyId)
{
    if(searchCompany(companyId) != NULL)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool UserAndCompany::checkJobExistence(std::string title, std::string companyId)
{
	Company* company = searchCompany(companyId);
	if(company != NULL)
	{
		Job* job = company->searchJob(title);
		if(job != NULL)
		{
			return true;
		}
	}
	return false;
}

void UserAndCompany::printExperiences(std::string userId)
{
	User* user = searchUser(userId);
	if(user != NULL)
	{
		std::vector<Experience*> experiences;
		experiences = user->getExperiences();

		for(int i = 0; i < experiences.size(); i++)
		{
			experiences[i]->setDisplacedStartAt(user->split(experiences[i]->getStartAt()));
		}

		std::sort(experiences.begin(), experiences.end(), sortobj);

		for(int i = 0; i < experiences.size(); i++)
		{
			if(experiences[i]->getEndAt() == NOW)
			{
				experiences[i]->getEndAt() = "NOW";
			}
			std::cout << i+1 << ". " << experiences[i]->getStartAt() << " - " << experiences[i]->getEndAt() << " ";
			std::cout << experiences[i]->getTitle() << " at " << experiences[i]->getCompanyName() << std::endl;
		}
	}
	return;
}

void UserAndCompany::printSkills(std::string userId)
{	
	User* user = searchUser(userId);
	if(user != NULL)
	{
		std::vector<Skill*> skills = user->getSkills();
		for(int i = 0; i < skills.size(); i++)
		{
			std::cout << i+1 << ". " << skills[i]->getSkillName() << " - " << skills[i]->getSkillRate() << std::endl;
		}
	}
	return;
}

void UserAndCompany::printJobs(std::string companyName)
{
	Company* company = searchCompany(companyName);
	if(company != NULL)
	{
		std::vector<Experience*> employment = company->getEmployment();
		for(int i = 0; i < employment.size(); i++)
		{
			employment[i]->setDisplacedStartAt(users[i]->split(employment[i]->getStartAt()));
		}

		std::sort(employment.begin(), employment.end(), sortobj);

		for(int i = 0; i < employment.size(); i++)
		{
			User* user = searchUser(employment[i]->getCompanyName());
			if(user != NULL)
			{
				std::cout << i+1 << ". " << employment[i]->getStartAt() << " - ";
				if(employment[i]->getEndAt() == NOW)
				{
					std::cout << "NOW ";
				}
				else
				{
					std::cout << employment[i]->getEndAt() << " ";
				}
				std::cout << employment[i]->getTitle() << " by " << user->getFirstName() << " " << user->getLastName() << std::endl;
			}
		}
	}
	return;
}

void UserAndCompany::printRequests(std::string companyId)
{
	int count = 1;
	Company* company = searchCompany(companyId);
	Job* job;

	for(int j = 0; j < company->getJob().size(); j++)
	{
		job = company->getJob()[j];

		std::cout << count << " " << job->getTitle() << " in " << job->getCompanyName() << " ";

		for (std::map<std::string, float>::iterator it = job->getConditions().begin(); it != job->getConditions().end(); ++it)
   			{
   					std::cout << it->first << "(" << it->second << ") ";
   			}
		std::cout << std::endl;
		count++;
	}
	
}
