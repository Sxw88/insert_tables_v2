#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    while (1==1) {

    int race = 1; cout << "(0=Angmo Name,1=Chinese Name,2=Tamil Name,3=Malay Name)" << endl << "select race: ";
    cin >> race;

    int local_chance = 2; //1 out of 2 is a foreigner

    //*angmo names (default)
    vector<string> surname = {"McLafferty","Fring","Salvatore","Richardson","Jamison","Wright","McCoy","Mordino","Robertson","Smith","Wesley","Bishop","Chauncey","Kimball","Gomez","White"};
    vector<string> malename = {"Richard","Marcus","Max","Mike","Jonas","Timothy","Ray","Louis","Walter","Rick","Marty","Ben","Elijiah","Noah","Oliver","Martinez","William"};
    vector<string> femname = {"Alice","Mary","Miria","Anna","Ann","Olivia","Ava","Sophia","Charlotte","Isabella","Lisa","Amelia","Mia","Camilla","Ella"};
    //*/

    if(race == 1) {
        local_chance = 3;
        //*chinese names
        surname = {"Lee","Chan","Moy","Ooi","Lim","Chua","Chai","Zheng","Zhang","Teo","Zhou","Zhao","Yeo","Yang","Wu","Wang","Ren"};
        malename = {"Richard","Max","John","Li Zheng","Jian Guo","Yong Qiang","Wu Biao","Xiao Er","Zhen Hua","Mun Yew","Simon",
                                    "Zhe Dong","Dong Liang","Bai Guo","Da Zhu","Ju Ren","Tian Zhe","Bao Qiang","De Hua", "Jie Lun"};
        femname = {"Mary","Janet","Faithe","Coco","Qi","Bing Bing","Hua Xia","Zi Qi","Zhi Ruo","Fei Yu","Bai Ruo","Mi Xin",
                                    "Xin Yi","Qun Ying","Xiang Nin","Ping Hui","Kai Li","Ji Ren","Zheng Fei","Qiu Jin","Bing Rou"};
        //*/
    }
    if (race == 2) {
        local_chance = 4;
        //*indian names
        surname = {"Narayanan","Abhilash","Natarajan","Kapoor","Vinayaka","Sujeethan","Nilavanthan","Jayakumar",
                                    "Illangobhan","Kiriprasath","Rithvikan","Yathurathan","Janarthanan","Dinushan","Neerthihan","Vengatavel","Aradesh"};
        malename = {"Ganatheep","Keathesan","Alen","Ganarathan","Rajeebhan","Vinagan","Aswin","Basuthan","Kavish","Hrisi","Lathush",
                                    "Jonathan","Jarthanan","Yasmiran","Sathivikan","Harishkrishnan","Kulavenan","Vivegan","Ravikumar", "Illan"};
        femname = {"Srisi","Nirvisha","Maruvi","Ananditha","Miruthila","Lishanya","Janaraja","Nidhipa","Priya","Sivika","Indya",
                                    "Keshiya","Devakumari","Shangamirta","Raththika","Mathumathi","Diyamika","Arthy"};
        //*/
    }
    if (race == 3) {
        local_chance = 6;
        //*malay names
        surname = {"Azzaam","Shafeeq","Badruddeen","Abdul Lateef","Sirajuddeen","Hilmi","Zaiid","Tammaam","Lokman",
                                    "Abdul Baasid","Ikram","Fayyaad","Rashaad","Abdul Rauf","Indera","Zaharin"};
        malename = {"Aznan","Syed Saddiq","Adi Putera","Johan","Deris","Kesuma","Ali","Shukur","Taib","Daniel","Hassan","Hussein",
                                    "Azman","Osman","Najib","Naib","Fikri","Suleimi","Rohan","Kamir","Adi"};
        femname = {"Rosmah","Adita","Aisyah","Suria","Shabeeba","Mariam","Faseeha","Fatimah","Suhaila","Hapsa","Linda","Saalima",
                                    "Nazmiiya","Khatijah","Sri Intan","Fat'hiyaa","Rafeeda","Mas Ayu","Wadiyah"};
        //*/
    }

    vector<string> email_suffix = {"@gmail.com","@hotmail.com","@gmail.com","@hotmail.com","@yahoo.com","@gmail.com","@yahoo.com.my","@gmail.com","@hotmail.co.uk","@gmail.com","@hotmail.com","@msn.com"};
    vector<string> phone_prefix = {"1","65","44","49","34","62","63","66","86","7"};
    string alphanumeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    ostringstream stream;
    ofstream outfile;
    outfile.open("output.txt", ios::trunc|ios::out);

    string temp = "empty string";

    int index = 0;
    cout << "Start from index: "; cin >> index;

    int rows = 1;
    cout << endl << "Generate how many number of rows? " ; cin >> rows;

    int tint,igender,local = 0; string nric,name,fname,lname = "";
    srand((int)time(0));
    size_t found;

    for (int i = 0; i < rows; i++){
        ///INDEX ID
        stream.str(string()); //clear stream
        stream << index;
        temp = "INSERT INTO member VALUES (" + stream.str() + ",'";

        stream.str(string()); //clear stream
        index ++;

        local = rand() % local_chance; //0,1,2,3 is local //4 is foreigner
        if (local < local_chance-1) {
            ///generate NRIC
            tint = rand() % 100;
            if (tint < 61){  //generate random year 1961 - 2004
                tint  = rand() % 5;
                stream << 0;
            }
            stream << tint;

            tint = rand() % 12 + 1; //generate random month jan to dec
            if (tint < 10) { stream << 0; }
            stream << tint;

            switch (tint) {  //generate random days based on month
            case 1:
                tint = rand() % 31 + 1;
                break;
            case 2:
                tint = rand() % 28 + 1;
                break;
            case 3:
                tint = rand() % 31 + 1;
                break;
            case 5:
                tint = rand() % 31 + 1;
                break;
            case 7:
                tint = rand() % 31 + 1;
                break;
            case 8:
                tint = rand() % 31 + 1;
                break;
            case 10:
                tint = rand() % 31 + 1;
                break;
            case 12:
                tint = rand() % 31 + 1;
                break;
            default:
                tint = rand() % 30 + 1;
            }
            if (tint < 10) {stream << 0;}
            stream << tint << "-";

            //location code
            tint = rand() % 59 + 1;
            stream << tint << "-";

            //4 random numbers at the end of nric
            tint = rand() % 10;  stream << tint; tint = rand() % 10;  stream << tint;
            tint = rand() % 10;  stream << tint; tint = rand() % 10;  stream << tint;
            stream << "','";

            nric = stream.str();
            stream.str(string()); //clear stream
            temp += nric;
        }
        else{
            ///generate passport
            for (int j = 0; j < (rand() % 2) + 2; j++){ //first half of passport
                temp += alphanumeric[rand() % alphanumeric.length()];
            }
            temp += "-";
            for (int j = 0; j < (rand() % 2) + 6; j++){ //second half of passport
                temp += alphanumeric[rand() % alphanumeric.length()];
            }
            temp += "','";
        }

        ///gender reveal
        igender = rand() % 2; //0 = male, 1 = female

        ///generate names
        if (igender == 0) {  //get first name
            fname = malename[rand() % malename.size()];
        }
        else {
            fname = femname[rand() % femname.size()];
        }

        //get last name
        lname = surname[rand() % surname.size()];

        //format names based on race
        if (race == 0) {  //angmo names
            name = fname + " " + lname;
        }
        if (race == 1) {
            found = fname.find(' ');
            if(found != string::npos){ //if it is a chinese name
                name = lname + " " + fname;
            }
            else{
                name = fname + " " + lname;
            }
        }
        if (race == 2) {    // tamil names
            if (igender == 0) {
                name = fname + " a/l " + lname;
            }
            else {
                name = fname + " a/l " + lname;
            }
        }
        if (race == 3){
            if (igender == 0) {
                found = fname.find(' ');
                if(found != string::npos){ //if name is one-syllable, add Mohd.
                    name = fname + " b. " + lname;
                }
                else{
                    name = "Mohd. " + fname + " b. " + lname;
                }
            }
            else {
                name = fname + " bt. " + lname;
            }
        }


        if (igender == 0) {
            temp += name + "','M','";
        }
        else {
            temp += name + "','F','";
        }

        ///generate emails (based on names)
        if (name.length() > 13) {
            for (int j = 0; j < name.length(); j++){
                if (name[j] != ' ') {
                    temp += tolower(name[j]);
                }
                if (j > 0) {
                    if(name[j-1] == ' '){
                        break;
                    }
                }
            }
            tint = rand() % 10000; stream << tint;
            temp += stream.str() + email_suffix[rand() % email_suffix.size()] + "','+";
        }
        else{
            for (int j = 0; j < name.length(); j++){
                if (name[j] != ' ') {
                    temp += tolower(name[j]);
                }
            }
            tint = rand() % 100; stream << tint;
            temp += stream.str() + email_suffix[rand() % email_suffix.size()] + "','+";
        }

        ///phone number, based on local/foreign
        if(local < local_chance-1){
            temp += "601";
        }
        else {
            temp += phone_prefix[rand() % phone_prefix.size()];
        }
        stream.str(string()); //clear stream
        tint = (rand() % 9) + 1;
        stream << tint << "-";
        for (int j = 0; j < rand() % 2 + 3; j++) {
            tint = (rand() % 9) + 1;
            stream << tint;
        }
        stream << " ";
        for (int j = 0; j < rand() % 2 + 3; j++) {
            tint = (rand() % 9) + 1;
            stream << tint;
        }

        temp += stream.str() + "','approved');";

        outfile << temp << endl;
        cout << temp << endl;
    }
    outfile.close();

    system("PAUSE");

    } //infinite while loop

    return 0;
}
