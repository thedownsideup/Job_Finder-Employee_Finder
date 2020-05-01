#ifndef __SKILL_H__
#define __SKILL_H__

#include <vector>
#include <string>

#define NOW "INDIFINITE_DATE"

class User;

class Skill
{
	public:

		Skill();
        void setSkillName(std::string skillName);
        std::string getSkillName();
        void addEndorser(User* endorser);
		void calculateSkillRate();
        double getSkillRate();
        int getEndorsersCount();

    private:
        int skillEndorsersCount;
        std::string skillName;
        float skillRate;
        std::vector<User*> endorsers;
};

#endif

