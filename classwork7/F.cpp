#include <iostream>

using namespace std;
enum Error
{
    Continue = 100,
    OK = 200,
    Created = 201,
    Accepted = 202,
    Bad_Request = 400,
    Unauthorized = 401,
    Not_Found = 404,
    Method_Not_Allowed = 405,
    Internal_Server_Error = 500,
    Not_Implemented = 501,
    Bad_Gateway = 502
};
void Errors_cout(Error error)
{
    switch (error)
    {
    case Error::Continue:
        cout << "Continue" << endl;
        break;

    case Error::OK:
        cout << "OK" << endl;
        break;
    case Error::Created:
        cout << "Created" << endl;
        break;
    case Error::Accepted:
        cout << "Accepted" << endl;
        break;
    case Error::Bad_Request:
        cout << "Bad Request" << endl;
        break;
    case Error::Unauthorized:
        cout << "Unauthorized" << endl;
        break;
    case Error::Not_Found:
        cout << "Not Found" << endl;
        break;
    case Error::Method_Not_Allowed:
        cout << "Method Not Allowed" << endl;
        break;
    case Error::Internal_Server_Error:
        cout << "Internal Server Error" << endl;
        break;
    case Error::Not_Implemented:
        cout << "Not Implemented" << endl;
        break;
    case Error::Bad_Gateway:
        cout << "Bad Gateway" << endl;
        break;
    }
}
int main()
{
    int type_er = 0;
    bool flag = true;
    while (flag)
    {
        cin >> type_er;
        if (type_er != 0)
        {
            Errors_cout(static_cast<Error>(type_er));
        } else
        {
            flag = false;
        }
    }
}
