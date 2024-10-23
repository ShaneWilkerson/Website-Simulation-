//Simulates visiting websites using nodes and push and pop!
//Author: Shane Wilkerson
//Date: 2-10-2024

#include <iostream>
#include <string>
using namespace std;

struct Location //Location contains two different datas
{
    string name;
    string url;
};

struct VisitNode 
{
    Location loc;
    VisitNode * next; 
};

class Stack
{
    private:
        VisitNode * head; //keeps track of head
        VisitNode * create()
{
    VisitNode * newnode;
    try
    {
        newnode = new VisitNode;
    }
    catch (bad_alloc)
    {
        newnode = NULL;
    }
    return newnode;
    // to create new node, use VisitNode * newnode = create()   
}
        void deallocate()
{
    VisitNode * t = create();  //create new temp variable set equal to head
    t = head;
    while (t != NULL)  //while loop to traverse through all nodes 
    {
        t = t -> next;     
        delete head;
        head = t;
    }
}

    public:
        Stack() 
{
    head = NULL;
}
bool push(string name, string url)
{
    VisitNode * newnode = create();
    if (newnode == NULL) //make sure newnode is created
    {
        return false;
    }    
    newnode->next = head; //set newnode to head
    head = newnode; //make head newnode
    newnode->loc.name = name; 
    newnode->loc.url = url;
    return true;
}


string pop()
{
    if (head == NULL) //make sure it is not empty
    {
        return "";
    }
    string popped = head->loc.name; //obtain name for value being popped
    VisitNode * t = create(); //create temporary node
    t=head->next; //traverse once
    delete head; //delete head and set it equal to the temp
    head = t;
    return popped; //return the name   
}

friend void show(Stack & S)
{
    VisitNode * t = S.head;
        while (t != NULL) //while loop to traverse through list and display names
    {
        cout << t->loc.name << " ";
        t=t->next;
    }
    cout << endl;
}



~Stack() //setup for destructor 
{
    deallocate(); //call function
    head = NULL;  //set head to NULL after it's done
}
};



int main()
{
  Stack browser;

  // simulate a browser history
  browser.push("Google", "//google.com");
  browser.push("Amazon", "//amazon.com");
  browser.push("LinkedIn", "//LinkedIn.com");
  browser.push("Reddit", "//reddit.com");

  show(browser);   // this should show the entire history

  // simulate clicking Back button
  string top = browser.pop();
  if (top != "")
    cout << endl << "Clicked back from " << top << endl;
  show(browser);

  // simulate clicking Back button
  top = browser.pop();
  if (top != "")
    cout << endl << "Clicked back from " << top << endl;
  show(browser);

  // simulate clicking Back button
  top = browser.pop();
  if (top != "")
    cout << endl << "Clicked back from " << top << endl;
  show(browser);

  return 0;
}
