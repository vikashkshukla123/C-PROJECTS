#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
struct Contact{
  std::string name;
  std::string phone;
  std::string email;

};
void addContact(std::vector<Contact>&contacts){
  Contact newContact;
  std::cout<<"ENTER NAME";
  std::cin>>newContact.name;
  std::cout<<"ENTER PHONE";
  std::cin>>newContact.phone;
  std::cout<<"ENTER EMAIL";
  std::cin>>newContact.email;

  contacts.push_back(newContact);
  std::cout<<"CONTACT IS ADDED"<<std::endl;
}
void displayContacts(const std::vector<Contact>&contacts){
  
  for(const auto &contact: contacts){
    std::cout<<"NAME:"<<contact.name<<",PHONE:"<<contact.phone<<",EMAIL:"<<contact.email<<std::endl;
  }
}
void searchContact(const std::vector<Contact>&contacts){
  std:: string searchTerm;
  std::cout<<"ENTER THE NAME TO SEARCH:"<<std::endl;
  std::cin>>searchTerm;

  bool found = false;
  for(const auto &contact : contacts){
    if(contact.name == searchTerm){
      std::cout<<"NAME:"<<contact.name<<",PHONE:"<<contact.phone<<",EMAIL:"<<contact.email<<std::endl;
    found = true;
    break;
    }
  }
  if(!found){
    std::cout<<"CONTACT NOT FOUND"<<std::endl;
  }

}
void deleteContact(std::vector<Contact>&contacts){
  std:: string nameToDelete;
  std::cout<<"ENTER THE NAME OF CONTACT TO DELETE:"<<std::endl;
  std::cin>>nameToDelete;
  auto it = std::remove_if(contacts.begin(),contacts.end(),[&](const Contact&contact){
    return contact.name == nameToDelete;});
    if(it!=contacts.end()){
      contacts.erase(it,contacts.end());
      std::cout<<"CONTACT DELETED:"<<std::endl;
    }
    else{
      std::cout<<"CONTACT IS NOT FOUND"<<std::endl;
    }

  }

int main(){
  std:: vector<Contact> contacts;
  int choice;
  do{
    std::cout<<"\n1.Add Contact"<<std::endl;
    std::cout<<"2.Display Contact"<<std::endl;
    std::cout<<"3.Search Contact"<<std::endl;
    std::cout<<"4.Delete Contact"<<std::endl;
    std::cout<<"5.EXIT"<<std::endl;
    std::cout<<"ENTER CHOICE"<<std::endl;
    std::cin>>choice;
    switch(choice){
      case 1:
      addContact(contacts);
      break;
    
      case 2:
      displayContacts(contacts);
      break;

      case 3:
      searchContact(contacts);
      break;

      case 4:
      deleteContact(contacts);
      break;

      case 5:
      break;

      default:
      std::cout<<"INVALID CHOICE"<<std::endl;


    

    }
  }
  while(choice!=5);
    return 0;
  
}