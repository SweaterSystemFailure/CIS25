#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include "containers.h"
#include "containerFunctions.h"
#include "utilities.h"
#include "menuFunctions.h"

using namespace std;
using namespace gradebook;

int main(){
globalStorage storage;

welcome(storage);
mainMenu(storage);

return 0;
}