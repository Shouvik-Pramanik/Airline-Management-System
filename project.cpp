#include<iostream>
#include<list>
using namespace std;
class passenger
{
    public:
    string name, address, nationality;
    int age, passno,flno;
    void bookflight();
    void cancel(int no);
    void delete_pass();
    passenger(string n, string add, string nat, int a, int p,int fno)
    {
        address = add;
        nationality = nat;
        passno = p;
        name = n;
        age = a;
        flno=fno;
    }
    passenger()
    {}
};
list<passenger> pass;
class flight
{
    public:
    string from,to;
    float cost;
    int fno,seats,seatsb;
    void addflight();
    void delflight();
    flight(int f,string fr,string t,float c,int s,int sb)
    {
        fno=f;
        from=fr;
        to=t;
        cost=c;
        seats=s;
        seatsb=sb;
    }
    flight(){}
};
list<flight> fl;
void flight::addflight()
{
    int fn,s,sb;
    string f,t;
    float c;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter the flight number "<<endl;
        cin>>fn;
        cout<<"Enter the departure location"<<endl;
        cin>>f;
        cout<<"Enter the arrival location"<<endl;
        cin>>t;
        cout<<"Enter cost of flight"<<endl;
        cin>>c;
        cout<<"Enter the number of seats in the plane"<<endl;
        cin>>s;
        cout<<"Enter the number of seats booked"<<endl;
        cin>>sb;
        if(sb>s)
        {
            cout<<"Number of booked seats cannot be greater than number of seats"<<endl;
            break;
        }
        fl.push_front(flight(fn,f,t,c,s,sb));
        cout<<"Flight added successfully! Do you want to add more flights? (y/n)"<<endl;
        cin>>ch;
    }
}
void flight::delflight()
{
    if(fl.empty())
    {
        cout<<"No flights to delete";
        return;
    }
    int fn;
    cout<<"Enter flight number of entry you want to delete"<<endl;
    cin>>fn;
    for(std::list<flight>::iterator i=fl.begin();i!=fl.end();i++)
    {
        if(i->fno==fn)
        {
            fl.erase(i);
            break;
        }
    }
}
void printp()
{
    if(pass.empty())
    {
        cout<<"No passenger details entered";
        return;
    }
    for(std::list<passenger>::iterator i=pass.begin();i!=pass.end();i++)
    {
        cout << "Name of Passenger : " << i->name << "\n";
        cout << "Age of Passenger : " << i->age << "\n";
        cout << "Pass Number is : " <<i->passno << "\n";
        cout<<"Flight number is : "<<i->flno<<" \n";
        cout << "Country : " << i->nationality << "\n";
        cout << "Address : " << i->address << "\n";
    }
}
void printfl()
{
    if(fl.empty())
    {
        cout<<"No flight details entered";
        return;
    }
    for(std::list<flight>::iterator i=fl.begin();i!=fl.end();i++)
    {
        cout<<"Flight number is: "<<i->fno<<endl;
        cout<<"Departure locations is: "<<i->from<<endl;
        cout<<"Arrival location is: "<<i->to<<endl;
        cout<<"Cost of flight is: "<<i->cost<<endl;
        cout<<"Number of seats are: "<<i->seats<<endl;
        cout<<"Number of seats booked are: "<<i->seatsb<<endl;
    }
}
bool checkpno(int pno)
{
    for(std::list<passenger>::iterator i=pass.begin();i!=pass.end();i++)
    {
        if(i->passno==pno)
        return true;
    }
    return false;
}
bool checkflno(int flno)
{
    for(std::list<flight>::iterator i=fl.begin();i!=fl.end();i++)
    {
        if(i->fno==flno)
        return true;
    }
    return false;
}
void passenger::delete_pass()
{
    if(pass.empty())
    {
        cout<<"No passengers to delete";
        return;
    }
    int passn;
    cout<<"Enter passport number of entry you want to delete"<<endl;
    cin>>passn;
    for(std::list<passenger>::iterator i=pass.begin();i!=pass.end();i++)
    {
        if(!checkpno(passn))
        cout<<"Entered passport number doesn't exist";
        if(i->passno==passn)
        {
            pass.erase(i);
            break;
        }
    }
}
void booked(int flno)
{
    for(std::list<flight>::iterator i=fl.begin();i!=fl.end();i++)
    {
        if(i->fno==flno)
        (i->seatsb)++;
    }
}
bool checkbooked(int flno)
{
    for(std::list<flight>::iterator i=fl.begin();i!=fl.end();i++)
    {
        if(i->fno==flno)
        {
            if(i->seats==i->seatsb)
            return true;
        }
    }
    return false;
}
void passenger::bookflight()
{
    string n, add, nat;
    char ch='y';
    int ag, p,flno;
    while(ch=='y'||ch=='Y')
    {
        if(fl.empty())
        {
            cout<<"No flights available at the moment";
            break;
        }
        cout << "Enter Name : "<<endl;
        cin >> n;
        cout << "Enter Age : "<<endl;
        cin >> ag;
        cout << "Enter Nationality : "<<endl;
        cin >> nat;
        cout << "Enter Address : "<<endl;
        cin >> add;
        cout << "Enter Passport number : "<<endl;
        cin >> p;
        if(checkpno(p))
        {
            cout<<"Sorry, entry already exists, please enter details again"<<endl;
            break;
        }
        cout<<"Enter flight number"<<endl;
        cin>>flno;
        if(!checkflno(flno))
        {
            cout<<"Sorry, entered flight doesn't exist, please enter details again"<<endl;
            break;
        }
        if(checkbooked(flno))
        {
            cout<<"Sorry, no seats are available on this flight"<<endl;
            break;
        }
        pass.push_front(passenger(n, add, nat, ag, p,flno));
        booked(flno);
        cout<<"Your flight has been booked successfully! Do you want to book more flights? (y/n)"<<endl;
        cin>>ch;
    }
}
void menu()
{
    int ch;
    flight f;
    passenger p;
    cout<<"\n\n";
    cout<<"*****************"<<endl;
    cout<<"Enter you choice from the options below:\n";
    cout<<"Enter 1 to add new flights \n";
	cout<<"Enter 2 to delete flights \n";
    cout<<"Enter 3 to book flight for a passenger\n";
    cout<<"Enter 4 to delete passenger details\n";
    cout<<"Enter 5 to display all flight details\n";
    cout<<"Enter 6 to display all passenger details\n";
    cout<<"Enter 7 to exit\n\n";
    cout<<"*****************"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: f.addflight();
                break;
        case 2: f.delflight();
                break;
        case 3: p.bookflight();
                break;
        case 4: p.delete_pass();
                break;
        case 5: printfl();
                break;
        case 6: printp();
                break;
        case 7: cout<<"Thank you for using our service!";
                exit(1);
        default: cout<<"Invalid choice";
    }
}

int main()
{
    while(1)
    menu();
    return 0;
}