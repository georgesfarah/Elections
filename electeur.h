#ifndef PASSWORDGEN_H
#define PASSWORDGEN_H

#include <string>
#include <vector>


class electeur
{
public:
    electeur();
    void saveConfigs();
    void getConfigs();
    void updateConfigs(int userN);
    void setVoted(std::string id);

    std::vector<std::string> getId();
    std::vector<std::string> getPass();
    std::vector<std::string> getCanVote();

private:

    std::vector<std::string>electeurId;
    std::vector<std::string>electeurPass;
    std::vector<std::string>electeurVoted;

};

#endif // PASSWORDGEN_H
