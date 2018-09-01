#include<iostream>
#include<string>
#include <cstring>

using namespace std;

const int MAX_NAME=14; // Assume a name contains at most 14 characters
enum Gender {MALE,FEMALE};

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    int ID;
    char first_name[MAX_NAME+1];
    char last_name[MAX_NAME+1];
    Date birth_date;
    Gender gender;
    double GPA;
};


void InputStudent(Student* s)
{
    cout<<"Enter id :";
    cin>> s->ID;
    cout<<"Enter first name :";
    cin>> s->first_name;
    cout<<"Enter last name :";
    cin>> s->last_name;
    cout<<"Enter the day :";
    cin>> s->birth_date.day;
    cout<<endl<<"Enter the month :";
    cin>> s->birth_date.month;
    cout<<endl<<"Enter the year :";
    cin>> s->birth_date.year;
    cout<<endl<<"Enter gender :";
    string genderFlag;
    cin >> genderFlag;
    if (genderFlag == "m")
        s->gender = MALE;
    else if (genderFlag == "f")
        s->gender = FEMALE;
    //cin>> s->gender;
    cout<<endl<<"Enter gpa :";
    cin>> s->GPA;

}
void OutputStudent(Student* s)
{
    cout<< s->ID<<"  ";
    cout<< s->first_name<<"  ";
    cout<< s->last_name<<"  ";
    cout<< s->birth_date.day<<"  ";
    cout<< s->birth_date.month<<"  ";
    cout<< s->birth_date.year<<"  ";
    if ( s->gender == MALE)
    {
        cout<<"male"<<"  ";
    }
    if ( s->gender == FEMALE)
    {
        cout<<"female"<<"  ";
    }
    cout<< s->GPA<<"  ";

}

void InputAllStudent(Student* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        InputStudent(&s[i]);
    }
}

void OutputAllStudent(Student* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        OutputStudent(&s[i]);
        cout << endl;
    }
}
bool BirthLess(Student* a, Student* b)
{
    if (a->birth_date.year < b->birth_date.year)
    {
        return true;
    }
    else if (a->birth_date.year > b->birth_date.year)
    {
        return false;
    }
    else if (a->birth_date.year == b->birth_date.year)
    {
        if (a->birth_date.month < b->birth_date.month)
        {
            return true;
        }
        else if (a->birth_date.month > b->birth_date.month)
        {
            return false;
        }
        else if (a->birth_date.month == b->birth_date.month)
        {
            if(a->birth_date.day <= b->birth_date.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

}

bool GPAGreater(Student* a, Student* b)
{
    if (a->GPA >= b->GPA)
    {
        return true ;
    }
    else if (a->GPA < b->GPA)
    {
        return false ;
    }

}

Student* SearchStudentID(Student* s, int n, int ID)
{
    for(int i=0; i < n; i++)
    {
        if(s[i].ID == ID)
        {
            return &s[i] ;
        }
    }
    return 0;
}

Student* SearchStudentFirstName(Student* s, int n, char* name)
{
    for(int i=0 ; i<n ; i++)
    {
        if(strcmp(s[i].first_name, name) == 0)
        {
            return &s[i] ;
        }
    }

    return 0;

}

void SortStudentsByIncreasingBirthDay(Student* s, int n)
{
    for(int j=0; j<n; j++)
    {
        int ind=j;
        for(int i=j+1; i<n; i++)
            if(BirthLess(&s[i], &s[ind]))
                ind=i;
        Student t=s[ind];
        s[ind]=s[j];
        s[j]=t;
    }
}

void SortStudentsByDecreasingGPA(Student* s, int n)
{
    for(int j=0; j<n; j++)
    {
        int ind=j;
        for(int i=j+1; i<n; i++)
            if(GPAGreater(&s[i], &s[ind]))
                ind=i;
        Student t=s[ind];
        s[ind]=s[j];
        s[j]=t;
    }
}

int main ()
{
    int n,y,id ;
    char* name;
    cout<<"enter the number of student ";
    cin>>n;
    Student* s= new Student[n];
    InputAllStudent(s, n);

    while (true)
    {
        cout<<"1-Output all students data."<<endl;
        cout<<"2-Sort students by increasing birth date."<<endl;
        cout<<"3-Sort students by decreasing GPA."<<endl;
        cout<<"4-Search students by ID."<<endl;
        cout<<"5-Search students by first name."<<endl;
        cout<<"6-Exit the program."<<endl;
        cin>>y;

        if (y == 1)
        {
            OutputAllStudent(s, n);
            continue;
        }
        else if (y == 2)
        {
            SortStudentsByIncreasingBirthDay(s, n);
            cout<< "sorting by birth day "<<endl;
            OutputAllStudent(s, n);
            continue;
        }
        else if (y == 3)
        {
            SortStudentsByDecreasingGPA(s, n);
            cout<< "sorting by GPA day "<<endl;
            OutputAllStudent(s, n);
            continue;
        }
        else if (y == 4)
        {
            cin>>id;
            if (SearchStudentID(s,n,id) != 0)
            {
                OutputStudent(SearchStudentID(s,n,id));
                continue;
            }
            else
            {
                cout<< "this id not here :";
                continue;
            }
        }
        else if (y == 5 )
        {

            cin>>name;
            if (SearchStudentFirstName(s,n,name) != 0)
            {
                OutputStudent(SearchStudentFirstName(s,n,name));
                continue;
            }
            else
            {
                cout<< "this name not here :";
                continue;
            }
        }
        else if (y== 6 )
        {
            break;
        }





    }

    return 0 ;

}
