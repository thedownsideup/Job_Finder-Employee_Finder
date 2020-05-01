#include "User.hpp"
#include <sstream>

#define NOW "INDIFINITE_DATE"

User::User(std::string firstname, std::string lastname, std::string emailaddress, std::string bio)
{
    firstName = firstname;
    lastName = lastname;
    emailAddress = emailaddress;
    biography = bio;
}

void User::setExperiences(Experience* experience)
{
    experiences.push_back(experience);
    return;
}

void User::setSkills(Skill* skill)
{
    skills.push_back(skill);
    return;
}

void User::addFollower(User* follower)
{
    followers.push_back(follower);
    return;
}

void User::addFollowing(User* following)
{
	followings.push_back(following);
    return;
}

std::string User::getFirstName()
{
    return firstName;
}

std::string User::getLastName()
{
    return lastName;
}

std::string User::getEmailAddress()
{
    return emailAddress;
}

std::string User::getBiography()
{
    return biography;
}

std::vector<Experience*> User::getExperiences()
{
    return experiences;
}

std::vector<Skill*> User::getSkills()
{
    return skills;
}

std::vector<User*> User::getFollowers()
{
    return followers;
}

int User::getFollowersCount()
{
    return followers.size();
}

std::vector<User*> User::getFollowings()
{
    return followings;
}

int User::getFollowingsCount()
{
  	return followings.size();
}

Skill* User::searchSkill(std::string skillName)
{
	for(int i = 0; i < skills.size(); i++)
	{
		if(skills[i]->getSkillName() == skillName)
		{
			return skills[i];
		}
	}
    return NULL;
}

float User::calculateTotalSkillRate()
{
	for(int i = 0; i < skills.size(); i++)
	{
		totalSkillRate += skills[i]->getSkillRate();
	}

	return totalSkillRate;
}

float User::getTotalSkillRate()
{
    calculateTotalSkillRate();
	return totalSkillRate;
}

std::string User::split(std::string splitWannaBe)
{
    std::vector<std::string> splitted;
    std::stringstream splitStream(splitWannaBe);
    std::string token;
    while(std::getline(splitStream, token, SLASH))
    {
        splitted.push_back(token);
    }

    std::string splittedString;
    splittedString = convertVectorToString(displace(splitted));
    return splittedString;
}

int User::convertStringtoNumber(std::string numberWannaBe)
{
    int result = 0;
    for(int i = 0;i<numberWannaBe.size();i++)
    {
        result += ((int)numberWannaBe[i])-'0';
        result *= 10;
    }
    result /= 10;
    return result;
}

bool User::isSingleDigit(int number)
{
    if(number < 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string User::convertVectorToString(std::vector<std::string> stringWannabe)
{
    std::string newString;
    for(int i = 0; i < stringWannabe.size(); i++)
    {
        newString.append(stringWannabe[i]);
    }
    return newString;
}

std::vector<std::string> User::displace(std::vector<std::string> displaceWannaBe)
{
    int number; 
    std::vector<std::string> displaced;
    displaced.push_back(displaceWannaBe[2]);

    if(displaceWannaBe[1].size() == 2)
    {
        number = convertStringtoNumber(displaceWannaBe[1]);

        if(isSingleDigit(number) == true)
        {
            displaceWannaBe[1].insert(displaceWannaBe[1].begin(), '0');
        }
    }

    displaced.push_back(displaceWannaBe[1]);

     if(displaceWannaBe[0].size() == 2)
    {
        number = convertStringtoNumber(displaceWannaBe[0]);

        if(isSingleDigit(number) == true)
            displaceWannaBe[0].insert(displaceWannaBe[0].begin(), '0');
    }

     displaced.push_back(displaceWannaBe[0]);

     return displaced;
}
