void insertNode(struct node *head, int x, int n){
    if(x==1){
        struct node *temp = newNode(x);
        temp->next = head;
        head = temp;
    }
    if(x==n){
        while(head->next)
            head = head->next;

        head->next = newNode(x);
    }
    else{

    }
}
