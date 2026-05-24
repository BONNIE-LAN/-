#include<iostream>
using namespace std;
class People
{
    public:
    int age;
    float hight;
    float weight;
    People(int isAge,float isHight,float isWeight);
    void eatting()
    {
        weight++;
    }
    void sporting()
    {
        hight++;
    }
    void sleeping()
    {
        age++;
        hight++;
        weight++;
    }
};
People::People(int isAge,float isHight,float isWeight)
{
    age=isAge;
    hight=isHight;
    weight=isWeight;
}
int main()
{
    
    People person(18,180.0,70.0);
    cout<<person.age<<" "<<person.hight<<" "<<person.weight<<endl;
    person.eatting();
    person.sleeping();
    person.sporting();
    cout<<person.age<<" "<<person.hight<<" "<<person.weight<<endl;
}