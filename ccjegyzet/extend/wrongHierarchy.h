#ifndef _WRONG_HIERARCHY_H_
#define _WRONG_HIERARCHY_H_

#include <string>

class Member
{
	std::string name;
public:
	inline Member(const std::string &name): name(name)
	{
	}
	
	virtual void setName(const std::string &newName);
	
	virtual std::string getName() const;
};

class TeamLeader: public Member
{
	int numTeamMembers;
public:
	inline TeamLeader(const std::string &name, int numTeamMembers):
		Member(name),
		numTeamMembers(numTeamMembers)
	{
	}
	
	inline void setNumTeamMembers(int newNum)
	{
		numTeamMembers = newNum;
	}
	
	inline int getNumTeamMembers() const
	{
		return numTeamMembers;
	}
};

class TeamMember: public Member
{
	TeamLeader *teamLeader;
public:
	inline TeamMember(const std::string &name):
		Member(name),
		teamLeader(0)
	{
	}
	
	inline TeamLeader* getTeamLeader() const
	{
		return teamLeader;
	}
	
	inline void setTeamLeader(TeamLeader *newTeamLeader)
	{
		teamLeader = newTeamLeader;
	}
};

class MiddleTeamLeader: public TeamLeader, public TeamMember
{
public:
	inline MiddleTeamLeader(const std::string &name, int numTeamMembers):
		TeamMember(name),
		TeamLeader(name, numTeamMembers)
	{
	}
};

#endif
