a.out: main.o interface.o UserAndCompany.o User.o Company.o Skill.o Experience.o Job.o
	g++ main.o interface.o UserAndCompany.o User.o Company.o Skill.o Experience.o Job.o

main.o: main.cpp
	g++ -c main.cpp

interface.o: interface.cpp
	g++ -c interface.cpp

UserAndCompany.o: UserAndCompany.cpp
	g++ -c UserAndCompany.cpp

User.o: User.cpp
	g++ -c User.cpp

Company.o: Company.cpp
	g++ -c Company.cpp

Skill.o: Skill.cpp
	g++ -c Skill.cpp

Experience.o: Experience.cpp
	g++ -c Experience.cpp

Job.o: Job.cpp
	g++ -c Job.cpp

clean:
	rm *.o a.out