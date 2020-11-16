#ifndef GRAPHTHEORYWORK_MENUMANAGER_H
#define GRAPHTHEORYWORK_MENUMANAGER_H


class MenuManager {
private:
    int selectedOption;
public:
    MenuManager();
    ~MenuManager();
    int createMenu();
    void createHeader();
    void createOptions();
};


#endif //GRAPHTHEORYWORK_MENUMANAGER_H
