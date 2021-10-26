//
// Created by Ivan on 10/23/2021.
//

#ifndef WORKFLOW_UTILITYCLASS_H
#define WORKFLOW_UTILITYCLASS_H

class UtilityClass {
public:
    static bool isExist(std::string& filename) {
        if (FILE *file = fopen(filename.c_str(), "r")) {
            fclose(file);
            return true;
        } else {
            return false;
        }
    }
};

#endif //WORKFLOW_UTILITYCLASS_H

