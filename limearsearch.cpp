#include<iostream>
using namespace std;

int limearsearch(int list[],int key)
{
int index=0;
int found=0;
do{
if(list[index]==key)
found=1;
else
index++;
}
while(found==0&&index<6);
if(found==0)
index=-1;
return index;

}
int main()
{
int list[]={1,3,4,5,6,7};
int key=6;
int result= limearsearch(list,key);
if(result==-1)
cout << "not found " << endl;
else
cout << "found in the list of index="<<result<< endl;

return 0;
}