#include <iostream>
#include <string>
#include <vector>

#include "interface.hpp"

Interface::Interface()
{
    userAndCompany = new UserAndCompany;
}

void Interface::addUser(std::string firstName, std::string lastName, std::string emailAddress, std::string biography)
{
    userAndCompany->addUser(firstName, lastName, emailAddress, biography);
    return;
}

void Interface::addCompany(std::string name, std::string address, std::string description)
{
    userAndCompany->addCompany(name, address, description);
    return;
}

void Interface::addExperience(std::string userId, std::string companyId, std::string title, std::string startAt , std::string endsAt)
{
    userAndCompany->addExperience(userId, companyId, title, startAt, endsAt);
    return;
}

void Interface::addJobRequest(std::string companyName, std::string title, std::map<std::string, float> conditions)
{
    userAndCompany->addJobRequest(companyName, title, conditions);
    return;
}

void Interface::assignSkill(std::string userId, std::string skillName)
{
    userAndCompany->assignSkillToUser(userId, skillName);
    return;
}

void Interface::endorseSkill(std::string endorserUserId, std::string skilledUserId, std::string skillName)
{
    userAndCompany->endorse(endorserUserId, skilledUserId, skillName);
    return;
}

void Interface::follow(std::string followerId, std::string followingId)
{
    userAndCompany->addFollower(followerId, followingId);
    return;
}

void Interface::applyForJob(std::string userId, std::string companyId, std::string jobTitle)
{
    userAndCompany->addApplicants(userId, companyId, jobTitle);
    return;
}

void Interface::hireBestApplicant(std::string companyId, std::string jobTitle, std::string startsAt)
{
    userAndCompany->hire(companyId, jobTitle, startsAt);
    return;
}

void Interface::printUserProfile(std::string userId)
{
    userAndCompany->printUser(userId);
    return;
}

void Interface::printCompanyProfile(std::string companyName)
{
    userAndCompany->printCompany(companyName);
    return;
}

void Interface::printSuggestedJobs(std::string userId)
{
    userAndCompany->printSuggestedJobs(userId);
    return;
}

void Interface::printSuggestedUsers(std::string companyName, std::string jobTitle)
{   
    userAndCompany->printSuggestedUsers(companyName, jobTitle);
    return;
}

void Interface::printNetwork(std::string userId, int level)
{
    return;
}
