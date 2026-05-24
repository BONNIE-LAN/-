#include<iostream>
using namespace std;
class People
{
    private:
    int age;
    float hight;
    float weight;
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
    public:
    
        void growth()
        {
            eatting();
            sporting();
            sleeping();
        }
        People(int isAge,float isHight,float isWeight)
        {
            age=isAge;
            hight=isHight;
            weight=isWeight;
        }
};
int main()
{
    People person(18,190.0,80.0);
    cout<<person.age<<" "<<person.hight<<" "<<person.weight<<endl;
    person.growth();
    cout<<person.age<<" "<<person.hight<<" "<<person.weight<<endl;

}