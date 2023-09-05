            if (hashTable[i]->next != nullptr) {
                cout << "\tAlso points to:\n";
                Node* other = hashTable[i]->next;
                while (other != nullptr) {
                    cout << "\t\t" << generateKey(other->name) << "\n";
                    other = other->next;
                }