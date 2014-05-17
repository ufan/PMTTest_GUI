#include "VISASystemManager.h"
#include "VISAInstrument.h"
#include <iostream>

using namespace std;
int main(int argc,char* argv[])
{
    VISASystemManager* visamanager=VISASystemManager::GetInstance();

    VISAInstrument instr("Serial_Test","ASRL3::INSTR");
    if(instr.Status() && visamanager->Status()){
        cout<< "Success" <<endl;
    }
    else{
        cout << "Fail" << endl;
    }
    cout<< "VISA Active Instruments:"<<endl;
    cout<<"Total Num: "<<visamanager->size()<<endl;
    if(visamanager->size()){
        int i=0;
        VISASystemManager::iterator it;
        for(it=visamanager->begin();it!=visamanager->end();++it){
            cout<< i+1 <<") "<< it->second->GetName()<<", "<< it->second->GetResourceString()<<", "<< it->second->GetRsrcDesc() <<endl;
        }
    }
    return 0;
}