#include<iostream>                                                                    //cin cout  
#include<string>																	  //class string
#include<fstream>																	  //class i/o fstream
#include <cstdlib>
//fuck you ass hole
using namespace std;

typedef struct student{																  //student information
    string name;
    int score[3];
    int total;
    double average;
}Stu;
void print_head(){																	  //print title
    cout<<"no\t"<<"name\t"<<"score1\t"<<"score2\t"<<"score3\t"<<"average"<<endl;
}
int main(){
    Stu s[10];																	      //initialization
    for(int i=0;i<10;i++){
        s[i].total=0;                                           					 
    }
    int sum[3]={0};
    double avg[3];
    int min[3]={100,100,100};
    int max[3]={0};
    ifstream infile;																//open file name.txt
    infile.open("name.txt");
    if(!infile){
        cout<<"error"<<endl;
    }
    for(int i=0;i<10;i++){
        infile>>s[i].name;															//read content to s.name
    }
    infile.close();																	//close file
    infile.open("score1.txt");														//open file score1
    if(!infile){
        cout<<"error"<<endl;
        exit(1);
    }
    for(int i=0;i<10;i++){
        infile>>s[i].score[0];														//read to score[0]
        s[i].total+=s[i].score[0];													//meanwhile update total sum max min 
        sum[0]+=s[i].score[0];
        if(min[0]>s[i].score[0])min[0]=s[i].score[0];
        if(max[0]<s[i].score[0])max[0]=s[i].score[0];

    }
    infile.close();																	
    infile.open("score2.txt");														//read to score[1] ,the same
    if(!infile){
        cout<<"error"<<endl;
        exit(1);
    }
    for(int i=0;i<10;i++){
        infile>>s[i].score[1];
        s[i].total+=s[i].score[1];
        sum[1]+=s[i].score[1];
        if(min[1]>s[i].score[1])min[1]=s[i].score[1];
        if(max[1]<s[i].score[1])max[1]=s[i].score[1];
    }
    infile.close();
    infile.open("score3.txt");														//read to score[2],also the same
        if(!infile){
        cout<<"error"<<endl;
        exit(1);
    }
     for(int i=0;i<10;i++){
        infile>>s[i].score[2];
        s[i].total+=s[i].score[2];
        sum[2]+=s[i].score[2];
        if(min[2]>s[i].score[2])min[2]=s[i].score[2];
        if(max[2]<s[i].score[2])max[2]=s[i].score[2];
    }
    infile.close();
    for(int i=0;i<10;i++)s[i].average=s[i].total/3.0;								//calculate average
    for(int i=0;i<3;i++)avg[i]=sum[i]/10.0;
    print_head();																    //print
    for(int i=0;i<10;i++){
        cout<<i+1<<"\t"<<s[i].name<<"\t"<<s[i].score[0];
        cout<<"\t"<<s[i].score[1]<<"\t"<<s[i].score[2];
        cout<<"\t"<<s[i].average<<"\t"<<endl;
    }
    cout<<"\t"<<"average\t";
    for(int i=0;i<3;i++)
        cout<<avg[i]<<"\t";
    cout<<endl;
    cout<<"\t"<<"min\t";
    for(int i=0;i<3;i++)
        cout<<min[i]<<"\t";
    cout<<endl;
    cout<<"\t"<<"max\t";
    for(int i=0;i<3;i++)
        cout<<max[i]<<"\t";
    cout<<endl;
    return 0;
}
