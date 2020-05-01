#include "Skill.hpp"
#include "User.hpp"
#include <cmath>

Skill::Skill()
{
	skillEndorsersCount = 0;
}

void Skill::setSkillName(std::string skill)
{
    skillName = skill;
    return;
}

std::string Skill::getSkillName()
{
    return skillName;
}

void Skill::addEndorser(User* endorser)
{
	endorsers.push_back(endorser);
	return;
}

int Skill::getEndorsersCount()
{
	return endorsers.size();
}

void Skill::calculateSkillRate()
{
	int sum = 0;
	for(int i = 0; i < endorsers.size(); i++)
	{
		Skill* endorserSkill = endorsers[i]->searchSkill(skillName);
		if(endorserSkill == NULL)
		{
			sum += 1;
		}
		else
		{
			sum += sqrt(endorserSkill->getEndorsersCount() + 1);
		}
	}
	skillRate = sum;
	return;
}

double Skill::getSkillRate()
{
	calculateSkillRate();
	return skillRate;
}