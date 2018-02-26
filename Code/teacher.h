#ifndef TEACHER_H
#define TEACHER_H

#include<fstream>
#include"student.h"
#include<iostream>

using namespace std;
class teacher
{
  char name[20];
  char subject[20];
  int subcode;
  int teacherid;
public:
  void input()
  {
    cout<<"\nEnter the name of teacher: ";
    cin>>name;
    cout<<"Enter teacher id number: ";
    cin>>teacherid;
    cout<<"\nEnter subject name: ";
    cin>>subject;
    cout<<"\nEnter subject code: ";
    cin>>subcode;
    subcode = subcode-1;
  }

  int idcompare(int id)
  {
    if(teacherid == id)
      return 1;

      else
        return 0;
  }

  void display()
  {
    cout<<"\nName of teacher: ";
    puts(name);
    cout<<"Teacher id number: "<<teacherid;
    cout<<"\nSubject name: ";
    puts(subject);
    cout<<"Subject code: "<<subcode;
  }

  void updateMarks()
  {
    fstream fio("student.dat", ios::in|ios::out|ios::binary);
    fstream fio2("student2.dat", ios::out);
    int count = 0, marks;
    student S;
    long pos;

    cout<<"\n\nUpload marks of all students for the subject "<<subject;

    pos = fio.tellg();

fio.read((char*)&S,sizeof(S));
cout<<"Roll number: "<<S.rollno<<endl;
    /*while(fio.read((char*)&S,sizeof(S)))
    {
      cout<<"\nEnter marks of student roll number "<<S.getroll()<<" : ";
      cin>>marks;
      S.entermarks(subcode, marks);
      //fio.seekp(pos);
      fio2.write((char*)&S,sizeof(S));
      count++;
      //pos = fio.tellg();
    }
    
	remove("student.dat");
	rename("student2.dat", "student.dat");
    */
	if(count == 0)
      cout<<"\n\nNo students enrolled";

    else
      cout<<"\nAll student marks have been uploaded successfully";

      fio.close();
      fio2.close();
  }
};

#endif
