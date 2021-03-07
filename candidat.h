#ifndef VOTER_H
#define VOTER_H

#include <vector>
#include <string>

class candidat
{
public:
    candidat();
    void addVote(std::string id);
    void saveConfigs();
    void getConfigs();
    void updateConfigs(std::vector<std::string> candidatsName);
    std::vector<std::string> getId();
    std::vector<std::string> getName();
    std::vector<std::string> getVotes();

private:
    std::vector<std::string> candidatsId;
    std::vector<std::string> candidatsName;
    std::vector<std::string> candidatsVotes;

};

#endif // VOTER_H
