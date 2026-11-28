# include <iostream>
# include <string>
# include <vector>
# include <fstream>
using namespace std;
class energyRecord{
    protected:
    int recordID;
    int installationID;
    string date;
    public:
        void displayRecordDetails(){
            cout<<"Record ID: "<<recordID<<endl;
            cout<<"Installation ID: "<<installationID<<endl;
            cout<<"Date: "<<date<<endl;
        }
};
class solarInstallation{
    int installationID;
    string customerName;
    string location;
    double systemCapacity;
    int panelCount;
    string inverter;
    string commissioningDate;
    public :
        void addInstallation(){
            cout<<"=== ADD INSTALLATION ==="<<endl;
            cout<<"Enter Installation ID: ";
            cin>>installationID;
            cout<<"Enter Customer Name: ";
            cin.ignore();
            getline(cin, customerName);
            cout<<"Enter Location: ";
            getline(cin, location);
            cout<<"Enter System Capacity (kW): ";
            cin>>systemCapacity;
            cout<<"Enter Number of Panels: ";
            cin>>panelCount;
            cout<<"Enter Commissioning Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, commissioningDate);
            cout<<"Enter Inverter Type: ";
            getline(cin, inverter);
        }
        void updateInstallation(){
            cout<<"=== UPDATE INSTALLATION ==="<<endl;
            cout<<"Enter new Customer Name: ";
            cin.ignore();
            getline(cin, customerName);
            cout<<"Enter new Location: ";
            getline(cin, location);
            cout<<"Enter new System Capacity (kW): ";
            cin>>systemCapacity;
            cout<<"Enter new Number of Panels: ";
            cin>>panelCount;
            cout<<"Enter new Commissioning Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, commissioningDate);
        }
        void displayInstallation(){
            cout<<"=== INSTALLATION DETAILS ==="<<endl;
            cout<<"Installation ID: "<<installationID<<endl;
            cout<<"Customer Name: "<<customerName<<endl;
            cout<<"Location: "<<location<<endl;
            cout<<"System Capacity: "<<systemCapacity<<" kW"<<endl;
            cout<<"Number of Panels: "<<panelCount<<endl;
            cout<<"Commissioning Date: "<<commissioningDate<<endl;
            cout<<"Inverter : "<<inverter<<endl;
            
        }
        
};

class battery : public energyRecord{
   int batteryID;
   double capacity;
   double currentCharge;
   string status;
    public:
        void addBattery(){
            cout<<"=== ADD BATTERY ==="<<endl;
            cout<<"Enter record ID: ";
            cin>>recordID;
            cout<<"Enter Installation ID: ";
            cin>>installationID;
            cout<<"Enter Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, date);
            cout<<"Enter Battery ID: ";
            cin>>batteryID;
            cout<<"Enter Capacity (kWh): ";
            cin>>capacity;
            cout<<"Enter Current Charge (kWh): ";
            cin>>currentCharge;
            cout<<"Enter Status (Charging/Discharging/Idle): ";
            cin.ignore();
            getline(cin, status);
            cout<<"Battery record added successfully!"<<endl;
        }
};
class generation : public energyRecord {
    double unitsGenerated;
    double peakPower;
    public:
        void addGenerationRecord(){
            cout<<"=== ADD GENERATION RECORD ==="<<endl;
            cout<<"Enter record ID: ";
            cin>>recordID;
            cout<<"Enter Installation ID: ";
            cin>>installationID;
            cout<<"Enter Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, date);
            cout<<"Enter Units Generated (kWh): ";
            cin>>unitsGenerated;
            cout<<"Enter Peak Power (kW): ";
            cin>>peakPower;
            cout<<"Generation record added successfully!"<<endl;
        }
};
class consumption : public energyRecord{
    string loadName;
    double unitsConsumed;
    public:
        void addConsumptionRecord(){
            cout<<"=== ADD CONSUMPTION RECORD ==="<<endl;
            cout<<"Enter record ID: ";
            cin>>recordID;
            cout<<"Enter Installation ID: ";
            cin>>installationID;
            cout<<"Enter Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, date);
            cout<<"Enter Load Name: ";
            getline(cin, loadName);
            cout<<"Enter Units Consumed (kWh): ";
            cin>>unitsConsumed;
        }
};
class gridExchange : public energyRecord{
    double importedUnits;
    double exportedUnits;
    double importTariff;
    double exportTariff;
    public:
        void addGridExchangeRecord(){
            cout<<"=== ADD GRID EXCHANGE RECORD ==="<<endl;
            cout<<"Enter record ID: ";
            cin>>recordID;
            cout<<"Enter Installation ID: ";
            cin>>installationID;
            cout<<"Enter Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, date);
            cout<<"Enter Imported Units (kWh): ";
            cin>>importedUnits;
            cout<<"Enter Exported Units (kWh): ";
            cin>>exportedUnits;
            cout<<"Enter Import Tariff ($/kWh): ";
            cin>>importTariff;
            cout<<"Enter Export Tariff ($/kWh): ";
            cin>>exportTariff;
            cout<<"Grid exchange record added successfully!"<<endl;
        }
};
class report{
    double totalGeneration;
    double totalConsumption;
    double totalImported;
    double totalExported;
};
/*class fileManagement{
    void saveInstallation(){
            ofstream file("Data/installation.txt", ios::app);
            file<<installationID<<","<<customerName<<","<<location<<","<<systemCapacity<<","<<panelCount<<","<<commissioningDate<<"\n";
            file.close();
        }
};*/
class solarManagement   {
    vector<solarInstallation> installations;
    vector<generation> generationRecords;
    vector<consumption> consumptionRecords;
    vector<battery> batteryRecords;
    vector<gridExchange> gridExchangeRecords;

    public:
        void addInstallation(){
            solarInstallation s;
            s.addInstallation();
            installations.push_back(s);
            cout<<"Installation added successfully!"<<endl;
        }
        void displayInstallations(){
            if(installations.empty()){
                cout<<"No installations found."<<endl;
                return;
            }
            for(int i=0;i<installations.size();i++){
                cout<<"Installation "<<i+1<<":"<<endl;
                installations[i].displayInstallation();
                cout<<"------------------------"<<endl;
            }
        }
        void addGenerationRecord(){
            generation g;
            g.addGenerationRecord();
            generationRecords.push_back(g);
            cout<<"Generation record added successfully!"<<endl;
        }
        void displayGenerationRecords(){
            if(generationRecords.empty()){
                cout<<"No generation records found."<<endl;
                return;
            }
            for(int i=0;i<generationRecords.size();i++){
                cout<<"Generation Record "<<i+1<<":"<<endl;
                generationRecords[i].displayRecordDetails();
                cout<<"------------------------"<<endl;
            }
        }

};

int main(){
    int option;
    solarManagement manager;
    
    do{
    cout<<"========================================\nSOLAR ENERGY MANAGEMENT SYSTEM\n========================================"<<endl;
    cout<<"1. Add Solar Installation"<<endl;   
    cout<<"2. Display Solar Installations"<<endl;
    cout<<"3. Add Generation Record"<<endl;
    cout<<"4. Display Generation Records"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>option;
    switch (option) {

    case 1: {
    solarInstallation installation;
    installation.addInstallation();
    break;
}

    case 2: {
        manager.displayInstallations();
        break;
    }

    case 3: {
        manager.addGenerationRecord();
        break;
    }

    case 4: {
        manager.displayGenerationRecords();
        break;
    }

    case 5: {
        cout << "Exiting the program..." << endl;
        break;
    }

    default:
        cout << "Invalid option. Please try again." << endl;
}
}while(option!=5);
return 0;
}

