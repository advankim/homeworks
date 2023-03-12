NODE_STRUCT* NewNode(void) {
    NODE_STRUCT* node = new NODE_STRUCT;

    node->object = new OBJECT_TYPE[SIZE];
    node->use = 0;
    node->next = NULL;

    return node;
}

void DeleteNode(NODE_STRUCT* node) {
    if (node != NULL) {
        delete[] node->object;
        delete node;
    }
}

void Clear(NODE_STRUCT** list) {
    if (*list != NULL) {
        NODE_STRUCT temp = **list;

        while (true) {
            temp = **list;

            DeleteNode(*list);

            if (temp.next == NULL) {
                break;
            }

            *list = temp.next;
        }

        *list = NULL;
    }
}

void AddFirst(NODE_STRUCT** list, OBJECT_TYPE* object) {
    if (*list == NULL) {
        NODE_STRUCT* newNode = NewNode();

        *(newNode->object) = *object;
        newNode->use = 1;

        *list = newNode;
    }
    else
    {
        if ((*list)->use < SIZE) {
            for (int i = (*list)->use; i > 0; i--) {
                *((*list)->object + i) = *((*list)->object + i - 1);
            }

            *(*list)->object = *object;
            (*list)->use += 1;
        }
        else {
            NODE_STRUCT* newNode = NewNode();

            *((newNode)->object) = *object;
            newNode->use = 1;
            newNode->next = *list;

            *list = newNode;
        }
    }
}

void AddLast(NODE_STRUCT** list, OBJECT_TYPE* object) {
    if (*list == NULL ) {
        NODE_STRUCT* newNode = NewNode();

        *((newNode)->object) = *object;
        newNode->use = 1;

        *list = newNode;

    }
    else {
        NODE_STRUCT* temp = *list;

        while(true) {
            if ((*list)->next == NULL) {
                break;
            }
               
            *list = (*list)->next;
        }

        if ((*list)->use < SIZE) {   
            *((*list)->object + (*list)->use) = *object;
            (*list)->use += 1;

            *list = temp;
        }
        else {
            NODE_STRUCT* newNode = NewNode();

            *((newNode)->object) = *object;
            newNode->use = 1;

            (*list)->next = newNode;

            *list = temp;
        }
    }
}

void GetFirst(NODE_STRUCT* list, NODE_STRUCT** node, BYTE* byte) {
    if (list == NULL) {
        *node = NULL;
    }
    else {
        *node = list;
        *byte = 0;
    }
}

void GetPrev(NODE_STRUCT* list, NODE_STRUCT* node, BYTE byte, NODE_STRUCT** prevNode, BYTE* prevByte) {
    if (list == NULL) {
        *prevNode = NULL;
    }
    else {
        if (byte != 0) {
            *prevNode = node;
            *prevByte = byte - 1;

            return;
        }

        if (list == node) {
            *prevNode = NULL;

            return;
        }


        NODE_STRUCT* temp = list;

        while (temp->next != node) {
            temp = temp->next;
        }

        *prevNode = temp;
        *prevByte = temp->use - 1;
    }
}

void GetNext(NODE_STRUCT* list, NODE_STRUCT* node, BYTE byte, NODE_STRUCT** nextNode, BYTE* nextByte) {
    if (list == NULL) {
        *nextNode = NULL;
    }
    else {
        if (byte == node->use - 1 && node->next == NULL) {
            *nextNode = NULL;

            return;
        }

        if (byte < node->use - 1) {
            *nextNode = node;
            *nextByte = byte + 1;
        }
        else {
            *nextNode = node->next;
            *nextByte = 0;
        }
    }
}

void GetLast(NODE_STRUCT* list, NODE_STRUCT** node, BYTE* byte) {
    if (list == NULL) {
        *node = NULL;
    }
    else {
        NODE_STRUCT* temp = list;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        *node = temp;
        *byte = temp->use - 1;
    }
}

void InsertPrev(NODE_STRUCT** list, NODE_STRUCT* node, BYTE byte, OBJECT_TYPE* object) {
    if (*list != NULL) {
        NODE_STRUCT* temp = *list;

        if (temp != node) {
            while (temp->next != node) {
                if (temp->next != NULL) {
                    temp = temp->next;
                }
                else {
                    break;
                }
            }
        }

        if (byte != 0) {
            if (byte < node->use) {
                if (node->use < SIZE) {
                    for (int i = node->use; i > byte; i--) {
                        *(node->object + i) = *(node->object + i - 1);
                    }

                    *(node->object + byte) = *object;
                    node->use = node->use + 1;
                }
                else {
                    if (node == *list) {
                        NODE_STRUCT* newNode = NewNode();

                        newNode->next = *list;

                        *(newNode->object) = *(node->object);
                        newNode->use = 1;

                        for (int i = 0; i < byte - 1; i++) {
                            *(node->object + i) = *(node->object + i + 1);
                        }

                        *(node->object + byte - 1) = *object;

                        *list = newNode;
                    }
                    else {
                        if (temp->use < SIZE) {
                            *(temp->object + temp->use) = *(node->object);

                            for (int i = 0; i < byte - 1; i++) {
                                *(node->object + i) = *(node->object + i + 1);
                            }

                            *(node->object + byte - 1) = *object;

                            temp->use = temp->use + 1;
                        }
                        else {
                            NODE_STRUCT* newNode = NewNode();

                            temp->next = newNode;
                            newNode->next = node;

                            *(newNode->object) = *(node->object);
                            newNode->use = 1;

                            for (int i = 0; i < byte - 1; i++) {
                                *(node->object + i) = *(node->object + i + 1);
                            }

                            *(node->object + byte - 1) = *object;
                        }
                    }
                }
            }
        }
        else {
            if (byte < node->use) {
                if (node->use < SIZE) {
                    for (int i = node->use; i > 0; i--) {
                        *(node->object + i) = *(node->object + i - 1);
                    }

                    *(node->object) = *object;

                    node->use = node->use + 1;
                }
                else {
                    if (node == *list) {
                        NODE_STRUCT* newNode = NewNode();

                        newNode->next = *list;

                        *(newNode->object) = *object;
                        newNode->use = 1;

                        *list = newNode;
                    }
                    else {
                        if (temp->use < SIZE) {
                            *(temp->object + temp->use) = *object;

                            temp->use = temp->use + 1;
                        }
                        else {
                            NODE_STRUCT* newNode = NewNode();

                            temp->next = newNode;
                            newNode->next = node;

                            *(newNode->object) = *object;
                            newNode->use = 1;
                        }
                    }
                }
            }
        }
    }
}


void InsertNext(NODE_STRUCT* list, NODE_STRUCT* node, BYTE byte, OBJECT_TYPE* object) {
    if (list != NULL) {
        NODE_STRUCT* temp = list;

        if (node->next != NULL) {
            while (node->next != temp) {
                temp = temp->next;
            }
        }
        else {
            temp = node;
        }

        if (byte < node->use) {
            if (node != temp) {
                if (node->use < SIZE) {
                    
                    for (int i = node->use; i > byte; i--) {
                        *(node->object + i) = *(node->object + i - 1);
                    }

                    *(node->object + byte + 1) = *object;
                    node->use = node->use + 1;
                }
                else {
                    if (temp->use < SIZE) {
                        for (int i = temp->use; i > 0; i--) {
                            *(temp->object + i) = *(temp->object + i - 1);
                        }

                        if (byte == SIZE - 1) {
                            *(temp->object) = *object;
                            temp->use = temp->use + 1;
                        }
                        else {
                            *(temp->object) = *(node->object + node->use - 1);
                            temp->use = temp->use + 1;

                            for (int i = node->use - 1; i > byte; i--) {
                                *(node->object + i) = *(node->object + i - 1);
                            }

                            *(node->object + byte + 1) = *object;
                        }
                    }
                    else {
                        if (byte == SIZE - 1) {
                            NODE_STRUCT* newNode = NewNode();

                            node->next = newNode;
                            newNode->next = temp;

                            *(newNode->object) = *object;

                            newNode->use = newNode->use + 1;
                        }
                        else {
                            NODE_STRUCT* newNode = NewNode();

                            node->next = newNode;
                            newNode->next = temp;

                            *(newNode->object) = *(node->object + node->use - 1);

                            newNode->use = newNode->use + 1;

                            for (int i = node->use; i > byte; i--) {
                                *(node->object + i) = *(node->object + i - 1);
                            }

                            *(node->object + byte + 1) = *object;
                        }
                    }
                }
            }
            else {
                if (node->use < SIZE) {
                    for (int i = node->use; i > byte; i--) {
                        *(node->object + i) = *(node->object + i - 1);
                    }

                    *(node->object + byte + 1) = *object;
                    node->use = node->use + 1;
                }
                else {
                    if (byte == SIZE - 1) {
                        NODE_STRUCT* newNode = NewNode();

                        node->next = newNode;

                        *(newNode->object) = *object;

                        newNode->use = newNode->use + 1;
                    }
                    else {
                        NODE_STRUCT* newNode = NewNode();

                        node->next = newNode;

                        *(newNode->object) = *(node->object + node->use - 1);

                        newNode->use = newNode->use + 1;

                        for (int i = node->use; i > byte; i--) {
                            *(node->object + i) = *(node->object + i - 1);
                        }

                        *(node->object + byte + 1) = *object;
                    }
                }
            }
        }
    }
}

void RemoveCurrent(NODE_STRUCT** list, NODE_STRUCT* node, BYTE byte) {
    if (*list != NULL) {
        for (int i = byte; i < node->use - 1; i++) {
            *(node->object + i) = *(node->object + i + 1);
        }

        node->use = node->use - 1;

        if (node->use <= 0) {
            if (*list == node) {
                if ((*list)->next != NULL) {
                    *list = (*list)->next;

                    DeleteNode(node);
                }                
                else {
                    DeleteNode(node);

                    *list = NULL;
                }
            }
            else {
                NODE_STRUCT* temp = *list;

                while (temp->next != node) {
                    temp = temp->next;
                }
                    
                temp->next = node->next;

                DeleteNode(node);
            }
        }
    }
}

void RemoveFirst(NODE_STRUCT** list) {
    if (*list != NULL) {
        RemoveCurrent(list, *list, 0);
    }
}

void RemovePrev(NODE_STRUCT** list, NODE_STRUCT* node, BYTE byte) {
    if (*list != NULL) {
        GetPrev(*list, node, byte, &node, &byte);

        if (node != NULL) {
            RemoveCurrent(list, node, byte);
        }
    }
}

void RemoveNext(NODE_STRUCT* list, NODE_STRUCT* node, BYTE byte) {
    if (list != NULL) {
        GetNext(list, node, byte, &node, &byte);

        if (node != NULL) {
            RemoveCurrent(&list, node, byte);
        }
    }
}

void RemoveLast(NODE_STRUCT** list) {
    if (*list != NULL) {
        NODE_STRUCT* temp = *list;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        RemoveCurrent(list, temp, temp->use - 1);
    }
}

void Find(NODE_STRUCT* list, OBJECT_TYPE* object, NODE_STRUCT** objectFind, BYTE* byte) {
    if (list == NULL) {
        *objectFind = NULL;
    }
    else {
        NODE_STRUCT* temp = list;
        *objectFind = NULL;

        while (temp != NULL) {
            for (int i = 0; i < temp->use; i++) {
                if (*(temp->object + i) == *object) {
                    *objectFind = temp;
                    *byte = i;

                    return;
                }
            }

            temp = temp->next;
        }
    }
}

void Compress(NODE_STRUCT* list) {
    if (list != NULL) {
        NODE_STRUCT* temp = list;
        NODE_STRUCT* tempTwo = list;

        if (tempTwo->next != NULL) {
            tempTwo = tempTwo->next;
        }
        else {
            return;
        }

        while (temp->next != NULL) {
            while (temp->use < SIZE) {
                if (tempTwo->use == 1) {
                    *(temp->object + temp->use) = *(tempTwo->object);
                    temp->use = temp->use + 1;

                    tempTwo->use = 0;

                    temp->next = tempTwo->next;

                    DeleteNode(tempTwo);

                    tempTwo = temp->next;
                }
                else {
                    *(temp->object + temp->use) = *(tempTwo->object);

                    temp->use = temp->use + 1;

                    RemoveFirst(&tempTwo);
                }

                if (tempTwo == NULL) {
                    return;
                }

                if (temp == tempTwo) {
                    tempTwo = tempTwo->next;
                }
            }

            temp = temp->next;

            if (temp == tempTwo) {
                if (tempTwo->next != NULL) {
                    tempTwo = tempTwo->next;
                }
            }
        }
    }
}

void Reverse(NODE_STRUCT* list) {
    if (list != NULL) {
        if (list->next == NULL) {
            NODE_STRUCT* temp = NewNode();

            for (int i = 0; i < list->use / 2; i++) {
                *(temp->object) = *(list->object + i);
                *(list->object + i) = *(list->object + list->use - i - 1);
                *(list->object + list->use - i - 1) = *(temp->object);
            }

            DeleteNode(temp);
        }
        else {
            NODE_STRUCT* temp = list;
            NODE_STRUCT* tempTwo = NewNode();
            NODE_STRUCT* tempThree = tempTwo;
            NODE_STRUCT* tempFour = NULL;

            tempFour = tempTwo;

            return;

            Compress(list);

            cout << tempTwo << endl;

            while (temp != NULL) {
                for (int i = 0; i < temp->use; i++) {
                    if (tempTwo->use >= SIZE) {
                        tempTwo->next = NewNode();
                        tempTwo = tempTwo->next;
                    }
                    AddFirst(&tempTwo, &*(temp->object + i));
                }

                temp = temp->next;
            }

            temp = tempThree;
            NODE_STRUCT* prevNode = NULL;
            NODE_STRUCT* nextNode = NULL;

            while (temp != NULL) {
                nextNode = temp->next;

                temp->next = prevNode;

                prevNode = temp;

                temp = nextNode;
            }

            temp = list;

            while (tempTwo != NULL) {
                list->use = 0;

                for (int i = 0; i < tempTwo->use; i++) {
                    *(list->object + i) = *(tempTwo->object + i);
                    list->use = list->use + 1;
                }

                list = list->next;
                tempTwo = tempTwo->next;
            }

            tempTwo = tempFour;
            tempThree = tempFour;

            Clear(&tempTwo);
            Clear(&tempThree);
            Clear(&tempFour);
            
            tempTwo = NULL;
            tempThree = NULL;
            tempFour = NULL;
            
            list = temp;

            Compress(list);
        }
    }
}
