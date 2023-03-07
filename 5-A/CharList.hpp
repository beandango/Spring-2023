#ifndef CHARLIST_HPP
#define CHARLIST_HPP

class CharList
{
    private:
        struct ListNode
        {
            char value;              // the char in this node
            ListNode *next;         // to point to next node
        };

        ListNode *head;             // List head pointer
    public:
        // constructor
        CharList()
            {   head = nullptr; }
        
        // Destructor
        ~CharList();

        // member functions
        void appendNode(char);
        void insertNode(char);
        void deleteNode(char);
        void displayList() const;   // read-only
};

#endif //CHARLIST_HPP