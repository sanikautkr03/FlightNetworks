#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
// #include<unistd.h>



//MAX NUMBER OF NODES
#define N 1000


// STRUCTURE OF A SINGLE NODE
struct ListNode{
    int v;
    int cost;
    struct ListNode* next;
};


typedef struct ListNode node;



// SREUCTURE OF GRAPH
struct Graph{
    node* head[N];
    node* tail[N];
};


typedef struct Graph graph;


// MAIN GRAPH
graph *g = NULL;



// TEMPROERY NODES USED IN DIJKISTRA
struct TempNode{
    int data;
    int cost;
};

typedef struct TempNode tempNode;




// GLOBAL HEAP
tempNode heap[1000000];
int heapSize = 0;


char places[N][20] = {""};
int noOfPlaces = 0;




//STACK ARRAY USED IN FINDING ALL POSSIBLE ROOTS
int stackArray[N] = {-1};
int stackArraySize = 0;
int flagForPath = 0;



//flight informeation
struct FlightInfo{
    int id;
    int from;
    int to;
    int flightPath[N];
    int noOfSeatsAvailable;
    int totalCost;
    int pathSize;
};


// Structure to represent user experience feedback
struct Experience {
    char review[1000];
    float rating;
};

//DYNAMIC ALLOCATION DONE IN ASSIGNINTIALLYNULL FUNCTION
typedef struct FlightInfo flights;
flights *flight;
int noOfFlights = 0;



//CURRENT USE WHO HAVE LOGED IN
char currUserName[20];



//ALL FUNCTION USED


//FUNCTION TO DISPLAY SPECIFIC FLIGHT
void displaySpecificFlights(flights temp);
//FUNCTION DISPLAY CURRENT FLIGHT INFO
void displayCurrFlightInfo(int i);
//DSIPLAY ALL PATH STORE IN STRUCTURE FLIGHTS
void displayFlighsInfo();
//CODE TO COMPARE TWO STRINGS
int isGreateString(char first[20], char second[20]);
//FUNCTIO WHICH PROVIDES KEY FOR THE GIVEN LOCATION
int findKeyForString(char place[20]);
//FUNCTION TO SORT PLACES NAMES IN ALPHABATICAL ORDER
void sortPlaces();
//ASSIGNING UNIQUE VALUE FOR EVERY PLACE
void addPlaces();
//FUNCTION TO DISPLA ALL LOCATIONS WHERE FLIGHTS ARE AVAILABLE
void displayPlaces();
//FUNCTIO WHICH CONVERTS ALL CHARECTERS IN A STRING INTO LOWERCASES
void convertToLowerCase(char str[100]);
// HEAPIFY FUNCTION TO MAINTAIN HEAP PROPERTY.
void heapify(int n, int i);
// FUNCTION TO BUILD A HEAP FROM HEAP.
void buildHeap();
//PUSH FUNCTION FOR HEAP
void heapPush(int data, int cost);
//TO CHECK WHETHER HEAP IS EMPTY OR NOT
int isHeapEmpty();
//POP IN HEAP
void heapPop();
//FUNCTION WHICH CREATES AND RETURNS NEW NODE IN GRAPH
node* createNewNode(int v, int cost);
// ASSIGNING NULL AS INITIAL VALUES FOR ALL LINKED LISTS
void assignNullInitially();
// FUNCTION FOR ADDING AN NEW EDGE
void addEdge(int u, int v, int cost);
//FUNCTION TO FORM A CONNECTION BETWEEN 2 PLACES USING STRING FORMAT
void formConnectionBetweenPlaces();
//FUNCTION TO DISPLAY THE GRAPH
void displayGraph();
//DFS FOR DESIGNER
void dfs(int i, int visited[], int cost);
void dfs_traversal();
//ALGORITHM WHICH FINDS MINIMUM COSTED PATH FROM SOURCE TO DEST
void dijkstra(int s, int d);
//SHORTEST PATH W.R.T COST
void shortest_cost_from_source_to_des_w_r_t_cost();
//STACK USED TO KEEP TRACK OF ALL THE NODES WHICH ARE IN A PATH
void printStackArray(int cost, int assignThisPathToFlight);
//DFS USED FOR FINDING ALL PATHS
void dfs_for_finding_all_paths(int currNode, int dest, int visited[], int cost, int assignThisPathToFlight);
//FUNCTION TO FIND ALL POSSIBLE FLIGHTS/ROOTA
void viewAllPossiblePaths();
//MENU FOR FLIGHTS
void menuForFlights();
// MENU AFTER LOG IN
void menuAferLogInForUser();
// KMP algorithm for string matching
int kmpSearch(const char *text, const char *pattern);
// Function to check if a username already exists in the file using KMP
int isUsernameExists(const char *username);
// Function to register a new user
void registerUser();
// Function to authenticate a user
void loginUser();
//MENU FOR USER LOG IN
void menuForUser();
//MENU AFTER LOG IN
void menuBeforeLogIn();
//ASSIGN EVERY PATH TO SOME FLIGHT
void assignPathToEachFlight();
//SORT TEMP FLIGHTS FROM SOURCE TO DESTINATION BY COST
void sortTempFlightsFromSourceToDestByCost(flights *TempFlightsFromSourceToDest, int noOfFlights);
//FUNCTION WHICH FINDS FOR THE FIRST FLIGHT WHICH HAS SOURCE AND DEST
int findFirstOccuOfReqFlight(int source, int dest);
//FUNCTION WHICH SEARCHES FOR GIVEN SOURCE TO DESTINATION
int searchForFlight(int source, int dest);
//FUNCTION TO VIEW ALL PATHS FROM SOURCE TO DESTINATION USING FLIGHTINFO
void viewAllFlightsFromSourceToDestination();
//FUNCTION TO BOOK A FLIGHT BY USER
void bookFlight();
//FILE FOR EACH AND EVERY USER
void createUserFile(char *username);
//FUNCTION TO WRITE BOOKING DETAILS IN USER FILE
void writeBookingDetailsIntoFile(const char *username, int flight_id, int no_of_seats_booked);
//FUNCTION TO PRINT ALREADY BOOKED FLIGHTS
int display_booked_flights(char* currUserName);
//FUNCTION TO CANCEL ALREADY BOOKED FLIGHT
void cancel_booking(char* currUserName);
// Function to check if a manager name already exists in the file using KMP
int isManagerExists(const char *username);
//FOR MANAGER
void registerManager();
// Function to authenticate a manager
void loginManager();
//MENY AFTER MANAGER LOG IN
void menuAferLogInForManager();
//ADD A PLACE IF ITS NEW AFTER MANAGER ENTERS
void addNewPlaceByTakingInput(char placeName[20]);
//FUNCTION TO ADD A NEW FLIGHTS
void addNewFlightsByTakingInput();
//FUNCTION FOR NOT DISPLAYING PASSWORD ON SCREEN
void getPassword(char *password, int max_length);



#include <stdio.h>
#include <windows.h>

// Function to display an attractive heading
void heading()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);  // Set text color to cyan and bold

    printf("\t\t**********************************************************************************\n");
    SetConsoleTextAttribute(hConsole, 14);  // Set text color to yellow and bold
    printf("\t\t*\t\t* * * * * * * * SKY VOYAGE NETWORK * * * * * * * *\t         *\n");
    SetConsoleTextAttribute(hConsole, 11);  // Set text color to cyan and bold
    printf("\t\t*\t\t\t\t\t\t\t\t                 *\n");
    SetConsoleTextAttribute(hConsole, 10);  // Set text color to green and bold
    printf("\t\t*\t* * * * More than flights, it's a symphony of destinations * * * *       *\n");
    SetConsoleTextAttribute(hConsole, 11);  // Set text color to cyan and bold
    printf("\t\t*\t\t\t\t\t\t\t\t                 *\n");
    SetConsoleTextAttribute(hConsole, 11);  // Set text color to cyan and bold
    printf("\t\t**********************************************************************************\n");

    SetConsoleTextAttribute(hConsole, 7);  // Reset text formatting to default
}


// Function to gather feedback from the user
struct Experience getFeedback() {
    struct Experience userFeedback;

    // Prompt user for review
    printf("Please provide your review (up to 1000 characters):\n");
    gets(userFeedback.review);

    // Prompt user for rating
    printf("Please provide your rating (1-5):\n");
    scanf("%2f", &userFeedback.rating);

    // Clear input buffer
    while (getchar() != '\n');

    return userFeedback;
}

// Function to write feedback to a file
void writeFeedbackToFile(struct Experience userExperience) {
    FILE *file = fopen("feedback.txt", "a");

    if (file != NULL) {
        fprintf(file, "Review: %s", userExperience.review);
        fprintf(file, "Rating: %d\n", userExperience.rating);

        fclose(file);
    } else {
        printf("Error opening the file for writing.\n");
    }
}


//FUNCTION TO DISPLAY SPECIFIC FLIGHT
void displaySpecificFlights(flights temp){


    printf("\nFlight ID: %d\n", temp.id);
    printf("name: flight%dSKV\n", temp.id);
    printf("%s -> %s\n", places[temp.from], places[temp.to]);

    printf("its root is\n");

    int j=0;

    for(j=0; j<temp.pathSize-1; j++){
        printf("%s -> ", places[temp.flightPath[j]]);
    }

    printf("%s.\n", places[temp.flightPath[j++]]);
    printf("no of seats available %d\n", temp.noOfSeatsAvailable);
    printf("COST: %d\n", temp.totalCost);

    printf("\n");
}


//FUNCTION DISPLAY CURRENT FLIGHT INFO
void displayCurrFlightInfo(int i){


    printf("\nFlight ID: %d\n", i);
    printf("name: flight%dSKV\n", i);
    printf("%s -> %s\n", places[flight[i].from], places[flight[i].to]);

    printf("its root is\n");

    int j=0;

    for(j=0; j<flight[i].pathSize-1; j++){
        printf("%s -> ", places[flight[i].flightPath[j]]);
    }

    printf("%s.\n", places[flight[i].flightPath[j++]]);
    printf("COST: %d\n", flight[i].totalCost);
    printf("no of seats available %d\n", flight[i].noOfSeatsAvailable);

    printf("\n");

}

//DSIPLAY ALL PATH STORE IN STRUCTURE FLIGHTS
void displayFlighsInfo(){
    for(int i=0; i<noOfFlights; i++){
        displayCurrFlightInfo(i);
    }
}



//CODE TO COMPARE TWO STRINGS
int isGreateString(char first[20], char second[20]){
    int i=0, j=0;
    int n = strlen(first);
    int m = strlen(second);


    while(i<n && j<m){
        if(first[i]==second[j]){
            i++, j++;
        } else if(first[i] > second[j]){
            return 1;
        } else{
            return 0;
        }
    }

    if(j<m) return 0;
    else return 1;
}


//FUNCTION WHICH PROVIDES KEY FOR THE GIVEN LOCATION
int findKeyForString(char place[20]){
    int lo = 0, hi = noOfPlaces-1;
    int mid = 0;


    while(lo <= hi){
        mid = (lo+hi) >> 1;

        if(strcmp(places[mid], place)==0){
            return mid;
        } else if(isGreateString(place, places[mid])){
            lo = mid+1;
        } else{
            hi = mid-1;
        }
    }


    return -1;
}


//FUNCTION TO SORT PLACES NAMES IN ALPHABATICAL ORDER
void sortPlaces(){
    int n = noOfPlaces;
    char temp[20];
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(isGreateString(places[j], places[j+1])){
                strcpy(temp, places[j]);
                strcpy(places[j], places[j+1]);
                strcpy(places[j+1], temp);
            }
        }
    }

}


//ASSIGNING UNIQUE VALUE FOR EVERY PLACE
void addPlaces(){

    strcat(places[0], "bengaluru");
    noOfPlaces++;
    strcat(places[1], "mumbai");
    noOfPlaces++;
    strcat(places[2], "delhi");
    noOfPlaces++;
    strcat(places[3], "indore");
    noOfPlaces++;
    strcat(places[4], "assam");
    noOfPlaces++;
    strcat(places[5], "punjab");
    noOfPlaces++;
    strcat(places[6], "karachi");
    noOfPlaces++;
    strcat(places[7], "chennai");
    noOfPlaces++;
    strcat(places[8], "norway");
    noOfPlaces++;


    sortPlaces();
}






//FUNCTION TO DISPLA ALL LOCATIONS WHERE FLIGHTS ARE AVAILABLE
void displayPlaces(){
    int i=0;
    printf("\n\n---PLACES WHERE OUR FLIGHTS ARE AVAILABLE---\n\n");
    for(int i=0; i<noOfPlaces; i+=2){
        if(i==noOfPlaces-1){
            printf("%d. %s\n", i, places[i]);
        } else{
            printf("%d. %s\t\t\t%d. %s\n", i, places[i], i+1, places[i+1]);
        }
    }
    printf("\n");
}



//FUNCTIO WHICH CONVERTS ALL CHARECTERS IN A STRING INTO LOWERCASES
void convertToLowerCase(char str[100])
{
    for (int i = 0; i <= strlen(str); i++)
    {
        // The ASCII value of A is 65 and Z is 90
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32; /* add 32 to string character to convert into lower case. */
    }

    // printf("in lower case %s\n", str);
}





// FUNCTION TO DISPLAY HEAP
void printHeap(){
    printf("\n");
    for(int i=0; i<heapSize; i++){
        printf("{%d, %d} ", heap[i].data, heap[i].cost);
    }
    printf("\n");
}

// HEAPIFY FUNCTION TO MAINTAIN HEAP PROPERTY.
void heapify(int n, int i)
{

    int smallest = i;

    while (i < n)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;


        if (leftChild < n && heap[leftChild].cost < heap[smallest].cost)
        {
            smallest = leftChild;
        }

        if (rightChild < n && heap[rightChild].cost < heap[smallest].cost)
        {
            smallest = rightChild;
        }

        if (i != smallest)
        {
            tempNode temp = heap[i];
            heap[i] =  heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        }
        else
        {
            break;
        }
    }

}

// FUNCTION TO BUILD A HEAP FROM HEAP.
void buildHeap()
{

    int n = heapSize;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }

}

//PUSH FUNCTION FOR HEAP
void heapPush(int data, int cost){
    tempNode newNode;
    newNode.data = data;
    newNode.cost = cost;

    heap[heapSize] = newNode;
    heapSize++;
    buildHeap();

}

//TO CHECK WHETHER HEAP IS EMPTY OR NOT
int isHeapEmpty(){
    if(heapSize==0) return 1;
    else return 0;
}

tempNode heapTop(){
    if(!isHeapEmpty()){
        return heap[0];
    } else{
        tempNode newNode = {-1, -1};
        return newNode;
    }
}

//POP IN HEAP
void heapPop(){
    if(!isHeapEmpty()){
        heap[0] = heap[heapSize-1];
        heapSize--;
        heapify(heapSize, 0);
    } else{
        printf("Heap is Empty\n");
        return ;
    }
}



//FUNCTION WHICH CREATES AND RETURNS NEW NODE IN GRAPH
node* createNewNode(int v, int cost){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->v = v;
    newNode->cost = cost;
    newNode->next = NULL;

    return newNode;
}




// ASSIGNING NULL AS INITIAL VALUES FOR ALL LINKED LISTS
void assignNullInitially(){
    // GRAPH INITIATION
    flight = (flights*)malloc(sizeof(flights)*N);
    g = (graph*)malloc(sizeof(graph));

    for(int i=0; i<N; i++){
        g->head[i] = NULL;
        g->tail[i] = NULL;
    }
}


// FUNCTION FOR ADDING AN NEW EDGE
void addEdge(int u, int v, int cost){

    // printf("%d %d %d\n", u, v, cost);

    node* newNode = createNewNode(v, cost);
    node* new_node = createNewNode(u, cost);

    //USING INSERT AT TAIL
    if(!g->head[u]){
        g->head[u] = newNode;
    } else{
        g->tail[u]->next = newNode;
    }
        g->tail[u] = newNode;

    // if(!g->head[v]){
    //     g->head[v] = new_node;
    // } else{
    //     g->tail[v]->next = new_node;
    // }
    // g->tail[v] = new_node;

}


//FUNCTION TO FORM A CONNECTION BETWEEN 2 PLACES USING STRING FORMAT
void formConnectionBetweenPlaces(){
    addEdge(findKeyForString("bengaluru"), findKeyForString("mumbai"), 2);
    addEdge(findKeyForString("bengaluru"), findKeyForString("delhi"), 7);
    addEdge(findKeyForString("mumbai"), findKeyForString("delhi"), 3);
    addEdge(findKeyForString("delhi"), findKeyForString("assam"), 5);
    addEdge(findKeyForString("delhi"), findKeyForString("indore"), 1);
    addEdge(findKeyForString("indore"), findKeyForString("mumbai"), 4);
    addEdge(findKeyForString("indore"), findKeyForString("punjab"), 2);
    addEdge(findKeyForString("indore"), findKeyForString("assam"), 7);
    addEdge(findKeyForString("assam"), findKeyForString("punjab"), 1);
    addEdge(findKeyForString("mumbai"), findKeyForString("karachi"), 9);
    addEdge(findKeyForString("karachi"), findKeyForString("mumbai"), 9);
    addEdge(findKeyForString("karachi"), findKeyForString("chennai"), 11);
    addEdge(findKeyForString("chennai"), findKeyForString("karachi"), 11);
    addEdge(findKeyForString("bengaluru"), findKeyForString("norway"), 23);
    addEdge(findKeyForString("delhi"), findKeyForString("norway"), 28);
    addEdge(findKeyForString("norway"), findKeyForString("delhi"), 28);




    assignPathToEachFlight();

}


//FUNCTION TO DISPLAY THE GRAPH
void displayGraph(){

    node* temp = NULL;

    for(int i=0; i<N; i++){
        int flag = 0;
        temp = g->head[i];
        if(temp){
            printf("%d -> ", i);
        }

        while(temp){
            printf("{%d, %d} ", temp->v, temp->cost);
            temp = temp->next;
            flag = 1;
        }

        if(flag) printf("\n");
    }

}

//DFS FOR DESIGNER
void dfs(int i, int visited[], int cost){
    node* temp = g->head[i];
    printf("{%d %d} -> ", i, cost);
    visited[i] = 1;


    while(temp){
        int v = temp->v;
        if(!visited[v]){
            dfs(v, visited, temp->cost);
        }
        temp = temp->next;
    }
}

void dfs_traversal(){
    int visited[N] = {0};

    for(int i=0; i<N; i++){
        if(!visited[i] && g->head[i]){
            dfs(i, visited, 0);
            printf("NULL\n");
        }
    }
}

//ALGORITHM WHICH FINDS MINIMUM COSTED PATH FROM SOURCE TO DEST
void dijkstra(int s, int d){
    heapPush(s, 0);
    int dest = d;
    int parent[N] = {-1};
    int cost[N] = {10000};
    for(int i=0; i<N; i++){
        cost[i] = 100000;
        parent[i] = i;
    }

    cost[s] = 0;
    parent[s] = s;

    while(!isHeapEmpty()){
        tempNode topEle = heapTop();
        heapPop();

        int u = topEle.data;
        int w = cost[u];
        node* temp = g->head[u];
        while(temp){
            if(w + temp->cost < cost[temp->v]){
                cost[temp->v] = w + temp->cost ;
                parent[temp->v] = u;
                heapPush(temp->v, cost[temp->v]);
            }
            temp = temp->next;
        }
    }



    int tempArr[N] = {-1};
    int idx = 0;
    while(parent[d]!=d){
        tempArr[idx++] = d;
        d = parent[d];
    }

    int tempArrSize = idx;

    int i=0, j=tempArrSize-1;

    while(i<j){
        int temp = tempArr[i];
        tempArr[i] = tempArr[j];
        tempArr[j] = temp;
        i++;
        j--;
    }

    if(cost[dest]==100000){
        printf("\nSorry there is no Filght available from %s to %s\n", places[s], places[dest]);
        // sleep(2);
        system("cls");
        return;
    }

    printf("\n%s -> ", places[s]);
    for(int i=0; i<tempArrSize-1; i++){
        printf("%s -> ", places[tempArr[i]]);
    }
    printf("%s\n", places[dest]);
    printf("total cost %d\n\n", cost[dest]);

    int waste;
    printf("Press any thing to go back: ");
    scanf("%d", &waste);
    fflush(stdin);
    system("cls");
}


//SHORTEST PATH W.R.T COST
void shortest_cost_from_source_to_des_w_r_t_cost(){
    char source_name[20], dest_name[20];
    printf("Enter source ");
    scanf("%s", source_name);
    printf("Enter destination ");
    scanf("%s", dest_name);


    //CONVERTING ID TO PLACE NAME
    if(source_name[0]>='0' && source_name[0]<='9'){
        int sourceNameIdx = atoi(source_name);
         if(sourceNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(source_name, places[sourceNameIdx]);
    }

    if(dest_name[0]>='0' && dest_name[0]<='9'){
        int destNameIdx = atoi(dest_name);
         if(destNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(dest_name, places[destNameIdx]);
    }

    //COVERT THE STRING INTO LOWERACSE TO AVOID AMBIGUITY BETWEEN SYTEM AND USER
    convertToLowerCase(source_name);
    convertToLowerCase(dest_name);


    int u = findKeyForString(source_name);
    int v = findKeyForString(dest_name);

    if(u==-1 || v==-1){
        printf("\nSorry! There is no Flight availability from %s -> %s\n", source_name, dest_name);
        // sleep(2);
        system("cls");
        return;
    }
    dijkstra(u, v);
}





//STACK USED TO KEEP TRACK OF ALL THE NODES WHICH ARE IN A PATH
void printStackArray(int cost, int assignThisPathToFlight){

    if(assignThisPathToFlight==0){
    printf("\n");
    }

    //ASSING FROM FOR FLIGHT
    flight[noOfFlights].from = stackArray[0];
    flight[noOfFlights].noOfSeatsAvailable = 5;

    int pathIdxForFlight = 0;
    for(int i=0; i<stackArraySize-1; i++){
        if(assignThisPathToFlight==0){
            printf("%s -> ", places[stackArray[i]]);
        }

        if(assignThisPathToFlight==1){
            flight[noOfFlights].flightPath[pathIdxForFlight++] = stackArray[i];
        }

    }

    if(assignThisPathToFlight==0){
        printf("%s", places[stackArray[stackArraySize-1]]);
        printf("\t| cost: %d\n", cost);
        printf("\n");
    }


    if(assignThisPathToFlight==1){
        //ADDING LAST STOP
        flight[noOfFlights].flightPath[pathIdxForFlight++] = stackArray[stackArraySize-1];
        flight[noOfFlights].to = stackArray[stackArraySize-1];
        flight[noOfFlights].totalCost = cost;
    }
    if(assignThisPathToFlight==1){
        flight[noOfFlights].pathSize = pathIdxForFlight;
        flight[noOfFlights].id = noOfFlights;
        noOfFlights++;
    }

}

//DFS USED FOR FINDING ALL PATHS
void dfs_for_finding_all_paths(int currNode, int dest, int visited[], int cost, int assignThisPathToFlight){

    stackArray[stackArraySize] = currNode;
    stackArraySize++;

    if(currNode == dest){
        flagForPath = 1;
        printStackArray(cost, assignThisPathToFlight);
        stackArraySize--;
        return;
    }

    node* temp = g->head[currNode];
    visited[currNode] = 1;

    while(temp){
        int v = temp->v;
        if(!visited[v]){
            dfs_for_finding_all_paths(v, dest, visited, cost+temp->cost, assignThisPathToFlight);
        }
        temp = temp->next;
    }

    visited[currNode] = 0;
    stackArraySize--;

}

//FUNCTION TO FIND ALL POSSIBLE FLIGHTS/ROOTA
void viewAllPossiblePaths(){

    char source_name[20], dest_name[20];
    printf("Enter source ");
    scanf("%s", source_name);
    printf("Enter destination ");
    scanf("%s", dest_name);


    //CONVERTING ID TO PLACE NAME
    if(source_name[0]>='0' && source_name[0]<='9'){
        int sourceNameIdx = atoi(source_name);
         if(sourceNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(source_name, places[sourceNameIdx]);
    }

    if(dest_name[0]>='0' && dest_name[0]<='9'){
        int destNameIdx = atoi(dest_name);
         if(destNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(dest_name, places[destNameIdx]);
    }

    //COVERT THE STRING INTO LOWERACSE TO AVOID AMBIGUITY BETWEEN SYTEM AND USER
    convertToLowerCase(source_name);
    convertToLowerCase(dest_name);


    int source = findKeyForString(source_name);
    int dest = findKeyForString(dest_name);

    if(source==-1 || dest==-1){
        printf("\nSorry! There is no Flight availability from %s -> %s\n", source_name, dest_name);
        // sleep(2);
        system("cls");
        return;
    }

    int visited[N] = {0};
    dfs_for_finding_all_paths(source, dest, visited, 0, 0);

    if(flagForPath==0){
        printf("\nSorry! There is no Flight availability from %s -> %s\n", source_name, dest_name);
        // sleep(2);
        system("cls");
        return;
    }

    char ch;
    printf("\nPress y to get root from %s to %s which has minimum cost\n", source_name, dest_name);
    printf("\nelse press any other key than y\n");
    fflush(stdin);
    scanf("%c", &ch);
    if(ch=='Y') ch = 'y';

    if(ch=='y') {
        printf("\n");
        dijkstra(source, dest);
    }
    return;
}


//MENU FOR FLIGHTS
void menuForFlights(){
    printf("\n1-View all the flights that are available from source to destination\n2-View the minimum costed root from source to destination\n3-book a flight\n4-view alreday booked flights\n5-cancel booking\n6-Add Experience\n0-Log Out\n");
}

// MENU AFTER LOG IN
void menuAferLogInForUser(){
     int choice;
     system("cls");

struct Experience userExperience;

    do{

        menuForFlights();

        printf("Enter choice\t");
        scanf("%d", &choice);
        system("cls");
        switch(choice){
            case 1: viewAllFlightsFromSourceToDestination();
                    // sleep(1);
            break;

            case 2: system("cls");
                    displayPlaces();
                    shortest_cost_from_source_to_des_w_r_t_cost();
                    // sleep(1);
            break;

            case 3: bookFlight();
            break;

            case 4: display_booked_flights(currUserName);
                    char c;
                    printf("Enter any to go back: ");
                    fflush(stdin);
                    scanf("%c", &c);
                    system("cls");
            break;

            case 5: cancel_booking(currUserName);
            break;
            case 6:
                 userExperience = getFeedback();
            writeFeedbackToFile(userExperience);
            break;

            default:
                if(choice!=0){
                    printf("plz Enter valid choice\n");
                }
        }
    } while(choice!=0);

    system("cls");
    printf("\nYou have loged out successfully!\n");
    // sleep(2);
}



//BELOW CODE REGARDING USER DETAILS
//{

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// KMP algorithm for string matching
int kmpSearch(const char *text, const char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int *lps = (int *)malloc(sizeof(int) * m);
    int j = 0;

    // Build the LPS (Longest Prefix Suffix) array
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Perform pattern matching
    i = 0;
    j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            free(lps);
            return i - j; // Pattern found at index i-j
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
    return -1; // Pattern not found
}

// Function to check if a username already exists in the file using KMP
int isUsernameExists(const char *username) {
    FILE *file = fopen("user_details.txt", "r");
    if (file == NULL) {
        return 0; // File doesn't exist, username doesn't exist
    }

    char buffer[MAX_USERNAME_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        if (kmpSearch(buffer, username) != -1) {
            fclose(file);
            return 1; // Username exists
        }
    }

    fclose(file);
    return 0; // Username doesn't exist
}



//FILE FOR EACH AND EVERY USER
void createUserFile(char *username) {
    // Construct the filename using the provided username
    char filename[50];
    sprintf(filename, "%s.txt", username);

    // Open the file for writing
    FILE *user_file = fopen(filename, "w");

    if (user_file == NULL) {
        perror("Error creating user file");
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(user_file);

}



// Function to register a new user
void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);



    if (isUsernameExists(username)) {
        printf("Username already exists. Please choose a different username.\n");
        // sleep(2);
        system("cls");
        return;
    }

    printf("Enter your password: ");
    getPassword(password, MAX_PASSWORD_LENGTH);

    FILE *file = fopen("user_details.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Registration successful.\n");

    createUserFile(username);
    // sleep(3);
    system("cls");
}

// Function to authenticate a user
void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);


    if (!isUsernameExists(username)) {
        printf("Username does not exist. Please register first.\n");
        return;
    }

    printf("Enter your password: ");
    getPassword(password, MAX_PASSWORD_LENGTH);

    FILE *file = fopen("user_details.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char storedPassword[MAX_PASSWORD_LENGTH];
    char storedUsername[MAX_USERNAME_LENGTH];
    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(username, storedUsername)==0 && strcmp(storedPassword, password) == 0) {
            fclose(file);
            system("cls");
            strcpy(currUserName, username);
            printf("Login successful. Welcome, %s!\n", username);
            // sleep(2);
            menuAferLogInForUser();
            return;
        }
    }

    fclose(file);
    // sleep(2);
    printf("Incorrect password. Please try again.\n");
    // sleep(2);
}

//MENU FOR USER LOG IN
void menuForUser(){
    printf("\nFlight Booking System\n");
    printf("1. Register As User\n");
    printf("2. Login As User\n");
    printf("3. Register As Manager\n");
    printf("4. Login As Manager\n");
    printf("0. Exit\n");
}

//MENU AFTER LOG IN
void menuBeforeLogIn(){
    int choice;

    do {
        menuForUser();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        system("cls");

        switch (choice) {
            case 0: break;
            case 1: // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
                registerUser();
                    break;

            case 2: // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
                loginUser();
                    break;

            case 3: // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
                registerManager();
                    break;

            case 4: // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
                loginManager();
                    break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}




//ASSIGN EVERY PATH TO SOME FLIGHT
void assignPathToEachFlight(){
    for(int i=0; i<noOfPlaces; i++){
        for(int j=0; j<noOfPlaces; j++){
            if(i!=j){
                int visited[N] = {0};
                dfs_for_finding_all_paths(findKeyForString(places[i]), findKeyForString(places[j]), visited, 0, 1);
            }
        }
    }
    //displayFlighsInfo();
}



//SORT TEMP FLIGHTS FROM SOURCE TO DESTINATION BY COST
void sortTempFlightsFromSourceToDestByCost(flights *TempFlightsFromSourceToDest, int noOfFlights){
    // flights temp = (flights)malloc(sizeof(flight));
    flights temp;

    for(int i=0; i<noOfFlights; i++){
        for(int j=0; j<noOfFlights-1; j++){
            if(TempFlightsFromSourceToDest[j].totalCost > TempFlightsFromSourceToDest[j+1].totalCost){
                temp = TempFlightsFromSourceToDest[j];
                TempFlightsFromSourceToDest[j] = TempFlightsFromSourceToDest[j+1];
                TempFlightsFromSourceToDest[j+1] = temp;
            }
        }
    }
}


//FUNCTION WHICH FINDS FOR THE FIRST FLIGHT WHICH HAS SOURCE AND DEST
int findFirstOccuOfReqFlight(int source, int dest){

    for(int i=0; i<noOfFlights; i++){
        if(flight[i].from==source && flight[i].to==dest){
            return i;
        }
    }
    return -1;
}

//FUNCTION WHICH SEARCHES FOR GIVEN SOURCE TO DESTINATION
int searchForFlight(int source, int dest){
    int firstOcc = findFirstOccuOfReqFlight(source, dest);
    // flights tempFlights[N];
    if(firstOcc==-1){
        printf("\n\nSorry! there are no flights available from %s -> %s\n\n", places[source], places[dest]);
        // sleep(3);
        system("cls");
        return 0;
    }

    flights* tempFlightsFromSourceToDest = (flights*)malloc(sizeof(flights)*N);
    int idxForTempFlights = 0;
    system("cls");
    printf("available flights\n\n");
    while(firstOcc < noOfFlights && flight[firstOcc].from == source && flight[firstOcc].to == dest){
        tempFlightsFromSourceToDest[idxForTempFlights++] = flight[firstOcc];
        firstOcc++;
    }


    sortTempFlightsFromSourceToDestByCost(tempFlightsFromSourceToDest, idxForTempFlights);

    for(int i=0; i<idxForTempFlights; i++){
        displaySpecificFlights(tempFlightsFromSourceToDest[i]);
        printf("\n");
    }
    return 1;
}


//FUNCTION TO VIEW ALL PATHS FROM SOURCE TO DESTINATION USING FLIGHTINFO
void viewAllFlightsFromSourceToDestination(){

    displayPlaces();

    char sourceName[20], destName[20];
    printf("Enter source : ");
    scanf("%s", sourceName);
    printf("Enter destination : ", destName);
    scanf("%s", destName);

    //CONVERTING ID TO PLACE NAME
    if(sourceName[0]>='0' && sourceName[0]<='9'){
        int sourceNameIdx = atoi(sourceName);
        if(sourceNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(sourceName, places[sourceNameIdx]);
    }

    if(destName[0]>='0' && destName[0]<='9'){
        int destNameIdx = atoi(destName);
        if(destNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(destName, places[destNameIdx]);
    }

    convertToLowerCase(sourceName);
    convertToLowerCase(destName);

    int source = findKeyForString(sourceName);
    int dest = findKeyForString(destName);

    if(source==-1 || dest==-1){
        printf("\nSorry! There is no Flight availability from %s -> %s\n", sourceName, destName);
        // sleep(2);
        system("cls");
        return;
    }
    searchForFlight(source, dest);
    int i;
    printf("Press any to go back : ");
    scanf("%d", &i);
    fflush(stdin);
    system("cls");

}


//FUNCTION TO BOOK A FLIGHT BY USER
void bookFlight(){

    displayPlaces();
    char sourceName[20], destName[20];
    printf("Enter source ");
    scanf("%s", sourceName);
    printf("Enter destination ");
    scanf("%s", destName);

    //CONVERTING ID TO PLACE NAME
    if(sourceName[0]>='0' && sourceName[0]<='9'){
        int sourceNameIdx = atoi(sourceName);
         if(sourceNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(sourceName, places[sourceNameIdx]);
    }

    if(destName[0]>='0' && destName[0]<='9'){
        int destNameIdx = atoi(destName);
         if(destNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            viewAllFlightsFromSourceToDestination();
        }
        strcpy(destName, places[destNameIdx]);
    }



    convertToLowerCase(sourceName);
    convertToLowerCase(destName);

    int source = findKeyForString(sourceName);
    int dest = findKeyForString(destName);


    if(source==-1 || dest==-1){
        printf("\nSorry! There is no Flight availability from %s -> %s\n", sourceName, destName);
        return;
    }

    id_input:
    printf("\n");
    int isAvailable = searchForFlight(source, dest);
    if(isAvailable==0){
        return;
    }

    int flight_id = -1;

    printf("Enter corresponding flight id to book a flight : \n");
    printf("else if don't want to book press -1 \n");
    printf("Enter: ");
    scanf("%d", &flight_id);

    if(flight_id==-1){
        printf("\nThank you!\n");
        system("cls");
        return;
    }

    if(flight_id>=noOfFlights || flight[flight_id].from!=source || flight[flight_id].to!=dest){
        system("cls");
        printf("You have entered wrong choice plz Enter  valid choice\n");
        // sleep(3);
        goto id_input;
    }


    system("cls");
    printf("\nThe Flight you have choosen is: \n");

    displaySpecificFlights(flight[flight_id]);

        int noOfSeatsToBeBooked;
        printf("Enter no of tickets you want to book : ");
        scanf("%d", &noOfSeatsToBeBooked);

        if(noOfSeatsToBeBooked > flight[flight_id].noOfSeatsAvailable){
            system("cls");
            printf("\nSorry But the only no of available seats are : %d\n", flight[flight_id].noOfSeatsAvailable);
            printf("you can try some other root\n");
            // sleep(4);
            goto id_input;
        } else{

            printf("press y to confirm your booking :\nelse press any except y/Y: \nEnter: ");
            char c;
            fflush(stdin);
            scanf("%c", &c);
            if(c=='y'||c=='Y'){
                flight[flight_id].noOfSeatsAvailable-=noOfSeatsToBeBooked;
                // sleep(1);
                system("cls");
                printf("You have successfully booked %d seats for \n", noOfSeatsToBeBooked);
                displaySpecificFlights(flight[flight_id]);
                printf("Your Total Cost For The Above Flights Is %d \n\n\n", (flight[flight_id].totalCost*noOfSeatsToBeBooked));
                writeBookingDetailsIntoFile(currUserName,flight_id,  noOfSeatsToBeBooked);
                // sleep(2);
            } else{
                printf("You have not booked any seat!\n");
            }
        }

    int waste;
    printf("Enter anything to go back: ");
    scanf("%d", &waste);
    fflush(stdin);
    // sleep(1);
    system("cls");
    printf("Thank you! Enjoy your tour!.\n");
    // sleep(2);
    system("cls");

}


//FUNCTION TO WRITE BOOKING DETAILS IN USER FILE
void writeBookingDetailsIntoFile(const char *username, int flight_id, int no_of_seats_booked) {
    // Construct the filename using the provided username
    char filename[50];
    //CREATING USERNAME.TXT -> FILENAME
    sprintf(filename, "%s.txt", username);

    // Open the user's file for appending
    FILE *user_file = fopen(filename, "a");

    if (user_file == NULL) {
        perror("Error opening user file");
        exit(EXIT_FAILURE);
    }

    // Write the flight details to the file
    fprintf(user_file, "%d %d\n", flight_id, no_of_seats_booked);

    // Close the user's file
    fclose(user_file);
}



//FUNCTION TO CANCEL ALREADY BOOKED FLIGHT
void cancel_booking(char *currUserName) {
    // Construct the filename using the provided username

    int isAny = display_booked_flights(currUserName);

    if(!isAny) return;

    int flightsBooked[1000] = {-1};
    int idxForFlightsBooked = 0;


    int flight_id;
    flag:
    printf("plz Enter flight id for you have to cancel bookings:\nelse if you want to go back then press -1: \n");
    printf("Enter ");
    scanf("%d", &flight_id);

    if(flight_id==-1) return;


    char filename[50];
    sprintf(filename, "%s.txt", currUserName);

    // Open the user's file for reading and writing
    FILE *user_file = fopen(filename, "r+");

    if (user_file == NULL) {
        perror("Error opening user file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_USERNAME_LENGTH];
    long int current_line_position;
    int current_flight_id;
    int current_no_of_seats_booked;
    int flight_id_found = 0;

    // Create a temporary file for writing
    FILE *temp_file = fopen("temp_user_file.txt", "w");

    if (temp_file == NULL) {
        perror("Error creating temporary file");
        fclose(user_file);
        exit(EXIT_FAILURE);
    }

    // Read and update flight details line by line
    while (fgets(line, sizeof(line), user_file)) {
        current_line_position = ftell(user_file);

        // Parse the line to get flight details
        if (sscanf(line, "%d %d", &current_flight_id, &current_no_of_seats_booked) == 2) {
            // Check if the current line corresponds to the given flight ID
            flightsBooked[idxForFlightsBooked++] = current_flight_id;
            if (flight_id == current_flight_id) {
                // Skip the line to effectively remove the booking
                continue;
            }
        }

        // Write the line to the temporary file
        fprintf(temp_file, "%s", line);
    }



    // Close both files
    fclose(user_file);
    fclose(temp_file);

    // Replace the original file with the temporary file
    remove(filename);
    rename("temp_user_file.txt", filename);

    int isBooked = 0;
    for(int i=0; i<idxForFlightsBooked; i++){
        if(flightsBooked[i]==flight_id) isBooked = 1;
    }

    if(!isBooked){
        printf("plz Enter a valid id\n");
        goto flag;
    }

    if(flight_id<noOfFlights){
          flight[flight_id].noOfSeatsAvailable+=current_no_of_seats_booked;
    } else{
        printf("plz Enter valid id\n");
        goto flag;

    }
    system("cls");
    printf("%s, Your booking for \n", currUserName);
    displaySpecificFlights(flight[flight_id]);
    printf("Has been canceled successfully\n");
    // sleep(2);

    char watse;
    printf("Press any key to go back: ");
    fflush(stdin);
    scanf("%c", &watse);
    system("cls");
}



//FUNCTION TO PRINT ALREADY BOOKED FLIGHTS
int display_booked_flights(char *currUserName) {

    int isAny = 0;
    // Construct the filename using the provided username
    char filename[50];
    sprintf(filename, "%s.txt", currUserName);

    // Open the user's file for reading
    FILE *user_file = fopen(filename, "r");

    if (user_file == NULL) {
        perror("Error opening user file");
        exit(EXIT_FAILURE);
    }

    printf("%s, The Flights You Have Booked Are: \n", currUserName);

    int current_flight_id;
    int current_no_of_seats_booked;

    // Read and display flight details line by line
    while (fscanf(user_file, "%d %d", &current_flight_id, &current_no_of_seats_booked) == 2) {
        isAny = 1;
        displaySpecificFlights(flight[current_flight_id]);
        printf("*Number of Seats You Have Booked For The Above Flight: %d\n*The Total Cost For The Above Flight Is %d\n\n\n", current_no_of_seats_booked, flight[current_flight_id].totalCost*current_no_of_seats_booked);
    }

    // Close the user's file
    fclose(user_file);

    if(!isAny){
        printf("You have not booked any flights!\n");
    }

    return isAny;
}





// Function to check if a manager name already exists in the file using KMP
int isManagerExists(const char *username){
    FILE *file = fopen("manager_details.txt", "r");
    if (file == NULL) {
        return 0; // File doesn't exist, username doesn't exist
    }

    char buffer[MAX_USERNAME_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        if (kmpSearch(buffer, username) != -1) {
            fclose(file);
            return 1; // Username exists
        }
    }

    fclose(file);
    return 0; // Username doesn't exist
}


// Function to get a password without displaying it
void getPassword(char *password, int max_length) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch(); // Get a single character without displaying it
        if (ch == 13 || ch == 10) { // Enter key
            password[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) { // Backspace key
            i--;
            printf("\b \b"); // Move the cursor back and erase the character
        } else if (i < max_length - 1) {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    printf("\n");
}



//FOR MANAGER
void registerManager() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your name: ");
    scanf("%s", username);


    if (isManagerExists(username)) {
        printf("name already exists. Please choose a different username.\n");
        // sleep(2);
        system("cls");
        return;
    }

    printf("Enter your password: ");
    getPassword(password, MAX_PASSWORD_LENGTH);
    FILE *file = fopen("manager_details.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    system("cls");
    printf("%s, Registered successfully\n", username);
    // sleep(2);
    system("cls");

}



//LOG IN FOR MANAGER

// Function to authenticate a manager
void loginManager(){
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your name: ");
    scanf("%s", username);


    if (!isManagerExists(username)) {
        printf("name does not exist. Please register first.\n");
        return;
    }


    printf("Enter your password: ");
    getPassword(password, MAX_PASSWORD_LENGTH);
    FILE *file = fopen("manager_details.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char storedPassword[MAX_PASSWORD_LENGTH];
    char storedUsername[MAX_USERNAME_LENGTH];
    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(username, storedUsername)==0 && strcmp(storedPassword, password) == 0) {
            fclose(file);
            system("cls");
            strcpy(currUserName, username);
            printf("Login successful. Welcome, %s!\n", username);
            // sleep(2);
            menuAferLogInForManager();
            return;
        }
    }

    fclose(file);
    // sleep(2);
    printf("Incorrect password. Please try again.\n");
    // sleep(2);
}



//MENU FOR MANAGER AFTER LOG IN
void menuAferLogInForManager(){

    int ch;
    do{
        printf("1-add new flights\n2-View all places where our flights are available\n0-log out\n");
        printf("Enter choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 0: break;

            case 1: // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
                addNewFlightsByTakingInput();
            break;

            case 2: // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
                    displayPlaces();
                    char c;
                    printf("Enter any to go back\n");
                    fflush(stdin);
                    scanf("%c", &c);
            break;

            default: printf("Plz enter a valid choice!\n");
                    // sleep(2);
                    system("cls");
        }
    } while(ch!=0);

    system("cls");
    printf("%s, You have logged out successfully\n", currUserName);
    // sleep(2);
    system("cls");
}

//ADD A PLACE IF ITS NEW AFTER MANAGER ENTERS
void addNewPlaceByTakingInput(char placeName[20]){

    strcpy(places[noOfPlaces], placeName);
    noOfPlaces++;
    sortPlaces();
}




//FUNCTION TO ADD A NEW FLIGHTS
void addNewFlightsByTakingInput(){
     displayPlaces();
    int u, v;
     printf("If a new flight has some new place as source or destination type the place name(be carefull with spelling):\n\n");

    char sourceName[20], destName[20];
    printf("Enter source : ");
    scanf("%s", sourceName);
    printf("Enter destination : ", destName);
    scanf("%s", destName);

    int cost;
    printf("Enter cost: ");
    scanf("%d", &cost);

    //CONVERTING ID TO PLACE NAME
    if(sourceName[0]>='0' && sourceName[0]<='9'){
        int sourceNameIdx = atoi(sourceName);
        if(sourceNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            addNewFlightsByTakingInput();
        }
        strcpy(sourceName, places[sourceNameIdx]);
    }

    if(destName[0]>='0' && destName[0]<='9'){
        int destNameIdx = atoi(destName);
        printf("%d", destNameIdx);
        if(destNameIdx>=noOfPlaces){
            printf("you have entered wrong choice plz try again\n");
            // sleep(2);
            system("cls");
            addNewFlightsByTakingInput();
        }
        strcpy(destName, places[destNameIdx]);
    }

    convertToLowerCase(sourceName);
    convertToLowerCase(destName);

    int source = findKeyForString(sourceName);
    int dest = findKeyForString(destName);

    if(source!=-1 && dest!=-1){
        addEdge(source, dest, cost);
        noOfFlights=0;
        assignPathToEachFlight();
        system("cls");
        printf("ADDED SUCCESSFULLY!!\n");
        // sleep(2);
        system("cls");
        // sleep(2);
        return;
    } else{
            if(source==-1){
                addNewPlaceByTakingInput(sourceName);
            }

            if(dest==-1){
                addNewPlaceByTakingInput(destName);
            }
            displayPlaces();

             u = findKeyForString(sourceName);
             v = findKeyForString(destName);


    }


    noOfFlights=0;
    assignNullInitially();
    formConnectionBetweenPlaces();
    addEdge(u, v, cost);
    assignPathToEachFlight();
    system("cls");
    printf("ADDED SUCCESSFULLY!!\n");
    // sleep(2);
    system("cls");
    // sleep(2);
}


int main(){
    system("cls");
    assignNullInitially();
    addPlaces();
    formConnectionBetweenPlaces();

    // Clearing Screen
           system("cls");
            // Calling heading() function
                heading();
    menuBeforeLogIn();


 return 0;
}
