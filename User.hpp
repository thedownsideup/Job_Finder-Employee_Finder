#ifndef __User_H__
#define __User_H__

#include <string>
#include <vector>

#define NOW "INDIFINITE_DATE"

#include "Experience.hpp"
#include "Skill.hpp"

#define SLASH '/'

class User
{
	public:

        User(std::string firstname,std:: string lastname,std:: string emailaddress,std:: string bio);
        void setExperiences(Experience* experience);
        void setSkills(Skill* skill);
        void addFollower(User* follower);
		void addFollowing(User* following);
        std::string getFirstName();
        std::string getLastName();
        std::string getEmailAddress();
        std::string getBiography();
        std::vector<Experience*> getExperiences();
        std::vector<Skill*> getSkills();
        std::vector<User*> getFollowers();
        int getFollowersCount();
        std::vector<User*> getFollowings();
        int getFollowingsCount();
        Skill* searchSkill(std::string skillName);
        float calculateTotalSkillRate();
        float getTotalSkillRate(); 
        std::string split(std::string splitWannaBe);
		std::vector<std::string> displace(std::vector<std::string> displaceWannaBe);
        std::string convertVectorToString(std::vector<std::string> stringWannabe);
        bool isSingleDigit(int number);
        int convertStringtoNumber(std::string numberWannaBe);

    private:

        std::string firstName;
        std::string lastName;
        std::string emailAddress;
        std::string biography;
        std::vector<Experience*> experiences;
        std::vector<Skill*> skills;
        std::vector<User*> followers;
        int networks;
        std::vector<User*> followings;
        float totalSkillRate;
};

#endif
