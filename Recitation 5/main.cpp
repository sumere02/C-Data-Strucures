#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

class TSiteNode{
    private:
        string time;
        string site_name;
        TSiteNode* up;
    public:
        TSiteNode(string,string);
        ~TSiteNode();
        void set_time(string);
        string get_time();
        void set_site_name(string);
        string get_site_name();
        void set_up(TSiteNode*);
        TSiteNode* get_up();

};

class DateNode{
    private:
        string date;
        DateNode* next;
        DateNode* prev;
        TSiteNode* up;

    public:
        DateNode(string);
        ~DateNode();
        void set_date(string);
        string get_date();
        void set_next(DateNode*);
        DateNode* get_next();
        void set_prev(DateNode*);
        DateNode* get_prev();
        void set_up(TSiteNode*);
        TSiteNode* get_up();

};


class MultiList{
    private:
        DateNode* head;
        DateNode* tail;

    public:
        MultiList();
        ~MultiList();
        DateNode* search_date(string);
        void add_node(string,string,string);
        void remove_node(string,string);
        void print_list();
        DateNode* search_prev_hor(string);
        TSiteNode* search_prev_ver(string,TSiteNode*);
        void add_ver(string,string,DateNode*);
        void delete_ver(string,DateNode*);

};


TSiteNode::TSiteNode(string time,string site_name){
    this->time = time;
    this->site_name = site_name;
    this->up = NULL;
}

TSiteNode::~TSiteNode(){
    if(up->get_up() != NULL){
        delete up;
    }
}

void TSiteNode::set_time(string time){
    this->time = time;
}

string TSiteNode::get_time(){
    return this->time;
}

void TSiteNode::set_site_name(string site_name){
    this->site_name = site_name;
}

string TSiteNode::get_site_name(){
    return this->site_name;
}

void TSiteNode::set_up(TSiteNode* up){
    this->up = up;
}

TSiteNode* TSiteNode::get_up(){
    return this->up;
}

DateNode::DateNode(string date){
    this->date = date;
    this->next = NULL;
    this->prev = NULL;
    this->up = NULL;
}

DateNode::~DateNode(){
    if(this->next != NULL){
        delete this->next;
    }
    if(up != NULL)
        delete up;
}

void DateNode::set_date(string date){
    this->date = date;
}

string DateNode::get_date(){
    return this->date;
}

void DateNode::set_next(DateNode* next){
    this->next = next;
}

DateNode* DateNode::get_next(){
    return this->next;
}

void DateNode::set_prev(DateNode* prev){
    this->prev = prev;
}

DateNode* DateNode::get_prev(){
    return this->prev;
}

void DateNode::set_up(TSiteNode* up){
    this->up = up;
}

TSiteNode* DateNode::get_up(){
    return this->up;
}
/*
MultiList::MultiList()
{
    head = NULL;
    tail = NULL;
}

MultiList::~MultiList()
{
    DateNode *p1 = head;
    DateNode *n1 = head;
    TSiteNode *p2 = NULL;
    TSiteNode *n2 = NULL;

    while (n1 != NULL)
    {
        n2 = n1->get_up();
        p2 = n2->get_up();
        while (n2 != NULL)
        {
            n2 = p2->get_up();
            delete p2;
            p2 = n2;
        }
        n1 = p1->get_next();
        delete p1;
        p1 = n1;
    }
}

DateNode *MultiList::search_prev_hor(string date)
{
    DateNode *p = head;

    if (date <= head->get_date())
        return NULL;
    else
    {
        while (p->get_next())
        {
            if (p->get_next()->get_date() >= date)
                return p;
            p = p->get_next();
        }
        return p;
    }
}

TSiteNode *MultiList::search_prev_ver(string time, TSiteNode *fnode)
{
    TSiteNode *p = fnode;

    if (!p || time <= p->get_time())
        return NULL;
    else
    {
        while (p->get_up())
        {
            if (p->get_up()->get_time() >= time)
                return p;
            p = p->get_up();
        }
        return p;
    }
}

void MultiList::add_ver(string time, string site_name, DateNode *fnode)
{
    TSiteNode *new_node = new TSiteNode(time, site_name);
    TSiteNode *p = fnode->get_up();
    if (!p) // firstly
    {
        fnode->set_up(new_node);
    }
    else
    {
        TSiteNode *prev = this->search_prev_ver(time, p);

        if (prev == NULL) // first node
        {
            new_node->set_up(p);
            fnode->set_up(new_node);
        }
        else if (prev->get_up() == NULL) // last node
        {
            prev->set_up(new_node);
        }
        else // between node
        {
            new_node->set_up(prev->get_up());
            prev->set_up(new_node);
        }
    }
}

void MultiList::delete_ver(string time, DateNode *fnode)
{
    TSiteNode *p = fnode->get_up();
    TSiteNode *prev = this->search_prev_ver(time, p);

    if (!p) // no node
        return;

    if (prev == NULL) // first node
    {
        fnode->set_up(p->get_up());
        p->set_up(NULL);
        delete p;
    }
    else if (prev->get_up()->get_up() == NULL) // last node
    {
        delete prev->get_up();
        prev->set_up(NULL);
    }
    else // between node
    {
        TSiteNode *cur = prev->get_up();
        prev->set_up(cur->get_up());
        cur->set_up(NULL);
        delete cur;
    }
}

void MultiList::add_node(string date, string time, string site_name)
{

    if (head == NULL) // firstly
    {
        DateNode *new_hor = new DateNode(date);
        TSiteNode *new_ver = new TSiteNode(time, site_name);
        new_hor->set_up(new_ver);
        head = new_hor;
        tail = new_hor;
    }
    else
    {
        if (head->get_date() == date) // if date already added and equals to head
        {
            this->add_ver(time, site_name, head);
            return;
        }

        DateNode *prev = this->search_prev_hor(date);

        if (prev && prev->get_next() && prev->get_next()->get_date() == date) // date already added and not equal to head
        {
            this->add_ver(time, site_name, prev->get_next());
        }

        else // date not added
        {
            DateNode *new_hor = new DateNode(date);

            if (prev == NULL) // add to beginning
            {
                new_hor->set_next(head);
                head->set_prev(new_hor);
                head = new_hor;
            }
            else if (prev == tail) // add to ending
            {
                tail->set_next(new_hor);
                new_hor->set_prev(tail);
                tail = new_hor;
            }
            else // between
            {
                DateNode *old_next = prev->get_next();
                new_hor->set_next(old_next);
                new_hor->set_prev(prev);
                prev->set_next(new_hor);
                old_next->set_prev(new_hor);
            }
            this->add_ver(time, site_name, new_hor);
        }
    }
}

void MultiList::remove_node(string date, string time)
{
    DateNode *prev = this->search_prev_hor(date);
    DateNode *cur;
    if (prev == NULL) // if head
        cur = head;
    else
        cur = prev->get_next();
    this->delete_ver(time, cur);
}

void MultiList::print_list()
{
    DateNode *p_hor = head;
    TSiteNode *p_ver;

    while (p_hor)
    {
        cout << p_hor->get_date() << ":" << endl;
        p_ver = p_hor->get_up();
        while (p_ver)
        {
            cout << p_ver->get_time() << "->" << p_ver->get_site_name() << endl;
            p_ver = p_ver->get_up();
        }
        p_hor = p_hor->get_next();
    }
}
*/

MultiList::MultiList(){
    head = NULL;
    tail = NULL;
}

MultiList::~MultiList(){
    delete head;
}

DateNode* MultiList::search_date(string date){
    if(head == NULL){
        return NULL;
    }
    else if(head == tail){
        if(head->get_date() == date){
            return head;
        }
        return NULL;
    }
    else{
        DateNode* temp = head;
        while(temp->get_next() != NULL){
            if(temp->get_date() == date){
                return temp;
            }
            temp = temp->get_next();
        }
        if(temp->get_date() == date){
            return temp;
        }
        return NULL;
    }
}

DateNode* MultiList::search_prev_hor(string date){
    if(date <= head->get_date()){
        return NULL;
    }
    DateNode* temp = head;
    while(temp->get_next() != NULL){
        if(date <= temp->get_next()->get_date()){
            return temp;
        }
        temp = temp->get_next();
    }
    return temp;
}

TSiteNode* MultiList::search_prev_ver(string time,TSiteNode* head){
    if(time <= head->get_time()){
        return NULL;
    }
    TSiteNode* temp = head;
    while(temp->get_up() != NULL){
        if(time <= temp->get_up()->get_time()){
            return temp;
        }
        temp = temp->get_up();
    }
    return temp;
}

void MultiList::add_ver(string time,string site_name,DateNode* Node){
    TSiteNode* newUp = new TSiteNode(time,site_name);
    if(Node->get_up() == NULL){
        Node->set_up(newUp);
    }
    else{
        TSiteNode* prev = search_prev_ver(time,Node->get_up());
        if(prev == NULL){
            newUp->set_up(Node->get_up());
            Node->set_up(newUp);
        }
        else if(prev->get_up() == NULL){
            prev->set_up(newUp);
        }
        else{
            newUp->set_up(prev->get_up());
            prev->set_up(newUp);
        }

    }
}

void MultiList::add_node(string date,string time,string site_name){
    DateNode* newNode = search_date(date);
    if(newNode == NULL){
        newNode = new DateNode(date);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            DateNode* prev = search_prev_hor(date);
            if(prev == NULL){
                newNode->set_next(head);
                head->set_prev(newNode);
                head = newNode;
            }
            else{
                if(prev != tail){
                    newNode->set_next(prev->get_next());
                    newNode->set_prev(prev);
                    prev->set_next(newNode);
                    newNode->get_next()->set_prev(newNode);
                }
                else{
                    newNode->set_prev(prev);
                    prev->set_next(newNode);
                    tail=newNode;
                }
            }
        }
    }
    add_ver(time,site_name,newNode);
}

void MultiList::delete_ver(string time,DateNode* node){
    TSiteNode* head = node->get_up();
    TSiteNode* temp = head;
    TSiteNode* searched = NULL;
    if(head->get_up() == NULL){
        if(time == head->get_time()){
            delete head;
            node->set_up(NULL);
            return;
        }
    }
    else{
        if(temp->get_time() == time){
            searched = temp;
            node->set_up(searched->get_up());
            searched->set_up(NULL);
            delete searched;
            return;
        }
    }

    while(temp->get_up() != NULL){
        if(temp->get_up()->get_time() == time){
            searched = temp->get_up();
            break;
        }   
        temp = temp->get_up();
    }
    if(searched != NULL){
        temp->set_up(searched->get_up());
        searched->set_up(NULL);
        delete searched;
    }

}

void MultiList::remove_node(string date,string time){
    DateNode* node = search_date(date);
    if(node != NULL){
        if(node->get_up() != NULL)
            delete_ver(time,node);
    }
}


void MultiList::print_list()
{
    DateNode *p_hor = head;
    TSiteNode *p_ver;

    while (p_hor)
    {
        cout << p_hor->get_date() << ":" << endl;
        p_ver = p_hor->get_up();
        while (p_ver)
        {
            cout << p_ver->get_time() << "->" << p_ver->get_site_name() << endl;
            p_ver = p_ver->get_up();
        }
        p_hor = p_hor->get_next();
    }
}


bool perform_operation(char);
void print_menu();
void add_record();
void delete_record();

MultiList* web_history = new MultiList();

int main(){

    bool end = false;
    char choice;

    while (!end)
    {
        print_menu();
        cin >> choice;
        end = perform_operation(choice);
    }
    delete web_history;
    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "A: Add a website record to web browser history" << endl;
    cout << "D: Delete a website record from web browser history" << endl;
    cout << "P: Print the web browser history" << endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {A,D,P,E}: ";
}

bool perform_operation(char choice)
{
    bool terminate = false;

    switch (choice)
    {
    case 'P':
    case 'p':
        web_history->print_list();
        break;
    case 'A':
    case 'a':
        add_record();
        break;
    case 'D':
    case 'd':
        delete_record();
        break;
    case 'E':
    case 'e':
        terminate = true;
        break;
    default:
        cout << "Error: You have entered an invalid choice" << endl;
        cin >> choice;
        terminate = perform_operation(choice);
        break;
    }
    return terminate;
}

void add_record()
{
    string f_date,date,time,site_name;
    cout << "Enter the website name:";
    cin >> site_name;
    cout << "Enter the date with yyyy-mm-dd HH:MM:SS format:";
    getline(cin >> ws,f_date);
    time = f_date.substr(f_date.size()-8);
    date = f_date.substr(0,10);
    //time = f_date.substr(f_date.size()-1);
    //date = f_date.substr(0,1);
    web_history->add_node(date,time,site_name);

}
void delete_record()
{
    string f_date,date,time;
    cout << "Enter the date with yyyy-mm-dd HH:MM:SS format:";
    getline(cin >> ws,f_date);
    time = f_date.substr(f_date.size()-8);
    date = f_date.substr(0,10);
    //time = f_date.substr(f_date.size()-1);
    //date = f_date.substr(0,1);
    web_history->remove_node(date,time);
}
