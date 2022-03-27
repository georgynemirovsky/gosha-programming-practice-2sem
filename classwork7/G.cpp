#include <iostream>
#include <string.h>

using namespace std;
struct atom
{
    char name[255] = "NO DATA";
    int A = 0;
    int Z = 0;
    bool operator==(atom a)
    {
        if ((a.Z == Z) and (a.A == A))
        {
            return true;
        } else
        {
            return false;
        }
    }
};
void comparison (atom &a, atom atoms[], int n)
{
    bool flag = false;
    for (int i = 0; i <= n; i++)
    {
        if (a == atoms[i])
        {
            a = atoms[i];
            flag = true;
        }
    }
    if (not(flag))
    {
        a = atoms[n];
    }
}
void beta_plus (atom &a, atom atoms[], int n)
{
    a.Z--;
    comparison (a, atoms, n);
}
void beta_minus (atom &a, atom atoms[], int n)
{
    a.Z++;
    comparison (a, atoms, n);
}
void alpha (atom &a, atom atoms[], int n)
{
    a.Z -= 2;
    a.A -= 4;
    comparison (a, atoms, n);
}
int main()
{
    int n = 0;
    cin >> n;
    atom *atoms = new atom[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> atoms[i].name >> atoms[i].A >> atoms[i].Z;
    }

    int r = 0;
    char atom_name[20], destruction[20];
    atom cheking_atom;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> atom_name >> destruction;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(atoms[j].name, atom_name) == 0)
            {
                cheking_atom = atoms[j];
                if (strcmp(destruction, "beta+") == 0)
                {
                    beta_plus(cheking_atom, atoms, n);
                    cout << cheking_atom.name << " ";
                    break;
                } else if (strcmp(destruction, "beta-") == 0)
                {
                    beta_minus(cheking_atom, atoms, n);
                    cout << cheking_atom.name << " ";
                    break;
                } else if (strcmp(destruction, "alpha") == 0)
                {
                    alpha(cheking_atom, atoms, n);
                    cout << cheking_atom.name << " ";
                    break;
                }
            }
        }
    }
    delete [] atoms;
    return 0;
}
