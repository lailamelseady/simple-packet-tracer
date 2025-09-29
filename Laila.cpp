#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<string>Devices;
    string name_device;
    string another_device;
    vector<vector<int> > links(50, vector<int>(50) );

    int choice;
    string name_device1;
    string name_device2;
    int index_device1;
    int index_device2;
    string message;
    vector<vector<string> > Messages(50, vector<string>(50) );

    cout << "simple packet tracer" << endl;
    cout << "enter number of devices:" << endl;
    cin >> n;
    cout << "add your devices:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> name_device;
        Devices.push_back(name_device);
    }


    for (int i = 0; i < Devices.size(); i++) {
        for (int j = i + 1; j < Devices.size(); j++) {
            if (Devices[i] == Devices[j]) {
                cout << Devices[j] << "  already exist" << endl;
                cout << "enter another device" << endl;
                cin >> another_device;
                Devices[j] = another_device;
                j--;
            }
        }
    }

    for (int i = 0; i >= 0; i++) {
        cout << "choose what you want to do? " << endl;
        cout << "1- add link " << endl << "2- send message" << endl << "3- show network" << endl << "4- close the program" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "add link :" << endl;
            cout << "first device: ";
            cin >> name_device1;
            cout << "second device: ";
            cin >> name_device2;
            index_device1 = -1;
            index_device2 = -1;
            for (int i = 0; i < Devices.size(); i++) {
                if (Devices[i] == name_device1) {
                    index_device1 = i;
                }
                if (Devices[i] == name_device2) {
                    index_device2 = i;

                }
            }
            if (index_device1 < Devices.size() && index_device2 < Devices.size() && index_device1 != index_device2) {
                links[index_device1][index_device2] = 1;
                links[index_device2][index_device1] = 1;
                cout << "link has been added" << endl;

            }
            else {

                cout << "out of range or not exist" << endl;
            }

        }

        else if (choice == 2) {
            cout << "send message" << endl;
            cout << "source_device :";
            cin >> name_device1;
            cout << "destination_device :";
            cin >> name_device2;
            index_device1 = -1;
            index_device2 = -1;
            for (int i = 0; i < Devices.size(); i++) {
                if (Devices[i] == name_device1) {
                    index_device1 = i;

                }
                if (Devices[i] == name_device2) {
                    index_device2 = i;

                }
            }

            if (index_device1 < Devices.size() && index_device2 < Devices.size()) {
                if (links[index_device1][index_device2] == 1) {
                    cout << "message:";
                    cin.ignore();
                    getline(cin, message);
                    cout << "message is sent" << endl;
                    Messages[index_device1][index_device2] = message;

                }
                else if (links[index_device1][index_device2] == 0) {
                    cout << "no connection" << endl;
                }

            }
            if (index_device1 > Devices.size() || index_device2 > Devices.size()) {
                cout << "not exist" << endl;
            }

        }

        else if (choice == 3) {

            cout << "      the network  " << endl;
            for (int i = 0; i < links.size(); i++) {
                for (int j = i + 1; j < links.size(); j++) {
                    if (links[i][j] == 1) {
                        cout << "      " << Devices[i] << " <---> " << Devices[j] << endl;

                    }
                }
            }
            for (int i = 0; i < Messages.size(); i++) {
  for (int j=i+1;j<Messages.size(); j++) {
                    if (!Messages[i][j].empty()) {
                        cout << "      " << Devices[i] << " sent " << Messages[i][j] << " to "
                            << Devices[j] << endl;
                    }

                }

            }
        }


        else if (choice == 4) {
            break;
        }

    }   return 0;
}
