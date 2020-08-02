#include <bits/stdc++.h>

using namespace std;

class SocialWebsite{
private:
protected:
public:
    virtual void secret() {} ;
};

class Facebook: public SocialWebsite{
private:
    string fbPassword;

    void secret(){
        cout << "The Facebook password is: " << fbPassword << endl;
        cout << "Its risky, but its fine to print here as it's a private function\n";
    }
public:
    Facebook(string pwd) {
        fbPassword = pwd;
    }
};

int main()
{
    Facebook f("Rachit95@fb");

    SocialWebsite *ptr = &f;
    ptr->secret();
}